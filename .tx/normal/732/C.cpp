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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

lint a[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> a[0] >> a[1] >> a[2];

    lint ans = 6e18;

    for (int i = 0; i < 3; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (a[i] != *max_element(a, a + 3)) {
            continue;
        }
        lint mn = a[i] - 1;
        lint ca = 0;
        ca += max(0LL, mn - a[(i + 1) % 3]);
        ca += max(0LL, mn - a[(i + 2) % 3]);
        ans = min(ans, ca);
    }

    cout << ans;


    return 0;
}