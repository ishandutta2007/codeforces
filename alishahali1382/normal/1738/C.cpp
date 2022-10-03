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
const int N=105;

int n, m, k, u, v, x, y, t, a, b, ans;
bool dp[N][N][2];

int Main(){
	int c0=0, c1=0;
	cin>>n;
	while (n--){
		cin>>x;
		if (x&1) c1++;
		else c0++;
	}
	if (dp[c0][c1][0]) kill("Alice")
	else kill("Bob")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	dp[0][0][0]=1;
	for (int i=1; i<N; i++){
		dp[0][i][((i+1)/2)&1]=1;
		dp[i][0][0]=1;
	}
	for (int c0=1; c0<N; c0++){
		for (int c1=1; c1<N; c1++){
			for (int x:{0, 1}){
				int y=(c1&1)^x^1;
				dp[c0][c1][x]=(!dp[c0-1][c1][y]) | (!dp[c0][c1-1][y]);
			}
		}
	}
//	debug(dp[0][3][0])
//	
//	return 0;
	
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}