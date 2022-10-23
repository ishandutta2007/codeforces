#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=3e5+10,mod=1e9+7,inf=2e9;
int a[N][10],n,m,dp[1000];
pii mask[1000];
int main()
{
   // freopen("ss.inp","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
    {
        /*for (int j=1;j<=m;j++) dp[(1<<(j-1))]=a[i][j];
        dp[0]=inf;*/
        for (int j=0;j<(1<<m);j++)
        {
            //dp[j]=min(dp[j-(j&-j)],dp[(j&-j)]);
            dp[j]=inf;
            for (int t=1;t<=m;t++)
                if ((j>>(t-1))&1) dp[j]=min(dp[j],a[i][t]);
            mask[j]=max(mask[j],mp(dp[j],i));
        }
    }
    int tmp=(1<<m)-1,res=0,t1=1,t2=1;
    for (int j=0;j<=tmp;j++)
        if (min(mask[j].fi,mask[tmp ^ j].fi)>res)
        {
            res=min(mask[j].fi,mask[tmp ^ j].fi);
            t1=mask[j].se;
            t2=mask[j ^ tmp].se;
        }
    cout<<t1<<" "<<t2;
    return 0;
}