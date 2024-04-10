#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)
#define ll int
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,par[N],mark[N],v,u,p,num_ed;
long long ans;
vector <ll> e[N];
pair<ll,ll> ed[N];

ll root(ll x){if(par[x]<0)return x;return par[x]=root(par[x]);}
void merge(ll x,ll y){if(root(x)==root(y))return ;par[root(y)]=root(x);}

void dfs(ll x)
{
    for(int i=0;i<e[x].size();i++)
    {
        if(mark[e[x][i]]==mark[x]){cout<<0;exit(0);}
        if(!mark[e[x][i]])mark[e[x][i]]=((mark[x]==1)?2:1),dfs(e[x][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<N;i++)par[i]=-i;
    for(int i=0;i<m;i++)
    {
        cin>>v>>u>>p;
        if(p)merge(v,u);
        else ed[num_ed++]={v,u};
    }
    for(int i=0;i<num_ed;i++)
    {
        if(root(ed[i].first)==root(ed[i].second))return cout<<0,0;
        v=-par[root(ed[i].first)],u=-par[root(ed[i].second)];
        e[v].push_back(u),e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!mark[i] && i==-par[root(i)])
        {
            if(!ans)ans=1;
            else ans*=2;ans%=MOD;
            mark[i]=1;
            dfs(i);
        }
    cout<<ans;
    return 0;
}