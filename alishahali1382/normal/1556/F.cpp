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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=14;

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[N], P[N][N];
ll tof[N][1<<N];
ll tof2[1<<7][1<<N], tof3[1<<7][1<<N];
ll dp[1<<N];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll Get(int mask1, int mask2){
	int x=(mask1&127), y=((mask1-x)>>7);
	return tof2[x][mask2]*tof3[y][mask2]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) P[i][j]=A[i]*powmod(A[i]+A[j], mod-2)%mod;
	for (int i=0; i<n; i++){
		tof[i][0]=1;
		for (int j=1; j<(1<<n); j++){
			int v=__builtin_ctz(j);
			tof[i][j]=tof[i][j^(1<<v)]*P[i][v]%mod;
		}
	}
//	debug(tof[0][2])
//	debug(tof[1][1])
	
	for (int i=0; i<(1<<n); i++) tof2[0][i]=tof3[0][i]=1;
	for (int i=1; i<(1<<7); i++){
		int v=__builtin_ctz(i);
		for (int mask=0; mask<(1<<n); mask++){
			tof2[i][mask]=tof2[i^(1<<v)][mask]*tof[v][mask]%mod;
			tof3[i][mask]=tof3[i^(1<<v)][mask]*tof[v+7][mask]%mod;/*
			if (i==1 && mask==2){
				debug(tof2[i][mask])
				debug2(v, i^(1<<v))
				debug(tof2[i^(1<<v)][mask])
			}*/
		}
	}
//	debug(tof2[1][2])
//	debug(Get(1, 2))
//	debug(Get(2, 1))
	dp[0]=1;
	for (int mask=1; mask<(1<<n); mask++){
		dp[mask]=1;
		for (int sub=(mask-1)&mask; sub; sub=(sub-1)&mask)
			dp[mask]=(dp[mask]-dp[sub]*Get(sub, mask^sub))%mod;
		
//		debug2(mask, dp[mask])
		
		ll ted=__builtin_popcount(mask);
		ans=(ans + dp[mask]*Get(mask, (1<<n)-1-mask)%mod*ted)%mod;
	}
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}