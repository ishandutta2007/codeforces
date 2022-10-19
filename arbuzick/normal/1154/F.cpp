#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    a.resize(k);
    vector<int> b(k+1);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        if(x <= k)
            b[x] = max(b[x], y);
    }
    vector<int> pr(k+1);
    for(int i = 0; i < k; ++i)
        pr[i+1] = pr[i]+a[i];
    vector<int> dp(k+1, 1000000000);
    dp[0] = 0;
    for(int i = 0; i <= k; ++i){
        if(i > 0)
            dp[i] = min(dp[i], dp[i-1]+a[i-1]);
        for(int j = 1; i+j <= k; ++j){
            if(b[j] == 0)
                continue;
            dp[i+j] = min(dp[i+j], dp[i]+pr[i+j]-pr[i+b[j]]);
        }
    }
    cout << dp[k];
    return 0;
}