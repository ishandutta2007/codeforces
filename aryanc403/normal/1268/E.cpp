/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/priank/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi dp,dpe;
    vii par;
    vector<vii> e;
    vii edges;
    vector<lli> vis;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void cycle(vi &a)
{
    lli n=sz(a);
    lli i,mn=INF;
    fo(i,n)
    {
        a.pb(a[i]);
        mn=min(mn,a[i]);
    }

    n*=2;
    fo(l,n)
    {
        if(a[l]==mn)
            break;
    }

    repD(r,n-1,0)
    {
        if(a[r]==mn)
            break;
    }

    while(l+1<n&&a[l]<a[l+1])
        l++;

    while(r-1>=0&&a[r]<a[r-1])
        r--;

    // dbg(mn,a[l],a[r],a);
    if(l==r)
        dpe[mn]=a[l];
}

void dfs(lli u,lli p,lli ed)
{
    dbg(u,p,ed);
    if(vis[u])
    {
        if(vis[u]==2)
            return;

        swap(u,p);
        vi a;
        a.pb(ed);
        while(u!=p)
        {
            a.pb(par[u].Y);
            u=par[u].X;
        }

        cycle(a);
        return;
    }

    vis[u]=1;
    par[u]={p,ed};
    for(auto x:e[u])
    {
        if(x.X==p)
            continue;
        dfs(x.X,u,x.Y);
    }

    vis[u]=2;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    dp.resize(n+1,1);
    vis.resize(n+1,0);
    dpe.resize(m+1,0);

    par.resize(n+1,{-1,-1});
    e.resize(n+1,vii());
    edges.pb({0,0});

    repA(i,1,m)
    {
        cin>>u>>v;
        e[u].pb({v,i});
        e[v].pb({u,i});
        edges.pb({u,v});
    }

    // if(n==500&&m==560)
    // {
    //     repA(i,1,m)
    //         cerr<<edges[i].X<<" "<<edges[i].Y<<endl;
    //     assert(false);
    // }

    dfs(1,0,0);

    UF d(n+1);

    repD(i,m,1)
    {
        u=edges[i].X;
        v=edges[i].Y;

        if(d.join(u,v))
            dpe[i]=dp[u]+dp[v];
        else
            dpe[i]=dp[u]+dp[v]-dpe[dpe[i]];
        dp[u]=dp[v]=dpe[i];
    }

    repA(i,1,n)
        cout<<dp[i]-1<<" ";cout<<endl;

}   aryanc403();
    return 0;
}