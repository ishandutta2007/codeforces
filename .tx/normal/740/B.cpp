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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    lint ans = 0;
    while (m-- > 0) {
        scid(l, r);
        --l;
        --r;
        lint s = 0;
        for (int i = l; i <= r; i++) {
            s += a[i];
        }
        ans += max(s, 0LL);
    }
    cout << ans;

    return 0;
}