#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
int c[10000],use[10000],kilk[10000],nt[10000],ans,mx,imx;
vector <int> vec[10000];
void dfs(int u,int color)
{
    use[u]=color;
    for (int i=0;i<vec[u].size();i++)
        if (use[vec[u][i]]==0) dfs(vec[u][i],color);
}
///-----------------------------------------------------------------------///
int main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++)
        cin>>c[i];
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
        vec[v].pb(u);
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (use[i]==0)
    {
        cnt++;
        dfs(i,cnt);
    }
    for (int i=1;i<=n;i++)
        kilk[use[i]]++;
    for (int i=1;i<=cnt;i++)
    {
        ans+=kilk[i]*(kilk[i]-1)/2;
    }
    for (int i=1;i<=k;i++)
    {
        if (kilk[use[c[i]]]>mx)
        {
            mx=kilk[use[c[i]]];
            imx=use[c[i]];
        }
        nt[use[c[i]]]=1;
    }
    for (int i=1;i<=cnt;i++)
        if (nt[i]==0)
    {
        ans+=mx*(kilk[i]);
        mx+=kilk[i];
    }
    cout<<ans-m;
}