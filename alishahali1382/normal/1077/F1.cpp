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
const int MAXN = 5010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans=-1;
int A[MAXN];
ll dp[MAXN][MAXN];
deque<int> dq;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -63, sizeof(dp));
	cin>>n>>k>>x;
	for (int i=1; i<=n; i++) cin>>A[i];
	//for (int i=0; i<MAXN; i++) dp[0][i]=0;
	dp[0][0]=0;
	for (int j=1; j<=x; j++){
		for (int i=0; i<=n; i++){
			//pop(dp[j-1][i-k])
			while (!dq.empty() && dq.back()<i-k) dq.pop_back();
			
			if (dq.size()) dp[j][i]=dp[j-1][dq.back()]+A[i];
			
			//push(dp[j-1][i])
			while (!dq.empty() && dp[j-1][dq.front()]<dp[j-1][i]) dq.pop_front();
			dq.push_front(i);
		}
		dq.clear();
	}/*
	cerr<<endl;
	debug(dp[1][0])
	debug(dp[1][1])
	debug(dp[1][2])
	cerr<<endl;
	debug(dp[2][1])
	debug(dp[2][2])
	debug(dp[2][3])
	cerr<<endl;
	debug(dp[3][1])
	debug(dp[3][2])
	debug(dp[3][3])
	debug(dp[3][4])
	
	debug(dp[5][6])
	*/
	for (int i=n-k+1; i<=n; i++) ans=max(ans, dp[x][i]);
	cout<<ans<<'\n';
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/