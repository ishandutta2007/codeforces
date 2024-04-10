#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".sol","r",stdin); freopen (name".dat","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=4*1e5;

vector<pair<int,int> > vec[arr];
int color[arr],sum[arr],d[arr],s[arr],f[arr];

vector<int> ans;

int get(int u)
{
    if (u==color[u]) return(u); else
        return(color[u]=get(color[u]));
}

void dfs(int u, int pred)
{
    if (d[u]!=-1)
        sum[u]=d[u];
    int cnt=0;
    for (int i=0;i<vec[u].size();i++)
        if (vec[u][i].fir!=pred)
        {
            dfs(vec[u][i].fir,u);
            if (sum[vec[u][i].fir]%2)
            {
                ans.pb(vec[u][i].sec);
                cnt++;
            }
            sum[u]+=sum[vec[u][i].fir];
        }
    //cout<<u<<' '<<d[u]<<' '<<cnt<<'\n';


}

signed main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>d[i];
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        s[i]=u;
        f[i]=v;
    }

    for (int i=1;i<=n;i++)
        color[i]=i;

    for (int i=1;i<=m;i++)
    {
        int a=get(s[i]);
        int b=get(f[i]);
        if (a==b) continue;
        vec[s[i]].pb({f[i],i});
        vec[f[i]].pb({s[i],i});
        if (rand()%2) swap(a,b);
        color[a]=b;
    }

    int root=1;
    bool ch=0;
    int sum=0;

    for (int i=1;i<=n;i++)
    {
        sum+=d[i];
        if (d[i]==-1)
        {
            root=i;
            ch=1;
        }
    }

    if (!ch && sum%2==1)
    {
        cout<<-1;
        return(0);
    }

    dfs(root,-1);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';

    for (int i=0;i<ans.size();i++)
        cout<<ans[i]<<'\n';
}