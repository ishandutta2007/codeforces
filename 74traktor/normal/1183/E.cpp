#include <bits/stdc++.h>

using namespace std;

#define int long long
int dp[105][105];
int maxn = 1e16;
int used[27];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k <= 1){
        cout << 0;
        return 0;
    }
    k--;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (j == 1){
                dp[i][j] = 1;
            }
            else{
                set < char > isi;
                for (int last = i - 1; last >= 1; --last){
                    if (isi.find(s[last - 1]) != isi.end()) continue;
                    isi.insert(s[last - 1]);
                    dp[i][j] = min(maxn, dp[i][j] + dp[last][j - 1]);
                }
            }
        }
    }
    int ans = 0;
    for (int len = n - 1; len >= 1; --len){
        for (int last = 0; last < 26; ++last){
            int mx = 0;
            for (int i = len; i <= n; ++i){
                if (s[i - 1] == char('a' + last)){
                    mx = max(mx, dp[i][len]);
                }
            }
            ans += min(k, mx) * (n - len);
            k -= min(k, mx);
        }
    }
    if (k == 1){
        ans += n;
        k--;
    }
    if (k == 0) cout << ans << '\n';
    else cout << -1;
    return 0;
}