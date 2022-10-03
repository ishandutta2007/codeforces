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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=300010, N=15;

int n, m, p, u, v, x, y, t, a, b, ans;
ll A[MAXN], out;
int B[MAXN], P[MAXN], dp[1<<N];
string S;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Solve(ll X){
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=n; i++){
		int pos=0;
		B[i]=0;
		for (int j=0; j<m; j++) if (X&(1ll<<j)){
			if (A[i]&(1ll<<j)) B[i]|=(1<<pos);
			pos++;
		}
//		debug2(i, B[i])
		dp[B[i]]++;
	}
	for (int j=0; j<N; j++) for (int i=0; i<(1<<N); i++) if (i&(1<<j)) dp[i^(1<<j)]+=dp[i];
	int ans=0, t=0;
	for (int i=0; i<(1<<N); i++) if (dp[i]>=(n+1)/2){
		int tt=__builtin_popcount(i);
		if (tt>t){
			t=tt;
			ans=i;
		}
	}
//	debug(ans)
	ll res=0;
	int pos=0;
	for (int j=0; j<m; j++) if (X&(1ll<<j)){
		if (ans&(1<<pos)) res|=(1ll<<j);
		pos++;
	}
//	debug2(ans, res)
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>p;
	for (int i=1; i<=n; i++){
		cin>>S;
		for (int j=0; j<m; j++) if (S[j]=='1') A[i]|=(1ll<<j);
		P[i]=i;
	}
//	debug(Solve(5))
//	return 0;
	shuffle(P+1, P+n+1, rng);
	for (int i=1; i<=min(n, 50); i++){
		ll x=Solve(A[P[i]]), y=__builtin_popcountll(x);
		if (y>ans){
			out=x;
			ans=y;
		}
	}
//	debug2(ans, out)
	for (int i=0; i<m; i++) cout<<((out>>i)&1);
	cout<<"\n";
	
	return 0;
}