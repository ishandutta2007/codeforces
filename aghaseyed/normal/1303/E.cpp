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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 410, LOG=20;

int n, m, k, u, v, x, y, t, ans;
int nxt[MAXN][26];
int dp[MAXN][MAXN];
string S, T, T1, T2;

bool check(){
	m=T1.size(), k=T2.size();
	T1="."+T1;
	T2="."+T2;
	dp[0][0]=-1;
	for (int i=0; i<=m; i++) for (int j=0; j<=k; j++) if (i || j){
		dp[i][j]=inf;
		if (i && dp[i-1][j]<n) dp[i][j]=min(dp[i][j], nxt[dp[i-1][j]+1][T1[i]-'a']);
		if (j && dp[i][j-1]<n) dp[i][j]=min(dp[i][j], nxt[dp[i][j-1]+1][T2[j]-'a']);
	}
	return dp[m][k]<n;
}

int solve(){
	cin>>S>>T;
	n=S.size();
	//S="."+S;
	memset(nxt[n], 63, sizeof(nxt[n]));
	for (int i=n-1; ~i; i--){
		memcpy(nxt[i], nxt[i+1], sizeof(nxt[i]));
		nxt[i][S[i]-'a']=i;
	}
	for (int i=0; i<T.size(); i++){
		T1=T.substr(0, i);
		T2=T.substr(i, T.size());
		if (check()) kill("YES")
	}
	kill("NO")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Test;
	cin>>Test;
	while (Test--) solve();
	
	return 0;
}
/*
1
xyz
x

*/