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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN];
int dp[MAXN];
int mx[MAXN][2];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=2; i<=n+1; i++){
		cin>>par[i];
		int v=i;
		dp[v]=1;
		while (v!=1){
			if (dp[mx[par[v]][0]]<dp[v]){
				swap(mx[par[v]][0], mx[par[v]][1]);
				mx[par[v]][0]=v;
			}
			else if (v!=mx[par[v]][0] && dp[mx[par[v]][1]]<dp[v]){
				mx[par[v]][1]=v;
			}
			
			v=par[v];
			int mx1=mx[v][0], mx2=mx[v][1], tmp=max(dp[mx1], dp[mx2]+1);
			if (dp[v]==tmp) break ;
			//debug2(i, v)
			dp[v]=tmp;
		}
		cout<<dp[mx[1][0]]<<' ';
	}
	
	
	return 0;
}
/*
5
1 1 1 3 4

*/