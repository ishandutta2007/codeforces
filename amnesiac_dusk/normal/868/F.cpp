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

int a[200005],f[200005];
vector<long long> dp_before,dp_cur;
// compute dp_cur[l], ... dp_cur[r] (inclusive)
int cl,cr,cost;
void compute(int l, int r, int optl, int optr) {
	if(l>r)
		return;
	int mid=(l+r)>>1;
	pair<long long, int> best={infl,-1};
	int lol=min(mid,optr);
// bring [cl,cr]->[lol+1,mid]
	while(cr>mid) {
		f[a[cr]]--;
		cost-=f[a[cr]];
		cr--;
	}
	while(cr<mid) {
		cr++;
		cost+=f[a[cr]];
		f[a[cr]]++;
	}
	while(cl>lol+1) {
		cl--;
		cost+=f[a[cl]];
		f[a[cl]]++;
	}
	while(cl<lol+1) {
		f[a[cl]]--;
		cost-=f[a[cl]];
		cl++;
	}
	for(int k=lol;k>=optl;k--) {
		best=min(best,{dp_before[k]+cost,k});
		cost+=f[a[k]];
		f[a[k]]++;
		cl--;
	}
	dp_cur[mid]=best.first;
	int opt=best.second;
	compute(l,mid-1,optl,opt);
	compute(mid+1,r,opt,optr);
}
void solve() {
	int n,k;
	cin>>n>>k;
	fr(i,1,n) {
		cin>>a[i];
	}
	dp_before.resize(n+1,infl);
	dp_cur.resize(n+1,infl);
	int cost=0;
	fr(i,1,n) {
		cost+=f[a[i]];
		f[a[i]]++;
		dp_before[i]=cost;
	}
	fr(i,1,n) {
		f[a[i]]--;
	}
	cl=1,cr=0;
	fr(i,1,k-1) {
		compute(1, n, 1, n);
		dp_before.swap(dp_cur);
//		fr(i,1,n) {
//			cout<<dp_before[i]<<" ";
//		}
//		cout<<endl;
//		fr(i,1,n) {
//			cout<<f[i]<<" ";
//		}
//		cout<<endl;
//		cout<<endl;
	}
	cout<<dp_before[n]<<endl;
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