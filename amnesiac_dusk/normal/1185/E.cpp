//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=1e9;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(ll a, ll b) {
	int res=1;
	a%=mod;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

const int N=2005;
string a[N];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
		a[i]='.'+a[i];
	}
	char maxi='a'-1;
	fr(i,1,n)
		fr(j,1,m)
			maxi=max(a[i][j],maxi);
	bool valid=0;
	vector<pair<pii,pii>> ans;
	for(int ch=maxi; ch>='a'; ch--) {
		vector<pii> th;
		fr(i,1,n) {
			fr(j,1,m) {
				if(a[i][j]==ch)
					th.pb({i,j});
			}
		}
		bool ron=0,con=0;
		int ro,co;
		if(th.empty()) {
			ro=ans.back().fi.fi;
			co=ans.back().fi.se;
			ans.pb({{ro,co},{ro,co}});
			continue;
		} else {
			ro=th[0].fi;
			co=th[0].se;
			for(auto &i:th) {
				if(i.fi!=ro)
					ron=1;
				if(i.se!=co)
					con=1;
			}
			if(ron&&con) {
				cout<<"NO"<<endl;
				return;
			} else if(ron) {
				int mi=infl,ma=0;
				for(auto &i:th) {
					mi=min(i.fi,mi);
					ma=max(i.fi,ma);
				}
				for(int i=mi; i<=ma; i++) {
					if(a[i][co]=='.'||a[i][co]<ch) {
						cout<<"NO"<<endl;
						return;
					}
				}
				ans.pb({{mi,co},{ma,co}});
			} else {
				int mi=infl,ma=0;
				for(auto &i:th) {
					mi=min(i.se,mi);
					ma=max(i.se,ma);
				}
				for(int i=mi; i<=ma; i++) {
					if(a[ro][i]=='.'||a[ro][i]<ch) {
						cout<<"NO"<<endl;
						return;
					}
				}
				ans.pb({{ro,mi},{ro,ma}});
			}
		}
	}
	cout<<"YES"<<endl;
	cout<<sz(ans)<<endl;
	reverse(all(ans));
	for(auto i:ans) {
		cout<<i.fi.fi<<" "<<i.fi.se<<" "<<i.se.fi<<" "<<i.se.se<<endl;
	}
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}