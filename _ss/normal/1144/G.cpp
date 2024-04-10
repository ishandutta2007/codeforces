#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=2e5+10,mod=1e9+7,inf=1e9;
int a[maxn],n,mark[maxn],f[maxn][2],trace[maxn][2];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    f[1][0]=inf;
    f[1][1]=-1;
    for (int i=2;i<=n;i++)
    {
        f[i][0]=-1;
        f[i][1]=inf;
    }
    for (int i=1;i<n;i++)
    {
        if (a[i+1]>a[i] && f[i][0]>f[i+1][0]) f[i+1][0]=f[i][0],trace[i+1][0]=0;
        if (a[i+1]<f[i][0] && a[i]<f[i+1][1]) f[i+1][1]=a[i],trace[i+1][1]=0;
        if (a[i+1]<a[i] && f[i][1]<f[i+1][1]) f[i+1][1]=f[i][1],trace[i+1][1]=1;
        if (a[i+1]>f[i][1] && a[i]>f[i+1][0]) f[i+1][0]=a[i],trace[i+1][0]=1;
    }
    int t=-1;
    if (f[n][0]!=-1) t=0;
    if (f[n][1]!=inf) t=1;
    if (t==-1) printf("NO");
    else
    {
        printf("YES\n");
        for (int i=n;i;i--)
        {
            mark[i]=t;
            t=trace[i][t];
        }
        for (int i=1;i<=n;i++) printf("%d ",mark[i]);
    }
    return 0;
}