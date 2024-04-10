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
const ll infl= 0x3f3f3f3f3f3f3f3fLL;
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

vector<string> lol={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dp[2005][2005];
int s[2005];
string ans;
int n;
vi lol2;
int go(int i, int k) {
	if(~dp[i][k])
		return dp[i][k];
	if(i==n&&k==0)
		return 1;
	if(k<0||i==n)
		return 0;
	for(int j=9; j>=0; j--) {
		if((lol2[j]&s[i])==s[i]&&(go(i+1,k-__builtin_popcount(s[i]^lol2[j])))) {
			ans[i]='0'+j;
			return dp[i][k]=1;
		}
	}
	return dp[i][k]=0;
}
int tos(string s) {
	int lol=0;
	while(sz(s)) {
		lol<<=1;
		lol|=(s.back()-'0');
		s.pop_back();
	}
	return lol;
}
void solve() {
	memset(dp,-1,sizeof(dp));
	int k;
	cin>>n>>k;
	ans.resize(n);
	rep(i,0,n) {
		string te;
		cin>>te;
		s[i]=tos(te);
	}
	for(auto i:lol)
		lol2.pb(tos(i));
	if(go(0,k)) {
		cout<<ans<<endl;
	} else {
		cout<<-1<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}