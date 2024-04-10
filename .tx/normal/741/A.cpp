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

int a[111];
int cnt[111];
bool used[111];

lint gcd(lint a, lint b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
        cnt[--a[i]]++;
        if (cnt[a[i]] > 1) {
            cout << -1;
            return 0;
        }
    }
    
    lint ans = 1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        int len = 0;
        int c = i;
        while (!used[c]) {
            len++;
            used[c] = true;
            c = a[c];
        }
        if (len % 2 == 0) {
            len /= 2;
        }
        ans = ans * len / gcd(ans, len);
    }
    
    cout << ans;
    

    return 0;
}