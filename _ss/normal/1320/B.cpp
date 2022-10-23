#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=4e5+10;
int n,k,m,p[N],d[N],visit[N];
vector<int> G[N],IG[N];

void read()
{
    cin>>n>>m;
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        IG[v].pb(u);
    }
    cin>>k;
    for (int i=1;i<=k;i++) cin>>p[i];
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visit[x]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v : IG[u])
            if (!visit[v])
            {
                visit[v]=1;
                d[v]=d[u]+1;
                q.push(v);
            }
    }
}

void process()
{
    bfs(p[k]);
    int res1=0,res2=0;
    for (int i=1;i<k;i++)
    {
        int flag1=0,flag2=0,u=p[i];
        for (int v : G[u])
            if (d[v]==d[u]-1)
            {
                if (v==p[i+1]) flag1=1;
                else flag2=1;
            }
        if (!flag1) res1++;
        if (flag2) res2++;
    }
    cout<<res1<<" "<<res2;
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