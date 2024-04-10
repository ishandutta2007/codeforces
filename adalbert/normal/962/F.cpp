#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
typedef long double ld;

const int arr=3e5;

vector<pair<int,int> > vec[arr];
vector<int> add;
int deep[arr],ok[arr],use[arr];
int a[arr],b[arr],cnt[arr];
vector<pair<int,int> > ask[arr];
vector<pair<int,int> > cyc;
int pr[arr];

void dfs(int u, int pred)
{
    use[u]=1;
    pr[u]=pred;
    deep[u]=deep[pred]+1;

    for (auto i:vec[u])
        if(i.fir!=pred)
    {
        if (use[i.fir])
        {
            if (deep[i.fir]<deep[u])
            add.pb(i.sec);
        } else
        dfs(i.fir,u);
    }
}

void dfs2(int u, int pred)
{
    use[u]=1;

    for (auto i:vec[u])
        if(i.fir!=pred)
        if (!use[i.fir])
        {
            dfs2(i.fir,u);
            cnt[u]+=cnt[i.fir];
        }
}

int get()
{
    if (cyc.empty())
        return(0);
    return(cyc.back().sec);
}

void addd(int u)
{
    if (u!=1)
        cyc.pb({u,0}); else
        cyc.pb({u,get()+1});
}

void dell()
{
    cyc.pop_back();
}

void dfs3(int u, int pred)
{
    use[u]=1;
    for (auto i:ask[u])
    {
        if (get()>=i.fir)
            ok[i.sec]=1;
    }

    for (auto i:vec[u])
        if (!use[i.fir])
        {
            addd(cnt[i.fir]);
            dfs3(i.fir,u);
            dell();
        }
}

map<pair<int,int>,int > mp;

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        mp[{a[i],b[i]}]=i;
        mp[{b[i],a[i]}]=i;

        vec[a[i]].pb({b[i],i});
        vec[b[i]].pb({a[i],i});
    }

    for (int i=1;i<=n;i++)
        if (!use[i])
            dfs(i,0);

    for (auto i:add)
    {
        if (deep[a[i]]<deep[b[i]])
            swap(a[i],b[i]);
        cnt[a[i]]++;
        cnt[b[i]]--;
    }

    for (int i=1;i<=n;i++)
        use[i]=0;

    for (int i=1;i<=n;i++)
        if (!use[i])
            dfs2(i,0);

    int cnt=0;
    for (auto i:add)
    {
        ask[a[i]].pb({deep[a[i]]-deep[b[i]],i});
    }

    for (int i=1;i<=n;i++)
        use[i]=0;

    for (int i=1;i<=n;i++)
        if (!use[i])
            dfs3(i,0);
    vector<int> ans;
    for (auto i:add)
        if (ok[i])
    {
        ans.pb(i);
        while (a[i]!=b[i])
        {
            ans.pb(mp[{a[i],pr[a[i]]}]);
            a[i]=pr[a[i]];
        }
    }

    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for (auto i:ans)
        cout<<i<<' ';
}
/*

*/