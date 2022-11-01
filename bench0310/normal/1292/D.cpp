#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int P=669;
using node=array<int,P>;
node zero;

node operator+(const node &a,const node &b)
{
    node c=zero;
    for(int i=0;i<P;i++) c[i]=a[i]+b[i];
    return c;
}

node lca(node a,node b)
{
    node c=zero;
    for(int i=P-1;i>=0;i--)
    {
        c[i]=min(a[i],b[i]);
        if(a[i]!=b[i]) break;
    }
    return c;
}

ll dist(node a,node b)
{
    node l=lca(a,b);
    ll d=0;
    for(int i=0;i<P;i++) d+=(abs(a[i]-l[i])+abs(l[i]-b[i]));
    return d;
}

const int N=10005;
vector<array<int,2>> g[N];
vector<ll> c(N,0);
ll now=0;
ll res=(1ll<<60);

void dfs(int a,int p=-1)
{
    for(auto [to,d]:g[a])
    {
        if(to==p) continue;
        dfs(to,a);
        c[a]+=c[to];
        now+=(c[to]*d);
    }
}

void reroot(int a,int b,int d)
{
    now-=(c[b]*d);
    c[a]-=c[b];
    now+=(c[a]*d);
    c[b]+=c[a];
}

void solve(int a,int p=-1,int up=0)
{
    res=min(res,now);
    for(auto [to,d]:g[a])
    {
        if(to==p) continue;
        reroot(a,to,d);
        solve(to,a,d);
    }
    if(p!=-1) reroot(a,p,up);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<P;i++) zero[i]=0;
    const int K=5000;
    vector<int> sieve(K+1,0);
    for(int i=1;i<=K;i++) sieve[i]=i;
    vector<int> primes;
    vector<int> h(K+1,0);
    for(int i=2;i<=K;i++)
    {
        if(sieve[i]!=i) continue;
        h[i]=primes.size();
        primes.push_back(i);
        for(int j=i*i;j<=K;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<node> ini(K+1,zero);
    for(int i=1;i<=K;i++)
    {
        ini[i]=ini[i-1];
        int t=i;
        while(t>1)
        {
            ini[i][h[sieve[t]]]++;
            t/=sieve[t];
        }
    }
    int n;
    cin >> n;
    vector<int> cnt(K+1,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<pair<node,int>> v;
    for(int i=0;i<=K;i++) if(cnt[i]>0) v.push_back({ini[i],cnt[i]});
    sort(v.begin(),v.end(),[&](const pair<node,int> &a,const pair<node,int> &b){for(int i=P-1;i>=0;i--)if(a.first[i]!=b.first[i])return (a.first[i]<b.first[i]);return false;});
    int tmp=v.size();
    for(int i=0;i<tmp-1;i++) v.push_back({lca(v[i].first,v[i+1].first),0});
    sort(v.begin(),v.end(),[&](const pair<node,int> &a,const pair<node,int> &b){for(int i=P-1;i>=0;i--)if(a.first[i]!=b.first[i])return (a.first[i]<b.first[i]);return false;});
    vector<pair<node,int>> t;
    int l=0;
    while(l<(int)v.size())
    {
        int cn=0;
        int r=l;
        while(r<(int)v.size()&&v[r].first==v[l].first) cn+=v[r++].second;
        t.push_back({v[l].first,cn});
        l=r;
    }
    int id=2;
    stack<pair<node,int>> s;
    c[1]=t[0].second;
    s.push({t[0].first,1});
    for(int i=1;i<(int)t.size();i++)
    {
        c[id]=t[i].second;
        while(lca(s.top().first,t[i].first)!=s.top().first) s.pop();
        int d=dist(s.top().first,t[i].first);
        g[id].push_back({s.top().second,d});
        g[s.top().second].push_back({id,d});
        s.push({t[i].first,id});
        id++;
    }
    dfs(1);
    solve(1);
    cout << res << "\n";
    return 0;
}