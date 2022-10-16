#pragma GCC optimze("Ofast")
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

const int N=35;
int a[200005];
int gauss[N];
int cntr=0;
void go(int n) {
	for(int i=34; i>=0; i--)
		if(n&(1LL<<i)) {
			if(gauss[i]==0) {
				gauss[i]=n;
				cntr++;
				break;
			} else
				n^=gauss[i];
		}
}
int ans[36];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,n) {
		cin>>a[i];
		go(a[i]);
	}
	for(int i=34; i>=0; i--)
		for(int j=34; j>i; j--)
			if(gauss[i]&&(gauss[j]&(1LL<<i)))
				gauss[j]^=gauss[i];
	if(cntr<=20) {
		vi ind;
		rep(i,0,35) {
			if(gauss[i])
				ind.pb(gauss[i]);
		}
		for(int i=0; i<(1<<sz(ind)); i++) {
			int te=0;
			for(int j=0; j<sz(ind); j++)
				if(i&(1LL<<j))
					te^=ind[j];
			ans[__builtin_popcountll(te)]++;
		}
	} else {
		vi ind;
		rep(i,0,35) {
			if(gauss[i])
				ind.pb(gauss[i]^(1LL<<i));
		}
		map<pii,int> lol;
		lol[{0,0}]=1;
		for(int i:ind) {
			map<pii,int> lol2=lol;
			for(auto j:lol) {
				lol2[{j.fi.fi^i,j.fi.se+1}]+=j.se;
				lol2[{j.fi.fi^i,j.fi.se+1}]%=mod;
			}
			lol2.swap(lol);
		}
		for(auto i:lol) {
			ans[__builtin_popcountll(i.fi.fi)+i.fi.se]+=i.se;
			ans[__builtin_popcountll(i.fi.fi)+i.fi.se]%=mod;
		}
	}
	fr(i,0,m)
		cout<<(ans[i]*powm(2,n-cntr))%mod<<" ";
	cout<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}