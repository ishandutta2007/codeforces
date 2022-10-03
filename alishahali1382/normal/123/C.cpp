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
const ll INF=1000000000000001000LL;
const int mod = 1000000007;
const int MAXN = 110, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN*2];
int mn[MAXN*2];
int C[MAXN][MAXN];
ll dp[MAXN*2][MAXN];
vector<int> vec;

void do_dp(){
	dp[0][0]=1;
	for (int i=1; i<=n+m-1; i++) for (int j=0; j<=n+m; j++){
		if (A[i]==1) dp[i][j]=(!j?0:dp[i-1][j-1]);
		else if (A[i]==-1) dp[i][j]=dp[i-1][j+1];
		else dp[i][j]=min(INF, (ll)dp[i-1][j+1] + (j?dp[i-1][j-1]:0));
	}
}

bool cmp(int i, int j){ return mn[i]<mn[j];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(mn, 63, sizeof(mn));
	cin>>n>>m>>k;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>C[i][j], mn[i+j-1]=min(mn[i+j-1], C[i][j]);
	for (int i=1; i<=n+m-1; i++) vec.pb(i);
	
	sort(all(vec), cmp);
	do_dp();
	
	for (int pos:vec){
		A[pos]=1;
		do_dp();
		if (dp[n+m-1][0]<k){
			k-=dp[n+m-1][0];
			A[pos]=-1;
		}
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		if (A[i+j-1]==1) cout<<'(';
		else cout<<')';
		if (j==m) cout<<'\n';
	}
	
	return 0;
}
/*
4 3 1
1 4 6
10 12 2
7 8 5
3 11 9
*/