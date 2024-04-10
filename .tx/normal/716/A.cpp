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

    scid(n, c);
    scid(last);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        scid(t);
        if (t - last > c) {
            ans = 1;
        } else {
            ans++;
        }
        last = t;
    }
    cout << ans;

    return 0;
}