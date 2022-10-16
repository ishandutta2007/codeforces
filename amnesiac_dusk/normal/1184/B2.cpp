#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
//#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


struct BipartiteMatcher{
    vector<vector<int>> G;
    vector<int> L, R, Viz;
    void init(int n, int m){
        G.clear(), L.clear(), R.clear(), Viz.clear();
        G.resize(n), L.resize(n, -1), R.resize(m, -1), Viz.resize(n, 0);
    }
    void AddEdge(int a, int b){ G[a].push_back(b); }
    bool Match(int node){
        if(Viz[node]) return 0;
        Viz[node] = 1;
        for(auto vec : G[node]){
            if(R[vec] == -1 || Match(R[vec])) {
                L[node] = vec;
                R[vec] = node;
                return 1;
            }
        }
        return 0;
    }
    int Solve(){
        bool ok = 1;
        while(ok){
            ok = 0;
            fill(Viz.begin(), Viz.end(), 0);
            fr(i, 0, L.size() - 1)
                if(L[i] == -1)
                    ok |= Match(i);
        }
        int ret = 0;
        fr(i, 0, L.size() - 1)
            ret += (L[i] != -1);
        return ret;
    }
} bm;

int dist[101][101];
void solve() {
	int n,m,s,b,k,h;
	cin>>n>>m;
	memset(dist,infi,sizeof(dist));
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		dist[u][v]=1;
		dist[v][u]=1;
	}
	fr(i,1,n)
		dist[i][i]=0;
	fr(i,1,n)
		fr(j,1,n)
			fr(k,1,n)
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
	cin>>s>>b>>k>>h;
	bm.init(s, b);
	vector<pair<int,pii>> sp;
	vector<pii> bases;
	fr(i,1,s) {
		int x,a,f;
		cin>>x>>a>>f;
		sp.pb({x,{a,f}});
	}
	fr(i,1,b) {
		int x,d;
		cin>>x>>d;
		bases.pb({x,d});
	}
	for(int i=0; i<s; i++) {
		for(int j=0; j<b; j++) {
			if(dist[sp[i].fi][bases[j].fi]<=sp[i].se.se&&sp[i].se.fi>=bases[j].se) {
				bm.AddEdge(i, j);
			}
		}
	}
	cout<<min(bm.Solve()*k,h*s)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}