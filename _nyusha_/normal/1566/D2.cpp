#include<bits/stdc++.h>

using namespace std;

int a[305][305];
int used[305][305];
map < int, vector < pair < int, int > > > goes;

int get(int i, int j) {
    int pos = 1, ans = 0;
    while (pos < j) {
        ans += used[i][pos++];
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector < int > go;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                used[i][j] = 0;
                cin >> a[i][j];
                go.push_back(a[i][j]);
            }
        }
        goes.clear();
        sort(go.begin(), go.end());
        int len = 1;
        go.push_back(-1);
        for (int i = 1; i <= n * m; ++i) {
            if (go[i] == go[i - 1]) len++;
            else {
                int L = i - len, R = i - 1;
                int start_r = L / m + 1, start_c = L % m + 1;
                int stop_r = R / m + 1, stop_c = R % m + 1;
                while (start_c <= m) {
                    goes[go[i - 1]].push_back({start_r, start_c});
                    if (start_r == stop_r && start_c == stop_c) break;
                    start_c++;
                }
                vector < pair < int, int > > tmp = goes[go[i - 1]];
                reverse(tmp.begin(), tmp.end());
                goes[go[i - 1]] = tmp;
                start_r++;
                while (start_r < stop_r) {
                    for (int j = m; j >= 1; --j) goes[go[i - 1]].push_back({start_r, j});
                    start_r++;
                }
                if (start_r == stop_r) {
                    while (stop_c >= 1) {
                        goes[go[i - 1]].push_back({stop_r, stop_c});
                        stop_c--;
                    }
                }
                tmp = goes[go[i - 1]];
                reverse(tmp.begin(), tmp.end());
                goes[go[i - 1]] = tmp;
                len = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ans += get(goes[a[i][j]].back().first, goes[a[i][j]].back().second);
            used[goes[a[i][j]].back().first][goes[a[i][j]].back().second] = 1;
            goes[a[i][j]].pop_back();
        }
        }
        cout << ans << '\n';
    }
    return 0;
}