#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10;
int dp[N][2],n;
char a[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        cin>>(a+1);
        n=strlen(a+1);
        a[0]='1';
        for (int i=2;i<=n;i++)
        {
            if (i>2) dp[i][0]=min(dp[i-3][0],dp[i-3][1])+2;
            else dp[i][0]=1;
            if (a[i]!=a[i-2]) dp[i][0]=min(dp[i][0],min(dp[i-2][0],dp[i-2][1])+1);
            dp[i][1]=n;
            if (a[i]!=a[i-1])
            {
                dp[i][1]=dp[i-1][0];
                if (a[i]!=a[i-2]) dp[i][1]=min(dp[i][1],dp[i-1][1]);
            }
        }
        cout<<min(dp[n][1],dp[n][0])<<"\n";
    }
    return 0;
}