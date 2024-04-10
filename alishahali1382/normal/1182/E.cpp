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
const int MAXN = 5, SQ=31623;

struct MATRIX{
	ll a[MAXN][MAXN];
	MATRIX(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=0;}
	void operator =(MATRIX M){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=M.a[i][j];}
	void operator *=(MATRIX M){
		MATRIX tmp;
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) tmp.a[i][j]+=a[i][k]*M.a[k][j];
		for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=tmp.a[i][j]%(mod-1);
	}
};

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
}

ll n, c, f1, f2, f3;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>f1>>f2>>f3>>c;
	c=c*c%mod;
	f1=solve(5, f1);
	f2=solve(5, f2);
	f3=solve(5, f3);
	c=solve(5, c);
	
	MATRIX M;
	M.a[0][1]=M.a[1][2]=M.a[2][0]=M.a[2][1]=M.a[2][2]=M.a[3][3]=M.a[3][4]=M.a[4][4]=1;
	M.a[2][3]=c;
	tavan(M, n-1);
	
	
	ll ans=f1*M.a[0][0] + f2*M.a[0][1] + f3*M.a[0][2] + M.a[0][3] + M.a[0][4];
	ans%=(mod-1);
	cout<<powmod(5, ans)<<'\n';
	
	return 0;
}