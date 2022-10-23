#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,d[N],visit[N];
vector<int> G[N];

void read()
{
    cin>>n;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

int ask(int u,int v)
{
    cout<<"? "<<u<<" "<<v<<"\n";
    cout.flush();
    int r;
    cin>>r;
    return r;
}

int process()
{
    for (int i=1;i<=n;i++) d[i]=G[i].size();
    queue<int> q;
    for (int i=1;i<=n;i++)
        if (d[i]==1) q.push(i),visit[i]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        if (q.empty()) return u;
        int v=q.front();
        q.pop();
        int r=ask(u,v);
        if (r==u || r==v) return r;
        for (int x : G[u])
        {
            d[x]--;
            if (d[x]==1 && !visit[x]) q.push(x),visit[x]=1;
        }
        for (int x : G[v])
        {
            d[x]--;
            if (d[x]==1 && !visit[x]) q.push(x),visit[x]=1;
        }
    }
    return 1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    cout<<"! "<<process()<<"\n";
    cout.flush();
    return 0;
}