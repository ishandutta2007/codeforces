/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 */
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
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
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

int dsu[2][200005];
int fpar(int c,int i) {
	return (dsu[c][i]<0)?i:dsu[c][i]=fpar(c,dsu[c][i]);
}
void merge(int c,int i, int j) {
	if((i=fpar(c,i))!=(j=fpar(c,j))) {
		if(dsu[c][i]>dsu[c][j])
			swap(i,j);
		dsu[c][i]+=dsu[c][j];
		dsu[c][j]=i;
	}
}
void solve() {
	vector<pii> diff;
	int n;
	cin>>n;
	fill(dsu[0],dsu[0]+n+1,-1);
	fill(dsu[1],dsu[1]+n+1,-1);
	fr(i,2,n) {
		int u,v,c;
		cin>>u>>v>>c;
		merge(c,u,v);
	}
	int ans=0;
	fr(i,1,n) {
		if(dsu[0][i]<0) {
			ans+=(dsu[0][i]*(dsu[0][i]+1));
		}
		int po1=fpar(0,i);
		int po2=fpar(1,i);
		ans+=(dsu[0][po1]+1)*(dsu[1][po2]+1);
		if(dsu[1][i]<0) {
			ans+=(dsu[1][i]*(dsu[1][i]+1));
		}
	}
	cout<<ans<<endl;

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();

#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}