#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

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
const int MAXN = 3610, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];
bool mark1[MAXN], mark2[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r>n || r<0) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int md(int x){
	if (x>=mod) x-=mod;
	return x; 
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	//debug(C(5, 2))
	
	cin>>n>>m>>k;
	while (k--){
		cin>>x>>y>>a>>b;
		mark1[x]=mark1[a]=1;
		mark2[y]=mark2[b]=1;
	}
	dp1[0][0]=dp2[0][0]=1;
	dp1[1][0]=dp2[1][0]=1;
	for (int i=2; i<=n; i++){
		dp1[i][0]=1;
		for (int j=1; j<=n; j++){
			dp1[i][j]=dp1[i-1][j];
			if (!(mark1[i]+mark1[i-1])) dp1[i][j]=md(dp1[i][j]+dp1[i-2][j-1]);
		}
	}
	
	for (int i=2; i<=m; i++){
		dp2[i][0]=1;
		for (int j=1; j<=m; j++){
			dp2[i][j]=dp2[i-1][j];
			if (!(mark2[i]+mark2[i-1])) dp2[i][j]=md(dp2[i-1][j]+dp2[i-2][j-1]);
		}
	}
	
	int cnt1=0, cnt2=0;
	for (int i=1; i<=n; i++) if (!mark1[i]) cnt1++;
	for (int i=1; i<=m; i++) if (!mark2[i]) cnt2++;
	
	
	for (int i=0; 2*i<=cnt1; i++) for (int j=0; 2*j<=cnt2; j++){
		ll tmp=1ll*dp1[n][i]*dp2[m][j]%mod;
		tmp=tmp*(C(cnt1-2*i, j)*C(cnt2-2*j, i)%mod)%mod;
		tmp=tmp*(F[i]*F[j]%mod)%mod;
		ans+=tmp;
	}
	cout<<ans%mod<<'\n';
	
	return 0;
}