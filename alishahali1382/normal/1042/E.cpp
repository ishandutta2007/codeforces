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
const int mod = 998244353;
const int MAXN = 1010, LOG=20;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll inv(ll x){ return powmod(x, mod-2);}

ll n, m, k, u, v, r, c, t, sdp, sx, sy, sxx, syy, ans;
int A[MAXN][MAXN];
pii ind[MAXN*MAXN];
ll dp[MAXN][MAXN];

bool cmp(pii i, pii j){ return A[i.first][i.second]<A[j.first][j.second];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		cin>>A[i][j];
		ind[t++]={i, j};
	}
	sort(ind, ind+t, cmp);
	for (int i=0, j=i; i<t; i=++j){
		while (A[ind[i].first][ind[i].second]==A[ind[j+1].first][ind[j+1].second]) j++;
		for (int k=i; k<=j; k++){
			ll x=ind[k].first, y=ind[k].second;
			dp[x][y]=(x*x*i+y*y*i+sdp-2*x*sx-2*y*sy+sxx+syy)%mod;
			dp[x][y]=dp[x][y]*inv(i)%mod;
		}
		for (int k=i; k<=j; k++){
			ll x=ind[k].first, y=ind[k].second;
			dp[x][y]=(dp[x][y]+mod)%mod;
			sdp=(sdp+dp[x][y])%mod;
			sx=(sx+x)%mod;
			sy=(sy+y)%mod;
			sxx=(sxx+x*x)%mod;
			syy=(syy+y*y)%mod;
		}
	}
	cin>>r>>c;
	cout<<dp[r][c]<<'\n';
	
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