#include <bits/stdc++.h>
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
        vector<pair<int, int>> lr(n);
        vector<int> a;
        for(int i = 0; i < n; ++i)
            cin >> lr[i].first >> lr[i].second, a.pb(lr[i].first), a.pb(lr[i].second);
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end())-a.begin());
        vector<int> lr2(n);
        for(int i = 0; i < n; ++i){
            lr[i].first = lower_bound(a.begin(), a.end(), lr[i].first)-a.begin();
            lr[i].second = lower_bound(a.begin(), a.end(), lr[i].second)-a.begin();
            lr2[i] = lr[i].first*2*n+lr[i].second;
        }
        sort(lr2.begin(), lr2.end());
        sort(lr.begin(), lr.end());
        vector<vector<int>> dp(a.size(), vector<int>(a.size(), 0));
        for(int i = 0; i < a.size(); ++i)
            if(binary_search(lr2.begin(), lr2.end(), i*2*n+i))
                dp[i][i] = 1;
        for(int len = 2; len <= a.size(); ++len){
            for(int l = 0; l+len-1 < a.size(); ++l){
                int r = l+len-1;
                int add = 0;
                if(binary_search(lr2.begin(), lr2.end(), l*2*n+r))
                    add = 1;
                dp[l][r] = max(dp[l+1][r], dp[l][r-1])+add;
                for(int m = lower_bound(lr2.begin(), lr2.end(), l*2*n)-lr2.begin(); m < n; ++m){
                    if(lr[m].first > l || lr[m].second >= r)
                        break;
                    dp[l][r] = max(dp[l][r], dp[l][lr[m].second]+dp[lr[m].second+1][r]+add);
                }
            }
        }
        cout << dp[0][a.size()-1] << '\n';
    }
    return 0;
}