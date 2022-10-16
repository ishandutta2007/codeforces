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

int dp[1000005];
int dp2[1000005];
int dp3[1000005];
int lat[1000005],lat2[1000005];
void holve(int n, string s, int dp[], int dp2[], int k, int lat[]) {
	dp[0]=1;
	int last=0,ways=1;
	fr(i,1,n) {
		if(i-k>last) {
			ways-=dp[last];
			last++;
		}
		if(s[i]=='W') {
			dp[i]=ways;
			last=i;
		} else if(s[i]=='X') {
			dp[i]=ways;
			ways=(ways*2);
		}
		ways%=mod;
	}
	last=0,ways=1;
	fr(i,1,n) {
		if(i-k>=last) {
			ways-=dp[last];
			last++;
		}
		if(s[i]=='W') {
			ways=dp[i];
			last=i;
		} else if(s[i]=='X')
			ways=(ways+dp[i]);
		ways%=mod;
		dp2[i]=ways;
	}
	int lol=1;
	int lol2=0;
	fr(i,1,n) {
		if(s[i]=='X') {
			lol=(lol*2)%mod;
			lol2=(lol2*2)%mod;
		}
//		trace(i,lol,dp2[i],lol2);
		lat[i]=(lol-dp2[i]-lol2)%mod;
		lol2=(lol2+lat[i])%mod;
	}
}
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s='W'+s+'B';
	holve(n,s,dp,dp2,k,lat);
	reverse(all(s));
	for(char &i:s)
		if(i=='W')
			i='B';
		else if(i=='B')
			i='W';
	memset(dp,0,sizeof(dp));
	holve(n,s,dp,dp3,k,lat2);
	int su=0,ans=0;
	reverse(lat2+1,lat2+n+1);
	reverse(all(s));
	for(char &i:s)
		if(i=='W')
			i='B';
		else if(i=='B')
			i='W';
	fr(i,1,n) {
		if(s[i]=='X')
			su=(su*2)%mod;
		su+=lat[i];
		su%=mod;
		ans=(ans+su*lat2[i+1])%mod;
	}
	if(ans<0)
    	ans+=mod;
	cout<<ans<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	// cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}