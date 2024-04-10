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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll T[MAXN], X[MAXN];
ll dp[MAXN], pd[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>T[i]>>X[i];
	dp[1]=abs(X[1]);
	if (dp[1]>T[1]) dp[1]=inf;
	for (int i=2; i<=n; i++){
		dp[i]=dp[i-1]+abs(X[i]-X[i-1]);
		if (pd[i-1]) dp[i]=min(dp[i], T[i-2]+abs(X[i-2]-X[i]));
		dp[i]=max(dp[i], T[i-1]);
		if (dp[i]>T[i]) dp[i]=inf;
		int j=i-1;
		while (j){
			if (max(dp[j-1]+abs(X[i]-X[j-1]), T[j-1])+abs(X[i]-X[j])<=T[j]) pd[i]=1;
			if (pd[j-1] && max(T[j-2]+abs(X[i]-X[j-2]), T[j-1])+abs(X[i]-X[j])<=T[j]) pd[i]=1;
			if (j==1 || T[j-1]+abs(X[j]-X[j-1])>T[j]) break ;
			j--;
		}
	}
	if (dp[n]<=T[n] || pd[n]) kill("YES")
	kill("NO")
	
	return 0;
}