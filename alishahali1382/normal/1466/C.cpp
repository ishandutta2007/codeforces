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
const int MAXN=300010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN][2][2];
string S;

inline void upd(int &x, int y){ if (x>y) x=y;}

int Solve(){
	cin>>S;
	n=S.size();
	dp[0][0][1]=dp[0][1][0]=dp[0][0][0]=inf;
	dp[0][1][1]=0;
	for (int i=1; i<=n; i++){
		memset(dp[i], 63, sizeof(dp[i]));
		int c=S[i-1]-'a';
		for (int x:{0, 1}) for (int y:{0, 1}) if (dp[i-1][x][y]<inf){
			int tmp=0;
			if (!x && S[i-3]==S[i-1]) tmp=1;
			if (!y && S[i-2]==S[i-1]) tmp=1;
			if (!tmp) upd(dp[i][y][0], dp[i-1][x][y]);
			upd(dp[i][y][1], dp[i-1][x][y]+1);
		}
	}
//	debug(dp[3][0][1])
//	debug(dp[2][0][0])
	ans=min(min(dp[n][0][0], dp[n][0][1]), min(dp[n][1][0], dp[n][1][1]));
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}
/*
1
babba


*/