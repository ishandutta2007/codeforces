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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int x[33];
int y[33];

int dp[1 << 24];
int p[1 << 24];

int dist(int x1, int y1, int x2 = 0, int y2 = 0) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(x0, y0);
    scid(n);
    for (int i = 0; i < n; i++) {
        sci(x[i], y[i]);
        x[i] -= x0;
        y[i] -= y0;
    }

    memset(p, -1, sizeof(p));

    for (int ms = 1; ms < (1 << n); ms++) {
        int fs = -1;
        for (int i = 0; i < n; i++) {
            if (!((ms >> i) & 1)) {
                continue;
            }
            if (fs == -1) {
                fs = i;
                dp[ms] = dp[ms ^ (1 << i)] + 2 * dist(x[fs], y[fs]);
                p[ms] = ms ^ (1 << i);
                continue;
            }
            int ns = ms ^ (1 << i) ^ (1 << fs);
            int nv = dp[ns] + dist(x[i], y[i]) + dist(x[fs], y[fs]) + dist(x[i], y[i], x[fs], y[fs]);
            if (dp[ms] > nv) {
                dp[ms] = nv;
                p[ms] = ns;
            }
        }
    }

    int ams = (1 << n) - 1;
    int opt = dp[ams];

    cout << opt << "\n";
    cout << 0;

    vector<bool> was(n);
    while (p[ams] != -1) {
        auto w = p[ams];
        for (int i = 0; i < n; i++) {
            if (((w ^ ams) >> i) & 1) {
                cout << " " << i + 1;
                was[i] = true;
            }
        }
        cout << " 0";
        ams = w;
    }

    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            cout << " " << i + 1 << " 0";
        }
    }

    return 0;
}