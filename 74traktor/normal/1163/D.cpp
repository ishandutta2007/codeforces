#include <bits/stdc++.h>

using namespace std;

int dp[1005][55][55];
int inf = -1e9;
int pref[2][55][26];

void build(string s, int t){
    int n = s.size();
    bool flag;
    for (int i = 0; i <= n; ++i){
        for (int j = 0; j < 26; ++j){
            string k = "";
            for (int p = 0; p < i; ++p) k += s[p];
            k += char('a' + j);
            for (int ok = 0; ok <= min(n, (int)k.size()); ++ok){
                flag = true;
                for (int pos = 0; pos < ok; ++pos){
                    if (s[pos] != k[(int)k.size() - ok + pos]){
                        flag = false;
                        //if (t == 0 && i == n && j == 2) cout << pos << " " << k << endl;
                        //break;
                    }
                }
                if (flag) pref[t][i][j] = ok;
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c, s, t;
    int n, k, m;
    cin >> c >> s >> t;
    n = c.size(), k = s.size(), m = t.size();
    build(s, 0);
    build(t, 1);
    for (int i = 0; i <= 1001; ++i) for (int j = 0; j <= 51; ++j) for (int z = 0; z <= 51; ++z) dp[i][j][z] = inf;
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j <= k; ++j){
            for (int z = 0; z <= m; ++z){
                for (int p = 0; p < 26; ++p){
                    if (c[i] == char('a' + p) || c[i] == '*'){
                        int len1 = pref[0][j][p], len2 = pref[1][z][p];
                        int ans = dp[i][j][z];
                        if (len1 == k) ans++;
                        if (len2 == m) ans--;
                        dp[i + 1][len1][len2] = max(dp[i + 1][len1][len2], ans);
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int j = 0; j <= k; ++j){
        for (int z = 0; z <= m; ++z) ans = max(ans, dp[n][j][z]);
    }
    cout << ans << '\n';
    return 0;
}