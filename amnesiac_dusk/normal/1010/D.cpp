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
//#define int long long
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

signed dp[21][1000005];
bool dp2[21][2][1000005];
int def[1000005];
int par[1000005];
int type[1000005];
pii gra[1000005];
void dfs(int at) {
	if(type[at]==0)
		return;
	dfs(gra[at].fi);
	dfs(gra[at].se);
	if(type[at]==1)
		def[at]=def[gra[at].fi]&def[gra[at].se];
	else if(type[at]==2)
		def[at]=def[gra[at].fi]|def[gra[at].se];
	else if(type[at]==3)
		def[at]=def[gra[at].fi]^def[gra[at].se];
	else
		def[at]=!def[gra[at].fi];
}
void solve() {
	int n;
	cin>>n;
	map<string,int> hulol;
	vector<string> types={"IN","AND", "OR", "XOR", "NOT"};
	rep(i,0,sz(types))
		hulol[types[i]]=i;
	fr(i,1,n) {
		string te;
		cin>>te;
		type[i]=hulol[te];
		if(type[i]==0) {
			cin>>def[i];
		} else if(type[i]==4) {
			int te;
			cin>>te;
			dp[0][te]=i;
			gra[i].fi=te;
		} else {
			int te1,te2;
			cin>>te1>>te2;
			dp[0][te1]=i;
			dp[0][te2]=i;
			gra[i].fi=te1;
			gra[i].se=te2;
		}
	}
	dfs(1);
	fr(i,1,n) {
		if(i==1) {
			dp2[0][0][i]=0;
			dp2[0][1][i]=1;
		}
		if(type[dp[0][i]]==1) {
			dp2[0][0][i]=0;
			dp2[0][1][i]=def[gra[dp[0][i]].fi]+def[gra[dp[0][i]].se]-def[i];
		}
		if(type[dp[0][i]]==2) {
			dp2[0][0][i]=def[gra[dp[0][i]].fi]+def[gra[dp[0][i]].se]-def[i];
			dp2[0][1][i]=1;
		}
		if(type[dp[0][i]]==3) {
			dp2[0][0][i]=def[dp[0][i]]^def[i];
			dp2[0][1][i]=def[dp[0][i]]^def[i]^1;
		}
		if(type[dp[0][i]]==4) {
			dp2[0][0][i]=1;
			dp2[0][1][i]=0;
		}
	}
	dp[0][1]=1;
	fr(j,1,20)
		fr(i,1,n) {
			dp[j][i]=dp[j-1][dp[j-1][i]];
			rep(k,0,2)
				dp2[j][k][i]=dp2[j-1][dp2[j-1][k][i]][dp[j-1][i]];
		}
	fr(i,1,n)
		if(type[i]==0)
			cout<<dp2[20][def[i]^1][i];
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}