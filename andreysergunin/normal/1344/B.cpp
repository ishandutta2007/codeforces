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
    freopen("input.txt", "r", stdin);
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

string s[MAXN];
bool used[MAXN][MAXN];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n, m;

bool onBoard(int x, int y) {
    return 0 <= x && x < n  && 0 <= y && y < m;
}

void dfs(int x, int y) {
    used[x][y] = 1;

    for (int d = 0; d < 4; ++d) {
        int xx = x + dx[d];
        int yy = y + dy[d];

        if (onBoard(xx, yy) && s[xx][yy] == '#' && !used[xx][yy]) {
            dfs(xx, yy);
        }
    }
}


void solve() {  
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    bool empty_col = false, empty_row = false;

    for (int i = 0; i < n; ++i) {
        bool empty = true;
        for (int j = 0; j < m - 1; ++j) {
            if (s[i][j] == '.' && s[i][j + 1] == '#' && !empty) {
                cout << -1 << "\n";
                return;
            } 
            empty &= s[i][j] == '.';
        }
        empty &= s[i][m - 1] == '.';
        empty_row |= empty;
    }

    for (int j = 0; j < m; ++j) {
        bool empty = true;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i][j] == '.' && s[i + 1][j] == '#' && !empty) {
                cout << -1 << "\n";
                return;
            } 
            empty &= s[i][j] == '.';
        }
        empty &= s[n - 1][j] == '.';
        empty_col |= empty;
    }


    if (empty_col ^ empty_row) {
        cout << -1 << "\n";
        return;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && s[i][j] == '#') {
                dfs(i, j);
                ++res;
            }
        }
    }
    cout << res << endl;

}