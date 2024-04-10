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
const int infi=1e9;
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

vector<pii> gra[1005];
vector<vi> ans;
int edges[1005];
bool processed[1005];
void dfs(int fr, int at, int val) {
//	trace(fr,at,val);
	for(auto i:gra[at]) {
		if(i.fi!=fr) {
			edges[i.se]+=val;
			dfs(at,i.fi, val);
			return;
		}
	}
	ans.back().pb(at);
}

void solve() {
	int n;
	cin>>n;
	fr(i,2,n) {
		int u,v,w;
		cin>>u>>v>>w;
		gra[u].pb({v,i});
		gra[v].pb({u,i});
		edges[i]=w;
	}
	fr(i,1,n) {
		if(gra[i].size()==2) {
			if(edges[gra[i][0].se]!=edges[gra[i][1].se]) {
				cout<<"NO"<<endl;
				return;
			}
		}
	}
	fr(i,1,n) {
		trace(i,sz(ans));
		if(gra[i].size()==1) {
			if(-edges[gra[i][0].se]) {
				ans.pb(vi());
				ans.back().pb(i);
				dfs(i,gra[i][0].fi,-edges[gra[i][0].se]);
				ans.back().pb(edges[gra[i][0].se]);
				edges[gra[i][0].se]=0;
			}
		} else {
			for(int j=3; j<sz(gra[i]); j++) {
				if(-edges[gra[i][j].se]) {
					ans.pb(vi());
					dfs(i,gra[i][j].fi,-edges[gra[i][j].se]);
					dfs(gra[i][j].fi,i,-edges[gra[i][j].se]);
					ans.back().pb(edges[gra[i][j].se]);
					edges[gra[i][j].se]=0;
				}
			}
			if(sz(gra[i])==2) {
				if(-edges[gra[i][0].se]) {
					ans.pb(vi());
					dfs(i,gra[i][0].fi,-edges[gra[i][0].se]);
					dfs(i,gra[i][1].fi,-edges[gra[i][1].se]);
					ans.back().pb(edges[gra[i][0].se]);
					edges[gra[i][1].se]=0;
					edges[gra[i][0].se]=0;
				}
			} else {
				int &a=edges[gra[i][0].se],&b=edges[gra[i][1].se],&c=edges[gra[i][2].se];
				if(((a+b-c)/2)) {
					ans.pb(vi());
					dfs(i,gra[i][0].fi,-(a+b-c)/2);
					dfs(i,gra[i][1].fi,-(a+b-c)/2);
					ans.back().pb((a+b-c)/2);
				}
				if(-(a-b+c)/2) {
					ans.pb(vi());
					dfs(i,gra[i][0].fi,-(a-b+c)/2);
					dfs(i,gra[i][2].fi,-(a-b+c)/2);
					ans.back().pb((a-b+c)/2);
				}
				if(-(-a+b+c)/2) {
					ans.pb(vi());
					dfs(i,gra[i][1].fi,-(-a+b+c)/2);
					dfs(i,gra[i][2].fi,-(-a+b+c)/2);
					ans.back().pb((-a+b+c)/2);
				}
				a=0;
				b=0;
				c=0;
			}
		}
		if(i==n) {
			fr(j,2,n) {
				if(edges[j]) {
					i=0;
					break;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	cout<<sz(ans)<<endl;
	for(auto &i:ans) {
		cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	}
	fr(i,2,n) {
		assert(edges[i]==0);
	}
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