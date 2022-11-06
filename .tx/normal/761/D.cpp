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

int a[111111];
int c[111111];
int p[111111];
int b[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, l, r);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        --c[i];
        p[c[i]] = i;
    }
    
    int mx = 1e9;
    mx += 31;
    for (int i = n - 1; i >= 0; i--) {
        int x = min(r, mx + a[p[i]] - 1);
        if (x < l) {
            cout << -1;
            return 0;
        }
        b[p[i]] = x;
        mx = x - a[p[i]];
    }
    
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}