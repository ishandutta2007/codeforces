#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=1e5+10,siz=320;
int n,a[N],p[N],bonus[N],pr[N],nx[N],cnt_upd[N],del[N],q,gdu[N];

void read()
{
    cin>>n>>q;
    for (int i=2;i<=n;i++) cin>>a[i];
}

set<int> st;

int find_p(int x)
{
    if (!del[x]) return p[x];
    return max(a[x]-bonus[gdu[x]],1);
}

int find_a(int x)
{
    return max(1,a[x]-bonus[gdu[x]]);
}

void era(int x)
{
    int u=pr[x],v=nx[x];
    nx[u]=v;
    pr[v]=u;
    del[x]=1;
    st.erase(x);
}
void upd(int l,int r,int x)
{
    int bl=gdu[l],br=gdu[r];
    if (bl==br)
    {
        for (int i=l;i<=r;i++) a[i]=max(a[i]-x,1);
    }
    else
    {
        for (int i=l;i<=bl*siz;i++) a[i]=max(a[i]-x,1);
        for (int i=br*siz-siz+1;i<=r;i++) a[i]=max(a[i]-x,1);
        for (int i=bl+1;i<br;i++) bonus[i]=min(bonus[i]+x,n);
    }
    int r2=min(n,gdu[r]*siz);
    l=*st.lower_bound(l);
    while (l<=r2)
    {
        int val=max(1,a[l]-bonus[gdu[l]]),lw=max(1,gdu[l]*siz-siz);
        if (val>lw) val=find_p(val);
        p[l]=val;
        p[l]=val;
        if (l<=r) cnt_upd[l]+=x;
        if (cnt_upd[l]>siz) era(l);
        l=nx[l];
    }
}

int lca(int u,int v)
{
    while (u!=v)
    {
        int pu=find_p(u),pv=find_p(v);
        if (pu<pv) v=pv;
        else if (pv<pu) u=pu;
        else break;
    }
    while (u!=v)
    {
        int au=find_a(u),av=find_a(v);
        if (au<av) v=av;
        else if (av<au) u=au;
        else
        {
            u=au;
            break;
        }
    }
    return u;
}

void precal()
{
    for (int i=1;i<=n;i++) gdu[i]=(i-1)/siz+1;
    for (int i=1;i<=n;i++) pr[i]=i-1,nx[i]=i+1,st.insert(i);
    st.insert(n+1);
    a[1]=p[1]=1;
    for (int i=2;i<=n;i++)
    {
        p[i]=a[i];
        if (p[i]>max(1,gdu[i]*siz-siz)) p[i]=p[p[i]];
    }
}

void process()
{
    for (int i=1,t,u,v;i<=q;i++)
    {
        cin>>t>>u>>v;
        if (t==1)
        {
            int x;
            cin>>x;
            upd(u,v,x);
        }
        else cout<<lca(u,v)<<"\n";
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    precal();
    process();
    return 0;
}