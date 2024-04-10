#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
vector<int> pr;
int n, m;
bool check(int mask){
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= min(i, m); ++j)
            for(int i2 = j-1; i2 < i; ++i2)
                if(dp[i2][j-1] && ((pr[i]-pr[i2])&mask) == mask)
                    dp[i][j] = 1;
    return dp[n][m];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    pr.resize(n+1);
    for(int i = 0; i < n; ++i)
        pr[i+1] = pr[i]+a[i];
    int ans = 0;
    for(int i = 63; i >= 0; --i)
        if(check(ans|(1LL << i)))
            ans = ans|(1LL << i);
    cout << ans;
    return 0;
}