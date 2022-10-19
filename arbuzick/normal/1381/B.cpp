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
        int n;
        cin >> n;
        vector<int> p(n*2);
        for(int i = 0; i < n*2; ++i)
            cin >> p[i];
        vector<int> w;
        int k = 0, m = p[0];
        for(int i = 0; i < n*2; ++i){
            k++;
            m = max(m, p[i]);
            if(i+1 == n*2 || p[i+1] > m){
                w.pb(k);
                k = 0;
            }
        }
        vector<bool> dp(n+1);
        dp[0] = 1;
        for(int i = 0; i < w.size(); ++i)
            for(int j = n; j >= w[i]; --j)
                dp[j] = dp[j]||dp[j-w[i]];
        if(dp[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
	return 0;
}