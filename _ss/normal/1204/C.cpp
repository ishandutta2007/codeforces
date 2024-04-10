#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e6+10,msiz=2,mod=1e9+7,inf=1e6;
int n,a[101][101],p[maxn],m,dis[101][101];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    char ch;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cin>>ch;
            a[i][j]=(ch=='1');
            if (a[i][j]==1) dis[i][j]=1; else dis[i][j]=inf;
        }
    cin>>m;
    for (int i=1;i<=n;i++) dis[i][i]=0;
    for (int i=1;i<=m;i++) cin>>p[i];
    for (int t=1;t<=n;t++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
    vector<int> ans;
    int t=1;
    ans.pb(p[1]);
    for (int i=2;i<=m;i++)
    {
        if (i-t!=dis[p[t]][p[i]])
        {
            ans.pb(p[i-1]);
            t=i-1;
        }
    }
    ans.pb(p[m]);
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++) cout<<dis[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}