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
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
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

int le[100005],ri[100005],a[100005];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>a[i];
	fr(i,1,n) {
		le[i]=1;
		if(a[i]>a[i-1])
			le[i]=le[i-1]+1;
	}
	for(int i=n; i>0; i--) {
		ri[i]=1;
		if(a[i]>a[i+1])
			ri[i]=ri[i+1]+1;
	}
	int mm=max(*max_element(le+1, le+n+1),*max_element(ri+1,ri+n+1));
	int ans=0;
	if(mm%2==0) {
		cout<<0<<endl;
		return;
	}
	fr(i,1,n)
		if(le[i]==ri[i]&&le[i]==mm)
			ans++;
	int ans2=0;
	fr(i,1,n)
		if(le[i]==mm||mm==ri[i])
			ans2++;
	if(ans2>1)
		ans=0;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}