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
const int MAXN = 1000010, LOG=21;

ll n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN][LOG][2];

inline ll f(int a, int b){
	int res=1;
	if (b) res=3;
	return res<<a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	int x1=log2(n), x2=log2(n/3)+1;
	dp[1][x1][0]=1;
	if (x1==x2) dp[1][x2-1][1]=1;
	for (int i=2; i<=n; i++){
		for (int a=0; a<LOG; a++) for (int b=0; b<2; b++){
			ll tmp=1ll*dp[i-1][a][b]*max(n/f(a, b)-(i-1), 0ll);
			if (a<LOG) tmp+=1ll*dp[i-1][a+1][b]*(n/f(a, b)-n/f(a+1, b));
			if (b<2) tmp+=1ll*dp[i-1][a][b+1]*(n/f(a, b)-n/f(a, b+1));
			tmp%=mod;
			//if (tmp<0) tmp+=mod;
			dp[i][a][b]=tmp;
		}
	}
	cout<<dp[n][0][0]<<'\n';
	
	return 0;
}