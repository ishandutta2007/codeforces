#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 5000010, seed=10007;

ll n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN];
ll tav[MAXN];
ll hl[MAXN];
ll hr[MAXN];
string s;

ll gethl(int l, int r){
	ll res=(hl[r]-hl[l-1]*tav[r-l+1])%mod;
	return (res+mod)%mod;
}
ll gethr(int l, int r){
	ll res=(hr[l]-hr[r+1]*tav[r-l+1])%mod;
	return (res+mod)%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*seed%mod;
	
	cin>>s;
	n=s.size();
	s=" "+s;
	for (int i=1; i<=n; i++) hl[i]=(hl[i-1]*seed+s[i])%mod;
	for (int i=n; i; i--) hr[i]=(hr[i+1]*seed+s[i])%mod;
	
	for (int i=1; i<=n; i++){
		int mid=(i+1)/2;
		int a=mid, b=mid+1;
		if (i&1) a--;
		if (gethl(1, a)!=gethr(b, i)) continue ;
		dp[i]=dp[a]+1;
		ans+=dp[i];
	}
	//for (int i=1; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	cout<<ans<<'\n';
	
	return 0;
}