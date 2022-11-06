#include <bits/stdc++.h>
using namespace std;

typedef long long lint;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scidl(l1, r1, l2, r2, k);
    if (r1 < l2 || r2 < l1) {
        cout << 0;
        return 0;
    }

    lint l = max(l1, l2);
    lint r = min(r1, r2);
    lint ans = r - l + 1;
    if (l <= k && k <= r) {
        ans--;
    }
    cout << ans;

    return 0;
}