#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int MAXN = 153;

int n, k, s, x, y, t, a, b=1, ans;
int A[MAXN];
int dp[2][MAXN][MAXN*MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>s;
	s=min(s, (n+1)*(n+1)/4);
	s+=k*(k+1)/2;
	for (int j=1; j<=k; j++) for (int x=0; x<=s; x++) dp[0][j][x]=inf; 
	for (int i=1; i<=n; i++){
		cin>>A[i];
		for (int j=1; j<=n; j++){
			for (int x=0; x<=s; x++){
				dp[b][j][x]=dp[a][j][x];
				if (x) dp[b][j][x]=min(dp[b][j][x], dp[b][j][x-1]);
				if (x>=i) dp[b][j][x]=min(dp[b][j][x], dp[a][j-1][x-i] + A[i]);
			}
		}
		swap(a, b);
	}
	cout<<dp[a][k][s]<<'\n';
	
	return 0;
}