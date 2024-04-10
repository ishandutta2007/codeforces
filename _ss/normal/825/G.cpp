#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
const ll maxn=1e6+10,mod=1e9+7,inf=1e18;
vector<int> G[maxn];
int n,q,root,p[maxn],f[maxn],mark[maxn],m,visit[maxn];

void read()
{
    cin>>n>>q;
    int u,v;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        //scanf("%d %d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    cin>>u>>v;
    root=v%n+1;
}

void dfs(int obj)
{
    stack<int> st;
    st.push(obj);
    while (!st.empty())
    {
        int u=st.top();
        st.pop();
        visit[u]=1;
        for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]])
        {
            p[G[u][i]]=u;
            f[G[u][i]]=min(G[u][i],f[u]);
            st.push(G[u][i]);
        }
        while (!st.empty() && visit[st.top()]) st.pop();
    }
}

void update(int u)
{
    while (!mark[u])
    {
        m=min(m,u);
        mark[u]=1;
        u=p[u];
    }
}

void process()
{
    mark[root]=1;
    f[root]=root;
    dfs(root);
    m=root;
    int t,x,last=0;
    for (int i=1;i<q;i++)
    {
        cin>>t>>x;
        //scanf("%d %d",&t,&x);
        x=(x+last)%n+1;
        if (t==1) update(x);
        else
        {
            printf("%d\n",min(m,f[x]));
            last=min(m,f[x]);
        }
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}