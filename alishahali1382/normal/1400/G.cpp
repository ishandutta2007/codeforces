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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int MAXN=300010, N=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
int L[MAXN], R[MAXN], A[N], B[N], ted[MAXN];
int ps[N*2+1][MAXN];
int mark[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>L[i]>>R[i];
		ted[L[i]]++;
		ted[++R[i]]--;
	}
	for (int i=0; i<m; i++) cin>>A[i]>>B[i];
	memset(mark, -1, sizeof(mark));
	for (int mask=0; mask<(1<<m); mask++){
		int t=0, l=1, r=n+1;
		for (int i=0; i<m; i++) if (mask&(1<<i)){
			if (mark[A[i]]!=mask){
				mark[A[i]]=mask;
				t++;
				l=max(l, L[A[i]]);
				r=min(r, R[A[i]]);
			}
			if (mark[B[i]]!=mask){
				mark[B[i]]=mask;
				t++;
				l=max(l, L[B[i]]);
				r=min(r, R[B[i]]);
			}
		}
		if (l>r) continue ;
		int z=1;
		if (__builtin_popcount(mask)&1) z=-1;
		ps[t][l]+=z;
		ps[t][r]-=z;
	}
	for (int i=1; i<=n; i++) ted[i]+=ted[i-1];
	for (int t=0; t<=2*m; t++){
		for (int i=1; i<=n; i++){
			ps[t][i]+=ps[t][i-1];
			ans=(ans + nCr(ted[i]-t, i-t)*ps[t][i])%mod;
		}
	}
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}