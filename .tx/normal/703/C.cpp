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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, w, v, u);

    pair<double, double> rt = {-1e30, -1e30};
    pair<double, double> lt = {1e30, 1e30};

    for (int i = 0; i < n; i++) {
        scidd(x, y);
        x -= 1.0 * y * v / u;
        if (x < lt.first) {
            lt = {x, y};
        }
        if (x > rt.first) {
            rt = {x, y};
        }
    }

    cout.precision(11);
    cout << fixed;

    if (lt.first >= 0 || rt.first <= 0) {
        cout << 1.0 * w / u;
    } else {
        cout << rt.first / v + 1.0 * w / u;
    }

    return 0;
}