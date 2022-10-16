//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
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
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int N=2e5+5;
int a[N];
int n,k;
bool compute(int ii) {
	int run=1,res=0;
	double drun=1.0;
	int tem=ii;
	for(int i=0; i<n; ) {
		if(drun>1.1e18) {
			for(int j=i; j<n; j++)
				if(a[j])
					return 1;
			return 0;
		}
		if(res+a[i]*(0.0+run)>1.1e18)
		    return 1;
		res=(res+a[i]*run);
		if(res>=k)
				return 1;
		i++;
		drun=(drun*tem)/i;
		if(drun<=1.1e18) {
			int gc=gcd(run,i);
			int ii=i/gc;
			run/=gc;
			int tmpp=tem/ii;
			run=tmpp*run;
		}
		tem++;
		trace(res,drun,run,i);
	}
	return 0;
}
void solve() {
// 	n=200005;
// 	k=1e18;
	cin>>n>>k;
	for(int i=n-1; i>=0; i--) {
		cin>>a[i];
// 		a[i]=0;
		if(a[i]>=k) {
			cout<<0<<endl;
			return;
		}
	}
	trace(compute(632455531));
	int lo=1,hi=k,mid=(lo+hi)/2;
	while(lo<hi) {
		if(compute(mid))
			hi=mid;
		else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	cout<<mid<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}