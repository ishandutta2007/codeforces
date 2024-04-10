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
#define sz(x) (lli)(x).size()
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
const lli N = 100000L;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
typedef long long ll;
typedef pair<lli, lli> pii;

// template<typename T>
// struct bit{
// // Ref - https://codeforces.com/contest/1208/submission/59476716
// 	lli n;
// 	vector<T> fen;
// 	bit(): n(0) {}
// 	bit(lli _n) : n(_n), fen(_n+10) {}
// 	void add(lli p,T val){
// 		for(;p <= n;p += p & -p)
// 			fen[p] += val;
// 	}
// 	T sum(lli p){
// 		T ans = 0;
// 		for(;p > 0;p -= p & -p)
// 			ans += fen[p];
// 		return ans%mod;
// 	}

//     T query(lli l,lli r){
// 		return sum(r)-sum(l-1);
// 	}
// };

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

typedef vector<pii> vpi;
typedef vector<vpi> graph;

struct LCA {
	int T = 0;
	vi time, path, ret;
	vector<ll> dist;
	RMQ<lli> rmq;

	LCA(graph& C):time(sz(C)), dist(sz(C)), rmq((dfs(C), ret)) {}
	void dfs(graph& C, int v = 0, int p = -1, ll di = 0) {
		time[v] = T++, dist[v] = di;
		trav(e, C[v]) if (e.first != p) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, e.first, v, di + e.second);
		}
	}

	int query(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi cst0,cst1,cst2;
    vi scst0,scst1,scst2;
    vi ucst1,ucst2;
    graph e;
    vi tin,tout,hei;
    // bit<lli> bt0(N+5),bt1(N+5),bt2(N+5);
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void dfs(lli u,lli p,lli h)
{
    hei[u]=h;
    tin[u]=++T;

    for(auto x:e[u])
    {
        const lli v=x.X,w=x.Y;
        if(v==p)
            continue;
        dfs(v,u,(h+w)%mod);
        cst2[u]=(cst2[u]+cst2[v]+2*w*cst1[v]%mod+cst0[v]*(w*w%mod)%mod)%mod;
        cst1[u]=(cst1[u]+cst1[v]%mod+cst0[v]*w%mod)%mod;
        cst0[u]+=cst0[v];
    }
    cst0[u]++;

    tout[u]=++T;
}

void dfs2(lli u,lli p,ii up)
{
    cst2[u]=(cst2[u]+up.Y)%mod;
    cst1[u]=(cst1[u]+up.X)%mod;
    
    ucst2[u]=up.Y%mod;
    ucst1[u]=up.X%mod;
    

    for(auto x:e[u])
    {
        const lli v=x.X,w=x.Y;
        if(v==p)
            continue;
        lli h2=cst2[u],h1=cst1[u],h0=n-cst0[v];
        h2-=cst0[v]*(w*w%mod)%mod+(2*w*cst1[v])%mod+cst2[v];
        h1-=cst0[v]*w+cst1[v];
        h1%=mod;h2%=mod;

        h2+=2*w*h1%mod;
        h2+=(w*w%mod)*h0%mod;

        h1+=w*h0%mod;
        h1%=mod;h2%=mod;
        dfs2(v,u,{h1,h2});
    }
}

lli query(lli u,lli y)
{
    y%=mod;
    lli h0=scst0[u];
    lli h1=scst1[u];
    lli h2=scst2[u];
    h2+=2*y*h1%mod;
    h2+=(y*y%mod)*h0%mod;
    return h2;
}

lli queryu(lli u,lli y)
{
    y%=mod;
    lli h0=n-scst0[u];
    lli h1=ucst1[u];
    lli h2=ucst2[u];
    h2+=2*y*h1%mod;
    h2+=(y*y%mod)*h0%mod;
    return h2;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    e.resize(n+1);
    cst0.resize(n+1);
    cst1.resize(n+1);
    cst2.resize(n+1);
    ucst1.resize(n+1);
    ucst2.resize(n+1);
    tin.resize(n+1);
    tout.resize(n+1);
    hei.resize(n+1);

    fo(i,n-1)
    {
        lli w;
        cin>>u>>v>>w;
        e[u].pb({v,w});
        e[v].pb({u,w});
    }

    dfs(1,-1,0);

    scst0=cst0;
    scst1=cst1;
    scst2=cst2;

    dfs2(1,-1,{0,0});

    e[0].pb({1,0});
    e[1].pb({0,0});
    LCA lca(e);

    lli q;
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        lli ans=0;

        dbg(u,v,ans,lca.distance(u,v))
        if(tin[v]<=tin[u]&&tout[u]<=tout[v])
        {
            ans+=cst2[u];
            ans-=queryu(v,lca.distance(u,v));
        }
        else
        {
            ans+=query(v,lca.distance(u,v));
        }
        dbg(u,ans,cst2[u])
        ans*=2;
        ans-=cst2[u];
        ans%=mod;ans+=mod;ans%=mod;
        cout<<ans<<endl;
    }

}   aryanc403();
    return 0;
}