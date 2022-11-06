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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    lint a[3];
    sci(a[0], a[1], a[2]);
    a[1] = min(a[1], 2 * a[0]);
    a[2] = min(a[2], min(3 * a[0], a[0] + a[1]));

    lint p[4];
    p[1] = min(a[0], min(a[1] + a[2], 3 * a[2]));
    p[2] = min(2 * a[0], min(a[1], 2 * a[2]));
    p[3] = min(3 * a[0], a[2]);

    lint ans = 0;
    if (n % 4 != 0) {
        ans += p[4 - n % 4];
    }
    cout << ans;

    return 0;
}