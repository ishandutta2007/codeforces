#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i){
        string s1 = "";
        for(int j = i; j < n; ++j)
            s1 += s[j];
        s1 += '$';
        for(int j = 0; j < i; ++j)
            s1 += s[j];
        vector<int> z(n+1, 0);
        int l = 0, r = 0;
        for(int j = 1; j <= n; ++j){
            if(j <= r)
                z[j] = min(r-j+1, z[j-l]);
            while(z[j]+j <= n && s1[z[j]] == s1[j+z[j]])
                z[j]++;
            if(j+z[j]-1 > r)
                l = j, r = j+z[j]-1;
        }
        for(int j = n-i+1; j <= n; ++j)
            v[i] = max(v[i], z[j]);
    }
    vector<int> dp(n+1, n*a);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        dp[i+1] = dp[i]+a;
        for(int j = 1; j <= i; ++j)
            if(v[j]+j > i)
                dp[i+1] = min(dp[i+1], dp[j]+b);
    }
    cout << dp[n];
	return 0;
}