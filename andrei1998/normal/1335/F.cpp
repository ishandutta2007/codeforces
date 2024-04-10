#include <bits/stdc++.h>

using namespace std;

void test() {
    int n, m;
    cin >> n >> m;
    vector<string> bits(n), mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> bits[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
    vector<vector<pair<int, int>>> nxt(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'U') {
                nxt[i][j] = make_pair(i - 1, j);
            } else if (mat[i][j] == 'D') {
                nxt[i][j] = make_pair(i + 1, j);
            } else if (mat[i][j] == 'L') {
                nxt[i][j] = make_pair(i, j - 1);
            } else if (mat[i][j] == 'R'){
                nxt[i][j] = make_pair(i, j + 1);
            } else {
                assert(false);
            }
        }
    }

    vector<vector<pair<int, int>>> cp_nxt(nxt);
    for (int k = 0; k < 25; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cp_nxt[i][j] = nxt[nxt[i][j].first][nxt[i][j].second];
            }
        }
        swap(nxt, cp_nxt);
    }

    vector<vector<bool>> have_normal(n, vector<bool>(m, false)), have_special(n, vector<bool>(m, false));
    int cnt_normal = 0, cnt_special = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            const int l = nxt[i][j].first, c = nxt[i][j].second;
            if (!have_normal[l][c]) {
                have_normal[l][c] = true;
                ++cnt_normal;
            }
            if (bits[i][j] == '0') {
                if (!have_special[l][c]) {
                    have_special[l][c] = true;
                    ++cnt_special;
                }
            }
        }
    }
    cout << cnt_normal << ' ' << cnt_special << '\n';
}

int main() {
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 0;
    cin >> t;
    while(t--) {
        test();
    }
    return 0;
}