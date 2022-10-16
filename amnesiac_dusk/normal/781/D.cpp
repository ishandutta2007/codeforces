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

vector<bool> seq={0};
bitset<505> here,here2;
bitset<505> pool[60][2][505];
void solve() {
	int n,m;
	cin>>n>>m;
	fr(i,1,m) {
		int u,v,t;
		cin>>u>>v>>t;
		pool[0][t][u][v]=1;
	}
	rep(i,1,60)
		fr(j,1,n)
			rep(l,0,2) {
				int k=pool[i-1][l][j]._Find_first();
				while(k!=sz(pool[i-1][l][j])) {
					pool[i][l][j]|=pool[i-1][l^1][k];
					k=pool[i-1][l][j]._Find_next(k);
				}
			}
	here[1]=1;
	int kul=0,ans=0;
	for(int i=59; i>=0; i--) {
		int at=here._Find_first();
		while(at!=sz(here)) {
			here2|=pool[i][kul][at];
			at=here._Find_next(at);
		}
		if(here2.count()) {
			kul^=1;
			ans|=(1LL<<i);
			here=here2;
			here2.reset();
		}
	}
	if(ans>1000000000000000000LL) {
		cout<<-1<<endl;
	} else
		cout<<ans<<endl;
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