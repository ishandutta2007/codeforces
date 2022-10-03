#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 2000010, LOG=21;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
pii dp[MAXN];

pii f(pii a, pii b){
	if (a.first<b.first) swap(a.first, b.first);
	a.second=max(a.second, max(b.first, b.second));
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], dp[A[i]]=f(dp[A[i]], {i, 0});
	for (int j=0; j<LOG; j++) for (int mask=0; mask<MAXN; mask++) if (mask&(1<<j)) dp[mask^(1<<j)]=f(dp[mask^(1<<j)], dp[mask]);
		
	for (int i=1; i<=n-2; i++){
		int x=0;
		for (int j=LOG-1; j>=0; j--){
			if (A[i]&(1<<j)) continue ;
			if (dp[x|(1<<j)].second<=i) continue ;
			x|=(1<<j);
		}
		ans=max(ans, A[i]|x);
	}
	cout<<ans<<'\n';
	
	
	return 0;
}