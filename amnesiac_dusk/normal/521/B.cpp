/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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
typedef double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=4e18;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000009;
typedef vector<int> vi;
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

const int N=1e5+5;
vector<pii> coo[N];
int ans[N];
set<int> ups[N],downs[N];
void solve() {
	int n;
	cin>>n;
	fr(i,0,n-1) {
		int x,y;
		cin>>x>>y;
		coo[y].pb({x,i});
	}
	sort(all(coo[0]));
	fr(i,1,n) {
		if(coo[i].empty())
			break;
		sort(all(coo[i]));
		for(auto j:coo[i]) {
			int lob=lower_bound(all(coo[i-1]),pii{j.fi-1,0})-coo[i-1].begin();
			while(lob<coo[i-1].size()&&abs(j.fi-coo[i-1][lob].fi)<=1) {
				ups[coo[i-1][lob].se].insert(j.se);
				downs[j.se].insert(coo[i-1][lob].se);
				lob++;
			}
		}
	}
	set<int> qu;
	fr(i,0,n-1) {
		int dependent=0;
		for(int j:ups[i])
			if(downs[j].size()==1) {
				dependent++;
			}
		if(dependent==0)
			qu.insert(i);
	}
//	fr(i,0,n-1) {
//		trace(i);
//		for(int j:ups[i])
//			cout<<j<<" ";
//		cout<<" | ";
//		for(int j:downs[i])
//			cout<<j<<" ";
//		cout<<endl;
//	}
	fr(i,0,n-1) {
		assert(qu.size());
		int tom;
		if(i&1) {
			tom=*(qu.begin());
		} else
			tom=*(--qu.end());
		qu.erase(tom);
		trace(tom);
		ans[i]=tom;
		if(downs[tom].size()>1) {
			for(int i:downs[tom]) {
				ups[i].erase(tom);
			}
		} else if(downs[tom].size()==1) {
			for(int i:downs[tom]) {
				ups[i].erase(tom);
				int dep=0;
				for(int j:ups[i]) {
					if(downs[j].size()==1)
						dep++;
				}
				trace(dep);
				if(dep==0)
					qu.insert(i);
			}
		}
		for(int i:ups[tom]) {
			downs[i].erase(tom);
			if(downs[i].size()==1)
				for(int j:downs[i]) {
					qu.erase(j);
				}
		}
//		fr(i,0,n-1) {
//			trace(i);
//			for(int j:ups[i])
//				cout<<j<<" ";
//			cout<<" | ";
//			for(int j:downs[i])
//				cout<<j<<" ";
//			cout<<endl;
//		}
	}
	int an=0;
	int tem=1;
	for(int i=n-1; i>=0; i--) {
		an=(an+tem*ans[i])%mod;
		trace(ans[i]);
		tem=(tem*n)%mod;
	}
	cout<<an<<endl;
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
	fflush(stdout);
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}