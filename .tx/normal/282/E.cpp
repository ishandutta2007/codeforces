#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct Node {
    Node* ch[2];
    Node() {
        ch[0] = ch[1] = 0;
    }
};

Node* root = new Node();

void add(Node* cur, lint x) {
    for (int i = 40; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (cur->ch[b] == 0) {
            cur->ch[b] = new Node();
        }
        cur = cur->ch[b];
    }
}

lint get(Node* cur, lint x) {
    lint res = 0;
    for (int i = 40; cur && i >= 0; i--) {
        int bx = (x >> i) & 1;
        if (cur->ch[1 - bx]) {
            res |= (1LL << i);
            cur = cur->ch[1 - bx];
        } else {
            cur = cur->ch[bx];
        }
    }
    return res;
}

lint a[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    lint xf = 0;
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        xf ^= a[i];
    }
    
    lint xe = 0;
    add(root, 0);
    lint ans = xf;
    for (int i = n - 1; i >= 0; i--) {
        xe ^= a[i];
        add(root, xe);
        xf ^= a[i];
        ans = max(ans, get(root, xf));
    }
    
    cout << ans;
    

    return 0;
}