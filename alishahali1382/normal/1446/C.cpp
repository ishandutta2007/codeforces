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
#define get(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=200010, LOG=30;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int TR[MAXN*LOG][2], dp[MAXN*LOG], ts;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		int v=0;
		for (int j=LOG-1; ~j; j--){
			int c=get(A[i], j);
			if (!TR[v][c]) TR[v][c]=++ts;
			v=TR[v][c];
		}
	}
	for (int v=ts; ~v; v--){
		if (TR[v][0]+TR[v][1]==0) dp[v]=1;
		else{
			dp[v]=max(dp[TR[v][0]], dp[TR[v][1]]);
			if (TR[v][0] && TR[v][1]) dp[v]++;
		}
	}
	cout<<n-dp[0]<<"\n";
	
	return 0;
}