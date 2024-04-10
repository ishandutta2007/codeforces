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

lint a[777];
lint d[777][777];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < n; i++) {
        sci(a[n - 1 - i]);
    }

    d[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        d[i][0] = min(a[i - 1], d[i - 1][0] + a[i - 1]);
        for (int j = 1; j <= i; j++) {
            d[i][j] = max(min(a[i - 1], d[i - 1][j] + a[i - 1]), d[i - 1][j - 1]);
        }
    }

    for (int i = 0; i < m; i++) {
        scidl(x);
        int l = -1, r = n;
        while (l + 1 < r) {
            int md = (l + r) >> 1;
            if (d[n][md] + x >= 0) {
                r = md;
            } else {
                l = md;
            }
        }
        cout << r << "\n";
    }

    return 0;
}