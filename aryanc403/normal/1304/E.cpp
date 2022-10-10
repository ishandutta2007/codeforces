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
// const lli maxN = 1000000007L;
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


    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    graph e;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n;
    e.resize(n+1);
    e[0].pb({1,1});
    e[1].pb({0,1});
    
    fo(i,n-1)
    {
        cin>>u>>v;
        e[u].pb({v,1});
        e[v].pb({u,1});
    }

    LCA a(e);
    cin>>m;
    while(m--)
    {
        cin>>u>>v>>x>>y>>k;
        bool fl=false;
        lli d;
        d=a.distance(x,y);
        if(d<=k&&(k-d)%2==0)
            fl=true;
        
        d=a.distance(x,u)+a.distance(v,y)+1;
        if(d<=k&&(k-d)%2==0)
            fl=true;

        d=a.distance(y,u)+a.distance(v,x)+1;
        if(d<=k&&(k-d)%2==0)
            fl=true;
        cout<<(fl?"YES":"NO")<<endl;
    }
}   aryanc403();
    return 0;
}