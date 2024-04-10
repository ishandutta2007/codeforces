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
const int MAXN = 2010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b=1, ans;
ll dp1[2][MAXN][11]; // dp[i][j][k]   first i odd numbers    subset with j negatives     modulo 11=k
ll dp2[2][MAXN][11]; // dp[i][j][k]   first i even numbers   subset with j negatives     modulo 11=k
ll F[MAXN], I[MAXN];
vector<int> odd, even;

ll powmod(ll a, ll b){
	ll res=1;
	for (ll tmp=a; b; b>>=1, tmp=tmp*tmp%mod) if (b&1) res=res*tmp%mod;
	return res;
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

ll S(ll k, ll n){
	if (k<0) return 0;
	if (!n) return 1;
	return C(n+k-1, k-1);
}

void solve(){
	odd.clear();
	even.clear();
	a=0;
	b=1;
	ans=0;
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	
	cin>>n;
	while (n--){
		cin>>x;
		int t=1, val=0;
		for (; x; x/=10, t=-t) val+=t*(x%10);
		val=((val%11)+11)%11;
		if (t==1) even.pb(val);
		else odd.pb(val);
	}
	n=odd.size();
	m=even.size();
	//debug2(n, m)
	//debug2(a, b)
	
	dp1[a][0][0]=1;
	for (int i=1; i<=n; i++){
		for (int k=0; k<=10; k++){
			dp1[b][0][k]=dp1[a][0][(k-odd[i-1]+11)%11];
			for (int j=1; j<=i; j++) dp1[b][j][k]=(dp1[a][j][(k-odd[i-1]+11)%11] + dp1[a][j-1][(k+odd[i-1])%11])%mod;
		}
		swap(a, b);
	}
	
	int a1=0, b1=1;
	dp2[a1][0][0]=1;
	for (int i=1; i<=m; i++){
		for (int k=0; k<=10; k++){
			dp2[b1][0][k]=dp2[a1][0][(k-even[i-1]+11)%11];
			for (int j=1; j<=i; j++) dp2[b1][j][k]=(dp2[a1][j][(k-even[i-1]+11)%11] + dp2[a1][j-1][(k+even[i-1])%11])%mod;
		}
		swap(a1, b1);
	}
	
	for (int cnt=0; cnt<=m; cnt++) for (int k=0; k<11; k++){
		ll tmp=dp2[a1][cnt][k]*dp1[a][n/2][(11-k)%11]%mod;
		tmp=tmp*(F[cnt]*F[m-cnt]%mod)%mod;
		//if (k==0) debug(tmp)
		tmp=tmp*S(1 + n/2, cnt)%mod;
		//if (k==0) debug(tmp)
		tmp=tmp*S(n+1 - (1+n/2), m-cnt)%mod;
		//if (k==0) debug(tmp)
		ans+=tmp;
	}
	ans%=mod;
	ans=ans*(F[n/2]*F[(n+1)/2]%mod)%mod;
	cout<<ans<<'\n';
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	int T;
	cin>>T;
	while (T--) solve();
	
	return 0;
}