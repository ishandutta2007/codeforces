#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=6e5+10;
int root[N],n,k,visit[N],p[N],a[N],sl[N];
vector<int> vex[N];
pii E[N];
char s[N];

void read()
{
    cin>>n>>k;
    cin>>s;
    for (int i=1,c;i<=k;i++)
    {
        cin>>c;
        for (int j=1,x;j<=c;j++)
        {
            cin>>x;
            if (E[x].fi) E[x].se=i;
            else E[x].fi=i;
        }
    }
    for (int i=1;i<=n;i++) a[i]=(s[i-1]=='1');
}

void merg(int u,int v,int w)
{
    u=root[u];
    v=root[v];
    if (vex[u].size()<vex[v].size()) swap(u,v);
    if (v==0) swap(u,v);
    for (int x : vex[v])
    {
        if (w)
        {
            if (p[x]) p[x]=0;
            else p[x]=1,sl[u]++;
        }
        else sl[u]+=p[x];
        vex[u].pb(x);
        root[x]=u;
    }
    vex[v].clear();
}

int getv(int x)
{
    if (x==0) return sl[x];
    return min((int)vex[x].size()-sl[x],sl[x]);
}

void process()
{
    for (int i=1;i<=k;i++) root[i]=i,vex[i].pb(i);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (E[i].fi==0)
        {
            cout<<ans<<"\n";
            continue;
        }
        int u=E[i].fi,v=E[i].se;
        if (!visit[u]) visit[u]=1;
        if (!visit[v] && v) visit[v]=1;
        if (root[u]!=root[v])
        {
            ans-=getv(root[u])+getv(root[v]);
            merg(u,v,a[i] ^ p[u] ^ p[v] ^ 1);
            ans+=getv(root[u]);
        }
        cout<<ans<<"\n";
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