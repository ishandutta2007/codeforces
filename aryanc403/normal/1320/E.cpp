/* in the name of Anton */

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
#define sz(x) ((lli)(x).size())
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


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
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
bool operator()(pair<lli,ii> a , pair<lli,ii> b) //For min priority_queue .
{    return ! ( a.X < b.X );   }};

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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;

typedef vector<pii> vpi;
typedef vector<vpi> graph;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < N) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll>> q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

vpi compressTree(LCA& lca, const vi& subset) {
	static vi rev; rev.resize(sz(lca.dist));
	vi li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(all(li), cmp);
	int m = sz(li)-1;
	rep(i,0,m) {
		int a = li[i], b = li[i+1];
		li.push_back(lca.query(a, b));
	}
	sort(all(li), cmp);
	li.erase(unique(all(li)), li.end());
	rep(i,0,sz(li)) rev[li[i]] = i;
	vpi ret = {pii(0, li[0])};
	rep(i,0,sz(li)-1) {
		int a = li[i], b = li[i+1];
		ret.emplace_back(lca.query(a, b), b);
	}
	return ret;
}

graph e(1);
LCA lca(e);
vii viru;
vi cities,subset;
vi ans;
graph ee;

void init()
{

    subset=cities;
    for(auto x:viru)
        subset.pb(x.X);
    sort(all(subset));
    subset.erase(unique(all(subset)),subset.end());
    auto ctree=compressTree(lca,subset);
    subset.clear();
    for(auto x:ctree)
    {
        subset.pb(x.X);
        subset.pb(x.Y);
    }

    sort(all(subset));
    subset.erase(unique(all(subset)),subset.end());
    const lli n=sz(subset);
    ee.clear();ee.resize(n);
    
    auto gt=[&](const lli x){
        return lower_bound(all(subset),x)-subset.begin();
    };
    dbg(ctree);
    for(auto x:ctree)
    {
        if(x.X==x.Y)
            continue;
        const lli u=gt(x.X);
        const lli v=gt(x.Y);
        const lli d=lca.distance(x.X,x.Y);
        ee[u].pb({v,d});
        ee[v].pb({u,d});
        dbg(x.X,x.Y,u,v,d);
    }
}

void solve()
{
    auto gt=[&](const lli x){
        return lower_bound(all(subset),x)-subset.begin();
    };

    priority_queue < pair<lli,ii> , vector < pair<lli,ii> > , CMP > pq;// min priority_queue .
    const lli len=sz(viru);
    const lli n=sz(subset);
    ans.clear();ans.resize(n,-1);

    for(lli i=0;i<len;++i)
    {
        pq.push({i,{gt(viru[i].X),0}});
    }
    dbg(subset);
    dbg(ee);
    while(!pq.empty())
    {
        auto cur=pq.top();pq.pop();
        const lli u=cur.Y.X,d=cur.Y.Y,v=cur.X%len;
        if(ans[u]>=0)
            continue;
        ans[u]=v;
        dbg(subset[u],v,cur.X);
        const lli s=viru[v].Y;
        for(auto x:ee[u])
        {
            dbg(subset[x.X],d+x.Y)
            if(ans[x.X]!=-1)    continue;
            pq.push({((d+x.Y+s-1)/s)*len+v,{x.X,d+x.Y}});
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    e.resize(n);
    fo(i,n-1)
    {
        cin>>u>>v;
        u--;v--;
        e[u].pb({v,1});
        e[v].pb({u,1});
    }

    lca=LCA(e);
    dbg(lca.query(5,6));

    lli q;
    cin>>q;
    while(q--)
    {
        cin>>k>>m;
        viru.resize(k);
        for(auto &x:viru)
        {
            cin>>x.X>>x.Y;
            x.X--;
        }
        cities.resize(m);
        for(auto &x:cities)
        {
            cin>>x;
            x--;
        }

        dbg(viru)
        dbg(cities)

        init();
        solve();
        for(auto x:cities)
            cout<<ans[lower_bound(all(subset),x)-subset.begin()]+1<<" ";
        cout<<endl;
    }

}   aryanc403();
    return 0;
}