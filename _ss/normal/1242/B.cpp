#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
int deg[maxn],n,m,visit[maxn],mark[maxn];
vector<int> G[maxn];
set<int> st;
set<int>::iterator it;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    st.erase(u);
    while (!q.empty())
    {
        int v=q.front();
        q.pop();
        visit[v]=1;
        for (int i=0;i<(int)G[v].size();i++)
        if (st.count(G[v][i])>0)
        {
            mark[i]=1;
            st.erase(G[v][i]);
        }
        while (!st.empty())
        {
            it=st.begin();
            q.push(*it);
            st.erase(it);
        }
        for (int i=0;i<(int)G[v].size();i++)
            if (mark[i]) st.insert(G[v][i]),mark[i]=0;
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1;i<=n;i++) st.insert(i);
    int cnt=0;
    for (int i=1;i<=n;i++)
        if (!visit[i]) bfs(i),cnt++;
    cout<<cnt-1;
    return 0;
}