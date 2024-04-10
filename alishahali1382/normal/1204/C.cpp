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
const int MAXN = 110, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool A[MAXN][MAXN];
int dist[MAXN][MAXN];
int P[1000010];
int dp[1000010];
int par[1000010];
char ch;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
		cin>>ch;
		A[i][j]=ch-'0';
		if (A[i][j]) dist[i][j]=1;
		else dist[i][j]=inf;
	}
	for (int i=1; i<=n; i++) dist[i][i]=0;
	for (int k=1; k<=n; k++) for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
	cin>>m>>P[1];
	for (int i=2; i<=m; i++){
		cin>>P[i];
		dp[i]=inf;
		for (int j=1; j<=n && j<i; j++) if (dist[P[i-j]][P[i]]==j && dp[i-j]+1<dp[i]){
			//debug2(i-j, i)
			dp[i]=dp[i-j]+1;
			par[i]=i-j;
		}
	}
	vector<int> out;
	for (int tmp=m; tmp; tmp=par[tmp]) out.pb(P[tmp]);
	
	cout<<out.size()<<endl;
	reverse(all(out));
	for (int x:out) cout<<x<<' ';
	
	return 0;
}