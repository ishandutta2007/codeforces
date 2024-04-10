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
const int MAXN = 60, LOG=20;

struct MAT{
	ll a[MAXN][MAXN];
	MAT(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=0;}
	void relax(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]%=mod;}
} T;

void operator *=(MAT &m1, MAT &m2){
	MAT M;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) M.a[i][j]+=m1.a[i][k]*m2.a[k][j]%mod;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) m1.a[i][j]=M.a[i][j];
	m1.relax();
}

void tavan(MAT &M, ll x){
	MAT m;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) m.a[i][j]=M.a[i][j], M.a[i][j]=0;
	for (int i=0; i<MAXN; i++) M.a[i][i]=1;
	for (; x; x>>=1, m*=m) if (x&1) M*=m;
}

ll n, m, k, u, v, x, y, t, a, b, ans;
char c1, c2;

int f(char c){
	if ('a'<=c && c<='z') return c-'a';
	return c-'A'+26;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=0; i<m; i++) for (int j=0; j<m; j++) T.a[i][j]=1;
	while (k--){
		cin>>c1>>c2;
		T.a[f(c1)][f(c2)]=0;
	}
	tavan(T, n-1);
	for (int i=0; i<m; i++) for (int j=0; j<m; j++) ans+=T.a[i][j];
	ans%=mod;
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