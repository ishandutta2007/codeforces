#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005][1005], b[1005][1005];
vector<vector<pair<int, int>>> pre2(1005, vector<pair<int, int>>(1005)); 
vector<vector<pair<int, int>>> pre5(1005, vector<pair<int, int>>(1005)); 

int solve(int u, vector<vector<pair<int, int>>> &pre) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int foo = a[i][j];
            if (foo == 0) {
                b[i][j] = 2000;
                continue;
            }
            b[i][j] = 0;
            while (foo % u == 0) {
                foo /= u;
                b[i][j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (i == 1) {
                b[i][j] = b[i][j - 1] + b[i][j];
                pre[i][j] = make_pair(i, j - 1);
                continue;
            }
            if (j == 1) {
                b[i][j] += b[i - 1][j];
                pre[i][j] = make_pair(i - 1, j);
                continue;
            }
            if (b[i][j - 1] < b[i - 1][j]) {
                b[i][j] += b[i][j - 1];
                pre[i][j] = make_pair(i, j - 1);
            } else {
                b[i][j] += b[i - 1][j];
                pre[i][j] = make_pair(i - 1, j);
            }
        }
    }
    return b[n][n];
}

void trace(vector<vector<pair<int, int>>> &pre) {
    string res;
    auto cur = make_pair(n, n);
    while (cur.first != 1 || cur.second != 1) {
        auto nxt = pre[cur.first][cur.second];
        if (nxt.first == cur.first) res.push_back('R');
        else res.push_back('D');
        cur = nxt;
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    pair<int, int> pos0 = make_pair(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) pos0 = make_pair(i, j);
        }
    }

    int res2 = solve(2, pre2);
    int res5 = solve(5, pre5);

    if (pos0.first != 0 && min(res2, res5) > 1) {
        cout << 1 << '\n';
        for (int i = 1; i < pos0.first; i++) {
            cout << 'D';
        }
        for (int i = 1; i < pos0.second; i++) {
            cout << 'R';
        }
        for (int i = pos0.first; i < n; i++) {
            cout << 'D';
        }
        for (int i = pos0.second; i < n; i++) {
            cout << 'R';
        } 
        cout << '\n';
        return 0;
    }

    if (res2 < res5) {
        cout << res2 << '\n';
        trace(pre2);
    } else {
        cout << res5 << '\n';
        trace(pre5);
    }
    
    return 0;
}