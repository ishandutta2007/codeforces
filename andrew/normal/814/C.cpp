#include <bits/stdc++.h>
#define ll long long
#define p_b push_back
#define endl "\n"
using namespace std;
string s;
ll dd,dp[1000][1501],sc[100000],c,i,j,n,m,k,l,r,ans;
int main() {

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> s;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=26;j++)sc[j]=0;
        l=0;
        r=i-1;
        for(j=l;j<=r;j++)
        {
            c=s[j]-96;
            sc[c]++;
        }
        while(r<n)
        {
             for(j=1;j<=26;j++)
             {
                  dd=i-sc[j];
                 dp[j][dd]=max(dp[j][dd],i);
             }
             c=s[l]-96;
             sc[c]--;
             r++;
             l++;
             if(r>=n)break;
             c=s[r]-96;
             sc[c]++;
        }
    }
    cin >> m;
        char ccc;
        for(i=1;i<=26;i++)
        {
            ans=-1e18;
            for(j=0;j<=n;j++)
            {
                ans=max(ans,dp[i][j]);
                dp[i][j]=ans;
            }
        }
    while(m>0)
    {
        cin >> k >> ccc;
        c=ccc-96;
        cout << dp[c][k] << endl;
        m--;
    }
    return 0;
}