#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,inf=1e18;
vector<pii> G[N];
pii e[N];
int n,m,q,inqueue[N],change=0;
ll d[N];

void read()
{
    scanf("%d %d %d",&n,&m,&q);
    for (int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        G[u].pb(mp(v,w));
        e[i]=mp(u,(int)G[u].size()-1);
    }
}

void build()
{
    for (int i=2;i<=n;i++) d[i]+=change+1;
    inqueue[1]=1;
    deque<int> q;
    q.push_back(1);
    int cnt=0;
    while (!q.empty())
    {
        int u;
        cnt++;
        if (cnt&1)
        {
            u=q.front();
            q.pop_front();
        }
        else
        {
            u=q.back();
            q.pop_back();
        }
        inqueue[u]=0;
        for (pii v : G[u])
            if (d[u]+v.se<d[v.fi])
            {
                d[v.fi]=d[u]+v.se;
                if (!inqueue[v.fi])
                {
                    inqueue[v.fi]=1;
                    q.push_back(v.fi);
                }
            }
    }
}

void process()
{
    for (int i=2;i<=n;i++) d[i]=inf;
    build();
    for (int i=1,t,x;i<=q;i++)
    {
        scanf("%d %d",&t,&x);
        if (t==1)
        {
            if (d[x]>=inf) cout<<"-1\n";
            else
            {
                if (change)
                {
                    build();
                    change=0;
                }
                cout<<d[x]<<"\n";
            }
        }
        else
        {
            change+=x;
            for (int j=1,c;j<=x;j++)
            {
                scanf("%d",&c);
                G[e[c].fi][e[c].se].se++;
            }
        }
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cout.tie(0);
    read();
    process();
    return 0;
}