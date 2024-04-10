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
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> a[i] >> b[i];
        if(n==k)
        {
            vector<array<int,2>> v(n);
            for(int i=0;i<n;i++) v[i]={b[i],i};
            sort(v.begin(),v.end());
            cout << n << "\n";
            for(int i=0;i<n;i++) cout << v[i][1]+1 << " \n"[i==n-1];
            continue;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<vector<bool>> p(n+1,vector<bool>(n+1,0));
        dp[0][0]=0;
        vector<array<int,2>> v(n);
        for(int i=0;i<n;i++) v[i]={b[i],i};
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            int x=v[i][1];
            for(int j=0;j<=n;j++)
            {
                if(dp[i][j]==-1) continue;
                //one
                if(dp[i][j]+a[x]+j*b[x]>dp[i+1][j+1])
                {
                    dp[i+1][j+1]=dp[i][j]+a[x]+j*b[x];
                    p[i+1][j+1]=0;
                }
                //two
                if(dp[i][j]+(k-1)*b[x]>dp[i+1][j])
                {
                    dp[i+1][j]=dp[i][j]+(k-1)*b[x];
                    p[i+1][j]=1;
                }
            }
        }
        vector<int> one;
        vector<int> two;
        int now=k;
        for(int i=n;i>=1;i--)
        {
            int x=v[i-1][1];
            if(p[i][now]==0)
            {
                one.push_back(x);
                now--;
            }
            else two.push_back(x);
        }
        reverse(one.begin(),one.end());
        vector<int> res;
        for(int i=0;i<k-1;i++) res.push_back(one[i]+1);
        for(int x:two)
        {
            res.push_back(x+1);
            res.push_back(-(x+1));
        }
        res.push_back(one[k-1]+1);
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}