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
const ll infl=1e12;
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
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

stack<pii> deps[300005];
vector<pii> dep[1000005],arr[1000005];
int marcost[300005];
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	fr(i,1,m) {
		int d,f,t,c;
		cin>>d>>f>>t>>c;
		if(f==0) {
			dep[d].pb({c,t});
		} else {
			arr[d].pb({c,f});
		}
	}
	int ans=0,depart=0;
	for(int i=1000000; i>k+1; i--) {
		for(pii f:dep[i]) {
			while((!deps[f.se].empty())&&(deps[f.se].top().fi>f.fi)&&(deps[f.se].top().se==i))
				deps[f.se].pop();
			if((!deps[f.se].empty())&&(deps[f.se].top().fi<=f.fi))
				continue;
			if(deps[f.se].empty())
				depart++;
			deps[f.se].push({f.fi,i});
		}
	}
	if(depart<n) {
		cout<<-1<<endl;
		return;
	}
	fill(marcost,marcost+n+1,infl);
	fr(i,1,n) {
		ans+=marcost[i]+deps[i].top().fi;
	}
	int arrived=0;
	int finans=infl;
	for(int i=1; i<=1000000; i++) {
		for(pii f:dep[k+i]) {
			if(deps[f.se].top().fi==f.fi&&deps[f.se].top().se==k+i) {
				if(deps[f.se].size()==1) {
					if(finans>=infl) {
						cout<<-1<<endl;
						return;
					} else {
						cout<<finans<<endl;
						return;
					}
				}
				ans-=deps[f.se].top().fi;
				deps[f.se].pop();
				ans+=deps[f.se].top().fi;
			}
		}
		for(pii f:arr[i]) {
			if(f.fi<marcost[f.se]) {
				ans-=marcost[f.se];
				marcost[f.se]=f.fi;
				ans+=marcost[f.se];
			}
		}
		finans=min(ans,finans);
	}
	cout<<ans<<endl;
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