#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=1e5+10,mod=1e9+7,inf=2e9;
struct ds
{
    int a,b,c,d;
};
ds g[maxn];
int n,v[maxn],p[maxn];
priority_queue<pii, vector<pii> , greater<pii> > h[maxn];
pii it[maxn*4];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>g[i].a>>g[i].b>>g[i].c>>g[i].d;
}

void build(int st,int l,int r)
{
    if (l==r)
    {
        it[st]=h[l].top();
        return;
    }
    int mid=(l+r)/2;
    build(st*2,l,mid);
    build(st*2+1,mid+1,r);
    it[st]=min(it[st*2],it[st*2+1]);
}

void adding(int st,int l,int r,int v,pii x)
{
    if (l>v || r<v) return;
    if (l==r)
    {
        it[st]=x;
        return;
    }
    int mid=(l+r)/2;
    adding(st*2,l,mid,v,x);
    adding(st*2+1,mid+1,r,v,x);
    it[st]=min(it[st*2],it[st*2+1]);
}

pii get(int st,int l,int r,int u,int v)
{
    if (l>v || r<u) return mp(inf,0);
    if (u<=l && r<=v) return it[st];
    int mid=(l+r)/2;
    return min(get(st*2,l,mid,u,v),get(st*2+1,mid+1,r,u,v));
}

void bfs()
{
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        int x=g[u].c,y=g[u].d;
        int vt=upper_bound(v+1,v+n+1,x)-v-1;
        pii val=get(1,1,n,1,vt);
        while (val.fi<=y)
        {
            int vc=val.se;
            p[vc]=u;
            q.push(vc);
            int tmp=upper_bound(v+1,v+n+1,g[vc].a)-v-1;
            h[tmp].pop();
            adding(1,1,n,tmp,h[tmp].top());
            val=get(1,1,n,1,vt);
        }
    }
}

void process()
{
    for (int i=1;i<=n;i++) v[i]=g[i].a;
    sort(v+1,v+n+1);
    for (int i=1;i<=n;i++) h[i].push(mp(inf,0));
    for (int i=1;i<=n;i++)
    {
        int tmp=upper_bound(v+1,v+n+1,g[i].a)-v-1;
        h[tmp].push(mp(g[i].b,i));
    }
    for (int i=1;i<=n;i++) p[i]=-1;
    build(1,1,n);
    bfs();
    if (p[n]==-1) cout<<-1;
    else
    {
        vector<int> ans;
        int tmp=n;
        while (tmp>0)
        {
            ans.pb(tmp);
            tmp=p[tmp];
        }
        cout<<ans.size()<<endl;
        for (int i=ans.size()-1;i+1;i--) cout<<ans[i]<<" ";
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