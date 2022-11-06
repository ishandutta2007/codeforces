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

int d[88][88][88][2];

vector<pair<int, int> > g[88];

const int inf = 1e9;

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n, k);
    if (k == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < 88; i++) {
        for (int j = 0; j < 88; ++j) {
            for (int l = 0; l < 88; ++l) {
                for (int m = 0; m < 2; ++m) {
                    d[i][j][l][m] = inf;
                }
            }
        }
    }

    scid(m);
    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        g[x].push_back({y, z});
    }

    for (int i = 1; i <= n; i++) {
        d[1][i][n + 1][0] = 0;
        d[1][0][i][1] = 0;
    }

    for (int i = 1; i < k; i++) {
        for (int l = 0; l <= n + 1; l++) {
            for (int r = l; r <= n + 1; r++) {
                if (d[i][l][r][0] != inf) {
                    for (auto e : g[l]) {
                        if (e.first > l && e.first < r) {
                            d[i + 1][e.first][r][0] = min(d[i + 1][e.first][r][0], d[i][l][r][0] + e.second);
                            d[i + 1][l][e.first][1] = min(d[i + 1][l][e.first][1], d[i][l][r][0] + e.second);
                        }
                    }
                }
                if (d[i][l][r][1] != inf) {
                    for (auto e : g[r]) {
                        if (e.first > l && e.first < r) {
                            d[i + 1][e.first][r][0] = min(d[i + 1][e.first][r][0], d[i][l][r][1] + e.second);
                            d[i + 1][l][e.first][1] = min(d[i + 1][l][e.first][1], d[i][l][r][1] + e.second);
                        }
                    }
                }
            }
        }
    }

    int ans = inf;
    for (int l = 0; l <= n + 1; l++) {
        for (int r = l; r <= n + 1; r++) {
            ans = min(ans, d[k][l][r][0]);
            ans = min(ans, d[k][l][r][1]);
        }
    }

    cout << (ans == inf ? -1 : ans);

    return 0;
}