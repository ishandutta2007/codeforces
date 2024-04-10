#pragma GCC optimize("Ofast")
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
const int mod=1000000007;
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

const int N=1e5+5;
int d[N],a[N];
int lt[N];
int n;
bool bs(int lim) {
	memset(lt,0,sizeof(lt));
	for(int i=1; i<=lim; i++)
		if(d[i]) {
			lt[d[i]]=i;
		}
	vector<pii> edf;
	fr(i,1,n) {
		if(lt[i]==0)
			return 0;
		edf.pb({lt[i],a[i]});
	}
	sort(all(edf),[](auto &i,auto &j){
		return i.fi<j.fi;
	});
	int ans=0;
	for(auto &i:edf) {
//		cout<<lim<<" "<<i.fi<<" "<<i.se<<endl;
		ans+=i.se;
		if(ans>i.fi)
			return 0;
	}
	return 1;
}
void solve() {
	int m;
	cin>>m>>n;
	fr(i,1,m) {
		cin>>d[i];
	}
	fr(i,1,n) {
		cin>>a[i];
		a[i]++;
	}
	int lo=n,hi=m+1,mid=(lo+hi)/2;
	while(lo<hi) {
		if(bs(mid)) {
			hi=mid;
		} else {
			lo=mid+1;
		}
		mid=(lo+hi)/2;
	}
	if(mid<=m)
		cout<<mid<<endl;
	else
		cout<<-1<<endl;
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
	cerr<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}