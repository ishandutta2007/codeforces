#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
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
vector<vi> anser;
int simulate(string s) {
	int ans=0;
	while(1) {
		bool done=1;
		anser.pb(vi());
		for(int i=sz(s)-2; i>=0; i--) {
			if(s[i]=='R'&&s[i+1]=='L') {
				done=0;
				swap(s[i],s[i+1]);
				anser.back().pb(i+1);
				i--;
			}
		}
		if(done)
			return ans;
		ans++;
	}
}
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ma=0,cnt=0;
	for(int i=0; i<n; i++) {
		if(s[i]=='L') {
			ma+=cnt;
		} else
			cnt++;
	}
	int mi=simulate(s);
	if(k<mi||k>ma) {
		cout<<-1<<endl;
		return;
	} else {
		int lat=0;
		vi anser2;
		anser.pop_back();
		trace(anser);
		reverse(all(anser));
		while(sz(anser)+sz(anser2)<k) {
			anser2.pb(anser.back().back());
			anser.back().pop_back();
			if(anser.back().empty())
				anser.pop_back();
		}
		reverse(all(anser));
		for(int i:anser2) {
			cout<<1<<" "<<i<<endl;
		}
		for(auto i:anser) {
			cout<<sz(i);
			for(auto j:i) {
				cout<<" "<<j;
			}
			cout<<endl;
		}

	}
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