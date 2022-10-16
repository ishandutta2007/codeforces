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

int a[500005][2];
vector<pii> nums[1<<20];
bool used[500005];
vector<pii> star;
int mask;
void dfs(int at, int par) {
	used[at]=1;
	par^=1;
	while(nums[a[at][par]&mask].size()) {
		if(used[nums[a[at][par]&mask].back().fi]) {
			nums[a[at][par]&mask].pop_back();
		} else {
			pii temp=nums[a[at][par]&mask].back();
			nums[a[at][par]&mask].pop_back();
			dfs(temp.fi,temp.se);
		}
	}
	star.pb({at,par});
	star.pb({at,par^1});
}
void solve() {
	int n;
	cin>>n;
	fr(i,1,n) {
		cin>>a[i][0]>>a[i][1];
	}
	int ans=0;
	vector<pii> fans;
	fr(j,0,20) {
		for(int i=0; i<(1<<j); i++)
			nums[i].clear();
		memset(used,0,sizeof(used));
		mask=(1<<j)-1;
		fr(i,1,n) {
			nums[a[i][0]&mask].pb({i,0});
			nums[a[i][1]&mask].pb({i,1});
		}
		star.clear();
		dfs(1,0);
		if(sz(star)!=2*n||(a[star[0].fi][star[0].se]&mask)!=(a[star.back().fi][star.back().se]&mask))
			break;
		ans=j;
		fans=star;
	}
	cout<<ans<<endl;
	for(auto i:fans)
		cout<<(i.fi<<1|i.se)-1<<" ";
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}