// Author: Ali Shahali
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
const int mod=1000000007;
const int N=3010;

inline void _upd(int &x, int y){ if (x<y) x=y;}

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N], last[N], prv[N];
int dp[N][N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=1; i<=n; i++) last[i]=0;
		for (int i=1; i<=n; i++){
			cin>>A[i];
			prv[i]=last[A[i]];
			last[A[i]]=i;
		}
		for (int l=n; l; l--) for (int r=l+1; r<=n; r++){
			dp[l][r]=dp[l][r-1];
			for (int i=prv[r]; i>=l; i=prv[i]) _upd(dp[l][r], dp[l][i]+dp[i+1][r-1]+1);
		}
		// debug(dp[1][n])
		cout<<n-1-dp[1][n]<<"\n";
	}
	
	return 0;
}