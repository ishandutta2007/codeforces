#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> cnt(2, vector<int>(n+1));
        for(int i = 0; i < n; ++i){
            cnt[0][i+1] = cnt[0][i], cnt[1][i+1] = cnt[1][i];
            cnt[s[i]-'0'][i+1]++;
        }
        int ans = n;
        for(int i = 0; i <= n; ++i)
            ans = min(ans, min(cnt[1][i]+cnt[0][n]-cnt[0][i], cnt[0][i]+cnt[1][n]-cnt[1][i]));
        cout << ans << '\n';
    }
}