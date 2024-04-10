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

int c[222222];
int v[222222];
int g[222222];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, k, s, t);

    for (int i = 0; i < n; i++) {
        sci(c[i], v[i]);
    }

    for (int i = 1; i <= k; i++) {
        sci(g[i]);
    }
    sort(g + 1, g + 1 + k);
    g[0] = 0;
    g[k + 1] = s;
    k++;

    int l = 0, r = 1e9 + 1;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        lint c = 0;
        for (int i = 1; i <= k; i++) {
            int d = g[i] - g[i - 1];
            if (d > m) {
                c = 1e18;
                break;
            }
            lint q = d * 2;
            int more = min(d, m - d);
            q -= more;
            c += q;
        }

        if (c <= t) {
            r = m;
        } else {
            l = m;
        }
    }

    lint ans = 1e18;
    for (int i = 0; i < n; i++) {
        if (v[i] >= r) {
            ans = min(ans, 1LL * c[i]);
        }
    }

    cout << (ans == 1e18 ? -1 : ans);

    return 0;
}