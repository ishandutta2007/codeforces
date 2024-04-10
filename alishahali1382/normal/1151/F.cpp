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
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110;

struct MAT{
	ll a[MAXN][MAXN];
	MAT(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=0;}
	void relax(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]%=mod;}
	
} T;

void zarb(MAT &m1, MAT &m2){
	MAT tmp;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) tmp.a[i][j]+=m1.a[i][k]*m2.a[k][j]%mod;
	tmp.relax();
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) m1.a[i][j]=tmp.a[i][j];
}

void tavan(MAT &M, ll x){
	if (x==0){
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) M.a[i][j]=(i==j);
		return ;
	}
	MAT tmp;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) tmp.a[i][j]=M.a[i][j];
	x--;
	for (; x; x>>=1, zarb(tmp, tmp)) if (x&1) zarb(M, tmp); 
}

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll n, m, k, u, v, x, y, t, c0, c1, ans, bad;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]) c1++;
		else c0++;
	}
	for (int i=1; i<=c0; i++) bad+=A[i];
	
	for (ll i=0; i<=n; i++){
		T.a[i][i]=(c1*(c1-1)+c0*(c0-1))/2-2*i*i+n*i;
		if (i) T.a[i][i-1]=i*i;
		if (i<n) T.a[i][i+1]=(c1-i)*(c0-i);
	}
	tavan(T, k);
	ans=(T.a[bad][0]+mod)%mod;
	
	cout<<(ans*powmod(n*(n-1)/2, mod-k-1))%mod<<'\n';
	
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