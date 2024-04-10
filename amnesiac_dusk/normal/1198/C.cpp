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
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
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
#define double long double
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

const int N=3e5+5;
set<int> gra[N];
bool valid[N];
bool disabled[N];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,3*n) {
		gra[i].clear();
		valid[i]=1;
		disabled[i]=1;
	}
	vector<pair<int,pii>> edges;
	fr(i,1,m) {
		int u,v;
		cin>>u>>v;
		gra[u].insert(v);
		gra[v].insert(u);
		edges.pb({i,{u,v}});
	}
	random_shuffle(all(edges),rng);
	vi ans;
	for(auto i:edges) {
		if(disabled[i.se.fi]&&disabled[i.se.se]) {
			disabled[i.se.fi]=0;
			disabled[i.se.se]=0;
			ans.pb(i.fi);
		}
	}
	if(sz(ans)>=n) {
		cout<<"Matching"<<endl;
		for(int i=0; i<n; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	auto cmp=[](int i, int j) {
		if(gra[i].size()!=gra[j].size())
			return gra[i].size()<gra[j].size();
		return i<j;
	};
	set<int,decltype(cmp)> q(cmp);
	fr(i,1,3*n) {
		q.insert(i);
	}
	ans.clear();
	while(!q.empty()) {
		int st=*q.begin();
		q.erase(st);
		ans.pb(st);
		for(int i:gra[st]) {
			for(int j:gra[i]) {
				if(q.find(j)!=q.end()) {
					q.erase(j);
					gra[j].erase(i);
					q.insert(j);
				}
			}
			q.erase(i);
		}
		trace(sz(q));
	}
	trace(sz(ans));
	assert(sz(ans)>=n);
	cout<<"IndSet"<<endl;
	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}