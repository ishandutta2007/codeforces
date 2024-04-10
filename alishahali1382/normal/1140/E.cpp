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
const int mod = 998244353 ;
const int MAXN = 200010, LOG=20;

ll k;
ll dp1[MAXN]; // nonequal ends
ll dp2[MAXN]; // equal ends
ll dp3[MAXN];

ll calc(ll A[], ll n){
	if (!n) return 1;
	ll res=1;
	for (int i=1; i<n; i++) if (A[i]==A[i+1] && A[i]!=-1) return 0;
	bool flag=1;
	for (int i=1; i<=n; i++) if (A[i]!=-1) flag=0;
	if (flag){
		res=k;
		for (int i=0; i<n-1; i++) res=(res*(k-1))%mod;
		return res;
	}
	
	ll len=0;
	for (int i=1; i<=n; i++){
		if (A[i]==-1) len++;
		else{
			if (A[i-len-1]==0) res=res*dp3[len]%mod;
			else if (A[i-len-1]==A[i]) res=res*dp2[len]%mod;
			else res=res*dp1[len]%mod;
			len=0;
		}
	}
	res=res*dp3[len]%mod;
	
	return res;
}

ll n, m, u, v, x, y, t, a, b, ans=1;
ll A[MAXN];
ll B[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=0; i<n; i++){
		if (i%2==0) cin>>A[++a];
		else cin>>B[++b];
	}
	
	dp1[0]=dp2[0]=1;
	dp1[1]=k-2;
	dp2[1]=k-1;
	for (int i=2; i<MAXN; i++){
		dp1[i]=(dp2[i-1]+(k-2)*dp1[i-1])%mod;
		dp2[i]=dp1[i-1]*(k-1)%mod;
	}
	dp3[0]=1;
	for (int i=1; i<MAXN; i++) dp3[i]=(dp3[i-1]*(k-1))%mod;
	
	ans=calc(A, a)*calc(B, b)%mod;
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