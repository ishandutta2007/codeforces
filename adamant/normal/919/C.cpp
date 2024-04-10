#include <bits/stdc++.h>

using namespace std;

string s[2001];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int p[m + 1];
        fill(p, p + m + 1, 0);
        for(int j = 0; j < m; j++) {
            p[j + 1] = (s[i][j] == '*') + p[j];
            if(j >= k - 1) {
                ans += (p[j + 1] - p[j - k + 1]) == 0;
            }
        }
    }
    for(int j = 0; j < m; j++) {
        
        int p[n + 1];
        fill(p, p + n + 1, 0);
        for(int i = 0; i < n; i++) {
            p[i + 1] = (s[i][j] == '*') + p[i];
            if(i >= k - 1) {
                ans += (p[i + 1] - p[i - k + 1]) == 0;
            }
        }
    }
    cout << ans / (1 + (k == 1)) << endl;
    return 0;
}