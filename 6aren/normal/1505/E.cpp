#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    pair<int, int> cur = {0, 0};
    if (s[cur.first][cur.second] == '*') ans = 1;
    while (cur != make_pair(n - 1, m - 1)) {
        // cout << cur.first << ' ' << cur.second << endl;
        pair<int, int> nxt = {-1, -1};
        int mn = 1e9;
        for (int i = cur.first; i < n; i++) { 
            for (int j = cur.second; j < m; j++) {
                if (cur == make_pair(i, j)) continue;
                if (s[i][j] == '*' && i - cur.first + j - cur.second < mn) {
                    nxt = make_pair(i, j);
                    mn = i - cur.first + j - cur.second;
                }
            }
        }
        if (nxt != make_pair(-1, -1)) {
            cur = nxt;
            ans++;
        } else {
            cur = make_pair(n - 1, m - 1);
        }
    }
    
    cout << ans << endl;

    return 0;
}