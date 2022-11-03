#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=2e5+100;

vector<int> vec[arr];
int deep[arr],dp[arr][25],v[8*arr],push[8*arr],in[arr],out[arr];
int now_root=1;
int cnt=0;

void make_push(int i, int tl, int tr)
{
    push[i*2]+=push[i];
    push[i*2+1]+=push[i];
    int d=(tl+tr)/2;
    v[i*2]+=push[i]*(d-tl+1);
    v[i*2+1]+=push[i]*(tr-d);

    push[i]=0;
}

void change(int i, int tl, int tr, int l, int r, int x)
{
    if (tl>=l && tr<=r)
    {
        v[i]+=x*(tr-tl+1);
        push[i]+=x;
        return;
    }

    if (tl>r || tr<l)
        return;

    int d=(tl+tr)/2;
    make_push(i,tl,tr);

    change(i*2,tl,d,l,r,x);
    change(i*2+1,d+1,tr,l,r,x);

    v[i]=v[i*2]+v[i*2+1];
}

int get(int i, int tl, int tr, int l, int r)
{
    if (tl>=l && tr<=r)
        return(v[i]);
    if (tl>r || tr<l)
        return(0);

    int d=(tl+tr)/2;
    make_push(i,tl,tr);

    return(get(i*2,tl,d,l,r)+get(i*2+1,d+1,tr,l,r));
}

void dfs(int u, int pred)
{
    in[u]=++cnt;
    deep[u]=deep[pred]+1;
    dp[u][0]=pred;
    for (int i=1;i<=20;i++)
        dp[u][i]=dp[dp[u][i-1]][i-1];

    for (auto i:vec[u])
        if (i!=pred)
        dfs(i,u);
    out[u]=cnt;
}

int lca(int a, int b)
{
    for (int i=20;i>=0;i--)
        if (deep[a]-(1<<i)>=deep[b])
        a=dp[a][i];

    for (int i=20;i>=0;i--)
        if (deep[b]-(1<<i)>=deep[a])
        b=dp[b][i];

    for (int i=20;i>=0;i--)
        if (dp[a][i]!=dp[b][i])
    {
        a=dp[a][i];
        b=dp[b][i];
    }

    if (a==b)
        return(a);
    return(dp[a][0]);
}

int real_lca(int a, int b)
{
    int intree=0;
    if (lca(a,now_root)==now_root)
        intree++;
    if (lca(b,now_root)==now_root)
        intree++;
    if (intree==2)
        return(lca(a,b));
    if (intree==1)
        return(now_root);

    int x=lca(a,now_root);
    int y=lca(b,now_root);
    int z=lca(a,b);

    if (deep[x]<deep[y])
        swap(x,y);
    if (deep[x]<deep[z])
        swap(x,z);
    if (deep[x]==deep[y] && x!=y)
        exit(1);
    if (deep[x]==deep[z] && x!=z)
        exit(1);
    return(x);
}

int plca(int a, int b)
{
    for (int i=20;i>=0;i--)
        if (deep[a]-(1<<i)>deep[b])
        a=dp[a][i];
    return(a);
}

int a[arr];

signed main()
{
    fast;
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    for (int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    dfs(1,0);

    for (int i=1;i<=n;i++)
    {
        change(1,1,n,in[i],in[i],a[i]);
    }
    while (q--)
    {
        int type;
        cin>>type;
        if (type==1)
        {
            cin>>now_root;
        } else
        if (type==2)
        {
            int u,uu,x;
            cin>>u>>uu>>x;
            u=real_lca(u,uu);
            if (u==now_root)
                change(1,1,n,1,n,x); else
            if (lca(u,now_root)==u)
            {

                change(1,1,n,1,n,x);
                int pc=plca(now_root,u);
                change(1,1,n,in[pc],out[pc],-x);
            } else
            {
                change(1,1,n,in[u],out[u],x);
            }
        } else
        {
            int u,x;
            cin>>u;
            int ans=0;

            if (u==now_root)
                ans+=get(1,1,n,1,n); else
            if (lca(u,now_root)==u)
            {
                ans+=get(1,1,n,1,n);
                int pc=plca(now_root,u);
                ans-=get(1,1,n,in[pc],out[pc]);
            } else
            {
                ans+=get(1,1,n,in[u],out[u]);
            }
            cout<<ans<<'\n';
        }
    }
}
/*
2
set physicsexercise 2
query physicsexercise
*/