#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        s="0"+s;
        vector<int> sumv(n+1,0);
        for(int i=1;i<=n;i++) sumv[i]=sumv[i-1]+(s[i]=='1');
        auto sum=[&](int l,int r)->int{return sumv[r]-sumv[l-1];};
        vector<int> dp(n+1,0);
        for(int i=1;i<=k;i++) dp[i]=sum(1,i-1)+(s[i]=='0');
        for(int i=k+1;i<=n;i++) dp[i]=min(dp[i-k]+sum(i-k+1,i-1),sum(1,i-1))+(s[i]=='0');
        int res=sum(1,n);
        for(int i=1;i<=n;i++) res=min(res,dp[i]+sum(i+1,n));
        cout << res << "\n";
    }
    return 0;
}