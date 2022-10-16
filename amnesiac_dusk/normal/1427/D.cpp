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

int c[53];
int c2[53];
void solve() {
	int n;
	cin>>n;
	fr(i,1,n)
		cin>>c[i];
	vector<vi> ops;
	int cntr=0;
	while(!is_sorted(c+1,c+n+1)) {
		ops.pb(vi());
		vi &here=ops.back();
		vector<vi> sim;
		cntr++;
		int po=0;
		fr(i,1,n)
			if(c[i]==cntr)
				po=i;
		if(cntr&1) {
			int to=cntr-1;
			if(to)
				here.pb(to);
			int le=po-cntr+1;
			if(le)
				here.pb(le);
			if(n-le-to)
				here.pb(n-le-to);
		} else {
			int latom=cntr-2;
			if(latom)
				here.pb(latom);
			here.pb(1);
			if(n-po-latom)
				here.pb(n-po-latom);
			if(n-latom-1-here.back())
				here.pb(n-latom-1-here.back());
			reverse(all(here));
		}
//		trace(here);
		int troll=0;
		for(int i:here) {
			sim.pb(vi());
			while(i--) {
				troll++;
				sim.back().pb(troll);
			}
		}
		reverse(all(sim));
		int cntr2=1;
		fr(i,1,n)
			c2[i]=c[i];
		for(auto i:sim)
			for(auto j:i)
				c[cntr2++]=c2[j];
//		fr(i,1,n)
//			cout<<c[i]<<" ";
//		cout<<endl;
		if(ops.back().size()==1)
			ops.pop_back();
	}
	cout<<sz(ops)<<endl;
	for(auto i:ops) {
		cout<<i.size();
		for(auto j:i)
			cout<<" "<<j;
		cout<<endl;
	}
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