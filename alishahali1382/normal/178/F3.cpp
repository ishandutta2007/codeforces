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
const int MAXN = 2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
string S[MAXN];
int lcp[MAXN];
int dp[MAXN][MAXN], N=1;

int solve(int l, int r){
	if (l==r) return 0;
	int id=N++, mid=l;
	for (int i=l+1; i<r; i++) if (lcp[i]<lcp[mid]) mid=i;
	int L=solve(l, mid), sl=mid-l+1;
	int R=solve(mid+1, r), sr=r-mid;
	for (int i=0; i<=sl; i++) for (int j=0; j<=sr; j++) dp[id][i+j]=max(dp[id][i+j], dp[L][i] + dp[R][j] + i*j*lcp[mid]);
	return id;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>S[i];
	sort(S+1, S+n+1);
	for (int i=1; i<n; i++) while (lcp[i]<min(S[i].size(), S[i+1].size()) && S[i][lcp[i]]==S[i+1][lcp[i]]) lcp[i]++;
	
	solve(1, n);
	cout<<dp[1][k]<<'\n';
	
	return 0;
}