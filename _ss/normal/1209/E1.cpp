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
int a[6][110],n,m,f[6][6],k,res;
pii mr[110];

bool cmp(pii t1,pii t2)
{
    return t1.fi>t2.fi;
}

void dfs(int d)
{
    if (d>k)
    {
        int kq=0;
        for (int i=1;i<=n;i++)
        {
            int t=0;
            for (int j=1;j<=k;j++) t=max(t,f[i][j]);
            kq+=t;
        }
        res=max(res,kq);
        return;
    }
    for (int i=1;i<=n;i++)
    {
        int tmp=f[1][d];
        for (int j=1;j<n;j++) f[j][d]=f[j+1][d];
        f[n][d]=tmp;
        dfs(d+1);
    }
}

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
            for (int j=1;j<=k;j++) f[i][j]=a[i][mr[j].se];
        res=0;
        dfs(1);
        cout<<res<<endl;
    }
    return 0;
}