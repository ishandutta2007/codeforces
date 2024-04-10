#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

string s[105];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);

    int ntest;
    cin >> ntest;

    while (ntest--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (s[i][j] == '1') {
                    vector<int> tmp = {i, j, i + 1, j, i + 1, j + 1};
                    ans.push_back(tmp);
                    for (int k = 0; k < 6; k += 2) {
                        int u = tmp[k];
                        int v = tmp[k + 1];
                        s[u][v] = (s[u][v] == '0' ? '1' : '0');
                    }
                }
            }
            if (s[i][m - 1] == '1') {
                vector<int> tmp = {i, m - 1, i + 1, m - 2, i + 1, m - 1};
                ans.push_back(tmp);
                for (int k = 0; k < 6; k += 2) {
                    int u = tmp[k];
                    int v = tmp[k + 1];
                    s[u][v] = (s[u][v] == '0' ? '1' : '0');
                }
            }
        }
        for (int i = 0; i < m - 1; i++) {
            vector<int> tmp;
            if (s[n - 2][i] == '0' && s[n - 1][i] == '0') continue;
            if (s[n - 2][i] == '1' && s[n - 1][i] == '0') {
                tmp = {n - 2, i, n - 2, i + 1, n - 1, i + 1};
            } else if (s[n - 2][i] == '0' && s[n - 1][i] == '1') {
                tmp = {n - 1, i, n - 2, i + 1, n - 1, i + 1};
            } else if (s[n - 2][i] == '1' && s[n - 1][i] == '1') {
                tmp = {n - 2, i, n - 1, i, n - 2, i + 1};
            }
            ans.push_back(tmp);
            for (int k = 0; k < 6; k += 2) {
                int u = tmp[k];
                int v = tmp[k + 1];
                s[u][v] = (s[u][v] == '0' ? '1' : '0');
            }
        }
        // for (int i = 0; i < n; i++) cout << s[i] << '\n';
        if (s[n - 2][m - 1] == '1' && s[n - 1][m - 1] == '0') {
            vector<int> tmp = {n - 2, m - 1, n - 2, m - 2, n - 1, m - 2};
            ans.push_back(tmp);
            tmp = {n - 1, m - 1, n - 2, m - 1, n - 2, m - 2};
            ans.push_back(tmp);
            tmp = {n - 1, m - 2, n - 1, m - 1, n - 2, m - 1};
            ans.push_back(tmp);
        } else if (s[n - 2][m - 1] == '0' && s[n - 1][m - 1] == '1') {
            vector<int> tmp = {n - 1, m - 1, n - 2, m - 2, n - 1, m - 2};
            ans.push_back(tmp);
            tmp = {n - 1, m - 1, n - 2, m - 1, n - 2, m - 2};
            ans.push_back(tmp);
            tmp = {n - 1, m - 2, n - 1, m - 1, n - 2, m - 1};
            ans.push_back(tmp);
        } else if (s[n - 2][m - 1] == '1' && s[n - 1][m - 1] == '1')  {
            vector<int> tmp = {n - 2, m - 1, n - 2, m - 2, n - 1, m - 2};
            ans.push_back(tmp);
            tmp = {n - 2, m - 2, n - 1, m - 2, n - 1, m - 1};
            ans.push_back(tmp);
        }
        cout << ans.size() << '\n';
        for (auto e : ans) {
            for (int ee : e) cout << ee + 1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}