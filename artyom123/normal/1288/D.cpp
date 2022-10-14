#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int>(m));
    for (auto &c : a) {
        for (auto &l : c) {
            cin >> l;
        }
    }
    vector <vector<int>> pr((1 << m) + 1, vector<int>(n));
    vector <int> l((1 << m) + 1);
    for (int mask = 0; mask <= (1 << m); mask++) {
        for (int i = 0; i < n; i++) {
            int now = INF;
            for (int j = 0; j < m; j++) {
                if (mask & (1 << j)) {
                    now = min(now, a[i][j]);
                }
            }
            pr[mask][i] = now;
            if (pr[mask][i] > pr[mask][l[mask]]) {
                l[mask] = i;
            }
        }
    }
    int best = -1;
    int ansi = -1, ansj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ans = a[i][j];
            if (ans <= best) {
                continue;
            }
            int mask = 0;
            for (int j1 = 0; j1 < m; j1++) {
                if (a[i][j1] < ans) {
                    mask |= (1 << j1);
                }
            }
            if (pr[mask][l[mask]] < ans) {
                continue;
            }
            best = ans;
            ansi = i;
            ansj = l[mask];
        }
    }
    cout << ansi + 1 << " " << ansj + 1;
    return 0;
}