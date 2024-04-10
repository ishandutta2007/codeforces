#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")

#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;

    int tests = 1;
    // cin >> tests;

    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}

// -----------------------------------------------------------------

const int MAXN = 1010;

int n, m, q;
string b[MAXN];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool onBoard(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dst[MAXN][MAXN];

void bfs() {
    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dst[i][j] == 0) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i]; 

            if (onBoard(xx, yy) && dst[xx][yy] == -1) {
                dst[xx][yy] = dst[x][y] + 1;
                q.push({xx, yy});
            } 
        }
    }
}

void solve() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }   

    memset(dst, -1, sizeof(dst));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            for (int i = 0; i < 4; ++i) {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if (onBoard(xx, yy) && b[x][y] == b[xx][yy]) {
                    dst[x][y] = 0;
                }
            }
        }
    }

    bfs();

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << dst[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < q; ++i) {
        int x, y;
        ll t;
        cin >> x >> y >> t;
        --x; --y;

        if (dst[x][y] >= t || dst[x][y] == -1) {
            cout << b[x][y] << "\n";
        } else {
            cout << (((t - dst[x][y]) & 1) ? char('0' + '1' - b[x][y]) : b[x][y]) << "\n";
        }
    }
}