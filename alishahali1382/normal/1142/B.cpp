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
const int MAXN = 1000010, LOG=18;

int n, m, q, u, v, x, y, t, l, r;
int A[MAXN], P[MAXN*2], pos[MAXN];
int val[MAXN][LOG];
int dp[MAXN][LOG];
vector<int> ind[MAXN];

int RMQ(int l, int r){ // [l, r)
	int x=log2(r-l);
	return min(dp[l][x], dp[r-(1<<x)][x]);
}

int query(){
	cin>>l>>r;
	int mn=RMQ(l, r+1);
	cout<<(mn<=r);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//memset(val, -1, sizeof(val));
	cin>>n>>m>>q;
	for (int i=1; i<=n; i++) cin>>P[i], pos[P[i+n]=P[i]]=i;
	for (int i=1; i<=m; i++) cin>>A[i], ind[A[i]].pb(i);
	for (int i=1; i<=n; i++) ind[i].pb(inf);
	
	memset(val, 63, sizeof(val));
	
	for (int i=m; i; i--){
		val[i][0]=*upper_bound(all(ind[P[pos[A[i]]+1]]), i);
		for (int j=1; j<LOG; j++){
			if (val[i][j-1]>=inf) val[i][j]=inf;
			else val[i][j]=val[val[i][j-1]][j-1];
		}
	}
	
	
	memset(dp, 63, sizeof(dp));
	for (int i=m; i; i--){
		//debug(i)
		int tmp=i;
		for (int j=0; j<LOG; j++) if ((n-1)&(1<<j) && tmp<inf) tmp=val[tmp][j];
		dp[i][0]=tmp;
		for (int j=1; j<LOG; j++) dp[i][j]=min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
	}
	/*
	cerr<<endl;
	for (int i=1; i<=m; i++) cerr<<val[i][0]<<' ';cerr<<endl;
	for (int i=1; i<=m; i++) cerr<<val[i][1]<<' ';cerr<<endl;
	for (int i=1; i<=m; i++) cerr<<dp[i][0]<<' ';cerr<<endl;
	cerr<<endl;*/
	
	while (q--) query();
	
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