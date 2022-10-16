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
typedef double f80;
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


string pref[205],suf[205];
bitset<1024> avl[205][10];
int sto(string tol) {
	int ans=0;
	for(int i=0; i<sz(tol); i++) {
		ans<<=1;
		if(tol[i]=='1')
			ans|=1;
	}
	return ans;
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		string te;
		cin>>te;
		if(sz(te)>9) {
			pref[i]=te.substr(0, 9);
			suf[i]=te.substr(sz(te)-9);
		} else {
			pref[i]=te;
			suf[i]=te;
		}
		for(int j=1; j<10; j++)
			for(int k=0; k+j<=sz(te); k++)
				avl[i][j][sto(te.substr(k,j))]=1;
	}
	int q;
	cin>>q;
	fr(i,n+1,n+q) {
		int a,b;
		cin>>a>>b;
		for(int j=1; j<10; j++) {
			avl[i][j]|=avl[a][j];
			avl[i][j]|=avl[b][j];
		}
		string te=suf[a]+pref[b];
		pref[i]=pref[a];
		if(sz(pref[i])<9)
			pref[i]+=pref[b];
		if(sz(pref[i])>9)
			pref[i]=pref[i].substr(0, 9);
		suf[i]=suf[b];
		if(sz(suf[i])<9)
			suf[i]=suf[a]+suf[b];
		if(sz(suf[i])>9)
			suf[i]=suf[i].substr(sz(suf[i])-9);
		for(int j=1; j<10; j++)
			for(int k=0; k+j<=sz(te); k++)
				avl[i][j][sto(te.substr(k,j))]=1;
		int ans=0;
		for(int j=1; j<10; j++) {
			if(avl[i][j].count()==(1<<j)) {
				ans=j;
			}
		}
		trace(te);
		cout<<ans<<endl;
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