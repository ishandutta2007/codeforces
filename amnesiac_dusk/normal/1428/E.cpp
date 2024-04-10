#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
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
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=998244353;
//const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
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

int a[100005],pc[100005],dif[100005];
int gval(int n, int k) {
	if(n<k)
		return infl;
	int sz=n/k,pp1=n%k;
	return pp1*(sz+1)*(sz+1)+(k-pp1)*sz*sz;
}
void solve() {
	int n,k;
	cin>>n>>k;
	int ans=0;
	fr(i,1,n) {
		cin>>a[i];
		ans+=a[i]*a[i];
		pc[i]=1;
	}
	int toll=k-n;
	priority_queue<pii> pool;
	fr(i,1,n) {
		dif[i]=gval(a[i],1)-gval(a[i],2);
		pool.push({dif[i],i});
	}
	while(toll>0) {
		pii to=pool.top();
		ans-=to.fi;
		toll--;
		pool.pop();
		pc[to.se]++;
		pool.push({gval(a[to.se],pc[to.se])-gval(a[to.se],pc[to.se]+1),to.se});
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}