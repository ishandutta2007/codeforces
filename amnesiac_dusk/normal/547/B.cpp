#pragma GCC optimize("Ofast")
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b, int mod) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


int ans[200005];
int dsu[200005];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
void merge(int i, int j) {
	if((i=fpar(i))!=(j=fpar(j))) {
		if(dsu[i]>dsu[j])
			swap(i,j);
		dsu[i]+=dsu[j];
		dsu[j]=i;
	}
}
bool active[200005];
void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n;
	cin>>n;
	vector<pii> lol;
	fr(i,1,n) {
		int te;
		cin>>te;
		lol.pb({te,i});
	}
	sort(all(lol));
	reverse(all(lol));
	for(auto i:lol) {
		active[i.se]=1;
		if(active[i.se+1])
			merge(i.se,i.se+1);
		if(active[i.se-1])
			merge(i.se,i.se-1);
		int sz=-dsu[fpar(i.se)];
		ans[sz]=max(ans[sz],i.fi);
	}
	for(int i=n-1; i>0; i--) {
		ans[i]=max(ans[i],ans[i+1]);
	}
	fr(i,1,n)
		cout<<ans[i]<<" ";



}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(20);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}