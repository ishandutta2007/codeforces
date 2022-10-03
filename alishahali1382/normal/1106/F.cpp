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
const int MAXN = 105, SQ=31623;

struct MATRIX{
	int a[MAXN][MAXN];
	MATRIX(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=0;}
	void operator =(MATRIX &M){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=M.a[i][j];}
	void operator *=(MATRIX &M){
		MATRIX tmp;
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) tmp.a[i][j]=(tmp.a[i][j]+1ll*a[i][k]*M.a[k][j])%(mod-1);
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=tmp.a[i][j];
	}
} T;

void tavan(MATRIX &M, ll t){
	if (!t){
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) M.a[i][j]=(i==j);
		return ;
	}
	t--;
	MATRIX tmp=M;
	for (; t; t>>=1, tmp*=tmp) if (t&1) M*=tmp;
}

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll solve(ll a, ll b){
	map<int, int> mp;
	ll inva=powmod(a, mod-2), tmp=1;
	for (int i=0; i<SQ; i++) mp[b*tmp%mod]=i, tmp=tmp*inva%mod;
	tmp=1;
	ll aT=powmod(a, SQ);
	for (int i=0; i<mod; i+=SQ){
		if (mp.count(tmp)) return i+mp[tmp];
		tmp=tmp*aT%mod;
	}
	return -1;
}

ll n, fn, k;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k;
	for (int i=0; i<k-1; i++) T.a[i][i+1]=1;
	for (int i=1; i<=k; i++) cin>>T.a[k-1][k-i];
	cin>>n>>fn;
	
	tavan(T, n-1);
	ll tav=T.a[0][k-1];
	ll ans=solve(powmod(3, tav), fn);
	if (ans==-1) kill(-1)
	cout<<powmod(3, ans)<<'\n';
	
	return 0;
}