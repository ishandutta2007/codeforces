#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
//const int mod=1000000007;
const int MAXN=4000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll dp[MAXN], ps[MAXN], sum, mod;

int Main(){
	cin>>n>>mod;
	dp[1]=1;
	sum=0;
	for (int i=1; i<=n; i++){
		ps[i]+=ps[i-1];
		dp[i]=(dp[i]+ps[i]+sum)%mod;
		for (int z=2; i*z<=n; z++){
			ps[i*z]+=dp[i];
			ps[min((i+1)*z, MAXN-1)]-=dp[i];
		}
		sum=(sum+dp[i])%mod;
	}
	ans=dp[n];
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T=1;
//	cin>>T;
	while (T--) Main();
	
	return 0;
}