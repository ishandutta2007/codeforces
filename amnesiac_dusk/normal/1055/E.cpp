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
const int mod=998244353;
//const int mod=1000000007;
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


int a[1505],b[1505];
int dp[1505][1505];
int segs[1505];
int pref[1505],n,m,k;
int check(int mid) {
	memset(dp,0,sizeof(dp));
	memset(pref,0,sizeof(pref));
	fr(i,1,n) {
		if(a[i]<=mid)
			pref[i]=1;
		pref[i]+=pref[i-1];
	}
	fr(i,0,n-1) {
		fr(j,0,m-1)
			dp[segs[i+1]][j+1]=max(dp[segs[i+1]][j+1],dp[i][j]+pref[segs[i+1]]-pref[i]);
		fr(j,0,m)
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
	}
	int ans=0;
	fr(i,0,m)
		ans=max(ans,dp[n][i]);
	return ans;
}
void solve() {
	int s;
	cin>>n>>s>>m>>k;
	fr(i,1,n) {
		cin>>a[i];
		b[i]=a[i];
	}
	fr(i,1,s) {
		int l,r;
		cin>>l>>r;
		segs[l]=max(segs[l],r);
	}
	fr(i,1,n) {
		segs[i]=max(segs[i-1],segs[i]);
	}
	sort(b+1,b+n+1);
	int lo=k,hi=n+1,mid=(lo+hi)/2;
	while(lo<hi) {
		if(check(b[mid])>=k) {
			hi=mid;
		} else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	if(mid!=n+1)
		cout<<b[mid]<<endl;
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
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}