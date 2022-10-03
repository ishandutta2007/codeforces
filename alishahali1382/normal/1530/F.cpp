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
const int mod=31607;
const int N=21;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[N][N];
int B[N][N];
int mul[N][1<<N];
int mul2[N];

inline int powmod(int a, int b){
	int res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
//	for (int i=2; i<mod; i++) assert(mod%i);
	cin>>n;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++){
		cin>>A[i][j];
		A[i][j]=A[i][j]*powmod(10000, mod-2)%mod;
	}
	int shit=1;
	for (int mask=0; mask<(1<<n+2); mask++){
		if (mask%(1<<n)==0){
			shit=1;
			memcpy(B, A, sizeof(B));
			if (mask&(1<<n)){
				for (int i=0; i<n; i++){
					shit=shit*B[i][i]%mod;
					B[i][i]=1;
				}
			}
			if (mask&(2<<n)){
				for (int i=0; i<n; i++){
					shit=shit*B[i][n-1-i]%mod;
					B[i][n-1-i]=1;
				}
			}
//			debug2(mask, shit)
			
			for (int i=0; i<n; i++){
				mul[i][0]=1;
				for (int j=1; j<(1<<n); j++){
					int x=__builtin_ctz(j);
					mul[i][j]=mul[i][j^(1<<x)]*B[i][x]%mod;
				}
			}
			for (int j=0; j<n; j++){
				mul2[j]=1;
				for (int i=0; i<n; i++) mul2[j]=mul2[j]*B[i][j]%mod;
			}
		}
		int res=shit;
		for (int i=0; i<n; i++){
			res=res*(1-mul[i][(1<<n)-1-(mask%(1<<n))])%mod;
		}
		for (int j=0; j<n; j++) if (mask&(1<<j)) res=res*mul2[j]%mod;
		
		if (__builtin_popcount(mask)&1) res*=-1;
		ans=(ans + res)%mod;
	}
	ans=1-ans;
	ans%=mod;
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
//	debug(ans*16%mod)
	
	return 0;
}