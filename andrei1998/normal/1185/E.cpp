#include <bits/stdc++.h>

using namespace std;

const int NMAX = 2000 + 5;

int N, M;
string init_mat[NMAX];
string mat[NMAX];

vector <vector <int> > ans;

bool at_least;
bool go_do(const char ch) {
    int min_line = N + 10;
    int min_col = M + 10;
    int max_line = -1;
    int max_col = -1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (init_mat[i][j] == ch) {
                min_line = min(min_line, i);
                max_line = max(max_line, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }
    if (max_line == -1) {
        if (!at_least) {
            return true;
        } else {
            bool legit = false;
            int x, y;
            for (int i = 1; i <= N && !legit; ++i) {
                for (int j = 1; j <= M; ++j) {
                    if (mat[i][j] == '?') {
                        legit = true;
                        x = i, y = j;
                        break;
                    }
                }
            }
            if (!legit) {
                return false;
            } else {
                ans.push_back({x, y, x, y});
                return true;
            }
        }
    }
    if (max_line - min_line > 0 && max_col - min_col > 0) {
        return false;
    }
    for (int i = min_line; i <= max_line; ++i) {
        for (int j = min_col; j <= max_col; ++j) {
            if (mat[i][j] == '.') {
                return false;
            }
            if (mat[i][j] != '?' && mat[i][j] != ch) {
                return false;
            }
            mat[i][j] = '?';
        }
    }
    ans.push_back({min_line, min_col, max_line, max_col});
    at_least = true;
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--) {
        ans.clear();
        at_least = false;
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            cin >> mat[i];
            mat[i] = " " + mat[i];
            init_mat[i] = mat[i];
        }
        bool bad = false;
        for (char ch = 'z'; ch >= 'a'; --ch) {
            if (!go_do(ch)) {
                bad = true;
                break;
            }
        }
        if (bad) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (int i = ans.size() - 1; i >= 0; --i) {
                cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << '\n';
            }
        }
    }
    return 0;
}