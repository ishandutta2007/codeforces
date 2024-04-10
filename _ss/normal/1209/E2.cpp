#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+1,mod=1e9+7,inf=1e18;
int a[15][2110],n,m,f[15][15][15],k,dp[5000][200][15];
pii mr[2110];

bool cmp(pii t1,pii t2)
{
    return t1.fi>t2.fi;
}

void mm(int &t1,int t2) {t1=max(t1,t2);}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for (int w=1;w<=t;w++)
    {
        cin>>n>>m;
        for (int i=1;i<=m;i++) mr[i]={0,0};
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) cin>>a[i][j],mr[j].fi=max(mr[j].fi,a[i][j]);
        for (int i=1;i<=m;i++) mr[i].se=i;
        sort(mr+1,mr+m+1,cmp);
        k=min(m,n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++) f[i][j][1]=a[i][mr[j].se];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=k;j++)
                for (int t=2;t<=n;t++) f[i][j][t]=f[(i+t-2)%n+1][j][1];
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<=n*k;j++)
                for (int t=0;t<=n;t++) dp[i][j][t]=0;
        for (int i=1;i<=k;i++)
        {
            for (int mask=0;mask<(1<<n);mask++)
                for (int t=1;t<=n;t++) mm(dp[mask][(i-1)*n][0],dp[mask][(i-1)*n][t]);
            for (int mask=0;mask<(1<<n);mask++)
                for (int t=1;t<=n;t++)
                {
                    mm(dp[mask][(i-1)*n+1][t],dp[mask][(i-1)*n][0]);
                    if ((mask&1)==0) mm(dp[mask ^ 1][(i-1)*n+1][t],dp[mask][(i-1)*n][0]+f[1][i][t]);
                }
            for (int j=2;j<=n;j++)
                for (int mask=0;mask<(1<<n);mask++)
                    for (int t=1;t<=n;t++)
                    {
                        mm(dp[mask][(i-1)*n+j][t],dp[mask][(i-1)*n+j-1][t]);
                        if ((mask&(1<<(j-1)))==0) mm(dp[mask ^ (1<<(j-1))][(i-1)*n+j][t],dp[mask][(i-1)*n+j-1][t]+f[j][i][t]);
                    }
        }
        int res=0;
        for (int t=1;t<=n;t++) res=max(res,dp[(1<<n)-1][n*k][t]);
        cout<<res<<endl;
    }
    return 0;
}