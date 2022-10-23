#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+10,mod=1e9+7,inf=1e9;

int dp[maxn],m,n,mark[maxn];
pii a[maxn];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i].fi>>a[i].se;
    for (int i=1;i<=n;i++)
        for (int j=max(1,a[i].fi-a[i].se);j<=min(m,a[i].fi+a[i].se);j++) mark[j]=1;
    for (int i=1;i<=m;i++)
        {
            dp[i]=inf;
            if (mark[i]) dp[i]=min(dp[i],dp[i-1]);
            for (int j=1;j<=n;j++)
            if (a[j].fi-a[j].se<=i)
            {
                int l=a[j].fi-a[j].se,r=a[j].fi+a[j].se,cost=0;
                if (i>r) l-=i-r,cost=i-r;
                if (l<1) l=1;
                dp[i]=min(dp[i],dp[l-1]+cost);
                if (l>1) cost+=l-1;
                dp[i]=min(dp[i],cost);
            }
        }
    cout<<dp[m];
    return 0;
}