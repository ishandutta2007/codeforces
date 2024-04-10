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
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN];
bitset<10100> dp;

int Main(){
	ll sum=0;
	ll val=0;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], val+=A[i]*A[i], sum+=A[i];
	for (int i=1; i<=n; i++) cin>>B[i], val+=B[i]*B[i], sum+=B[i];
	
	dp.reset();
	dp.set(0);
	for (int i=1; i<=n; i++)
		dp=(dp<<A[i])|(dp<<B[i]);
	
	ans=INF;
	
//	debug(val)
	
	for (ll i=0; i<10100; i++) if (dp[i]){
		ll j=sum-i;
		ans=min(ans, i*i+j*j);
	}
	kill(ans+(n-2)*val)
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--) Main();
	
	
	return 0;
}
/*
1
4
3 6 6 6
2 7 4 1

*/