/*
sekai no hate sae bokura wa shiranai
kanashi mazu ikiru sube mo mottenai
mezasu kono saki ni matteru yuuki
sore wo te ni shitara owaru yume wo mita
*/
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
//const int mod=998244353;
int mod=1000000007;
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

int cntr[26];
void solve() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	if(k==n) {
		int ans=0;
		rep(i,0,sz(s)/2)
			if(s[i]!=s[sz(s)-i-1])
				ans++;
		cout<<ans<<endl;
	} else {
		int cost=0;
		if(k&1) {
			memset(cntr,0,sizeof(cntr));
			for(int i=k/2; i<n; i+=k)
				cntr[s[i]-'a']++;
			cost+=accumulate(cntr,cntr+26,0LL)-(*max_element(cntr,cntr+26));
		}
		rep(i,0,k/2) {
			memset(cntr,0,sizeof(cntr));
			for(int j=i; j<n; j+=k)
				cntr[s[j]-'a']++;
			for(int j=k-i-1; j<n; j+=k)
				cntr[s[j]-'a']++;
			cost+=accumulate(cntr,cntr+26,0LL)-(*max_element(cntr,cntr+26));
		}
		cout<<cost<<endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(12);
	int t=1;
	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}