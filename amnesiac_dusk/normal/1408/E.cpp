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

const int N=100005;
int ident[N];
int dsu[N];
int fpar(int i) {
	return (dsu[i]<0)?i:dsu[i]=fpar(dsu[i]);
}
bool merge(int u, int v) {
	if((u=fpar(u))!=(v=fpar(v))) {
		if(dsu[u]>dsu[v])
			swap(u,v);
		dsu[u]+=dsu[v];
		dsu[v]=u;
		return 0;
	} else
		return 1;
}
int a[N],b[N];

void solve() {
	memset(dsu,-1,sizeof(dsu));
	int n,m;
	cin>>m>>n;
	fr(i,1,m)
		cin>>a[i];
	fr(i,1,n)
		cin>>b[i];
	vector<pii> ho;
	fr(i,1,m) {
		int te;
		cin>>te;
		while(te--) {
			int te2;
			cin>>te2;
			ho.pb({i,te2});
		}
	}
	sort(all(ho),[](pii i, pii j){
		return a[i.fi]+b[i.se]>a[j.fi]+b[j.se];
	});
	int ans=0;
	for(auto i:ho) {
		if(ident[i.se]) {
			if(merge(i.fi,ident[i.se])) {
				ans+=a[i.fi]+b[i.se];
			}
		}
		else
			ident[i.se]=i.fi;
	}
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}