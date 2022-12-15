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
const int MAXN = 110, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, shit=1;
ll A[MAXN], B[MAXN];
ll dp[MAXN][MAXN*2][MAXN];
ll ent[MAXN][MAXN];
ll F[MAXN], I[MAXN];
vector<int> comp;

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

int C(int n, int r){
	if (r<0 || r>n) return 0;
	ll res=1;
	for (int i=n; i>n-r; i--) res=res*i%mod;
	return res*I[r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	cin>>n;
	for (int i=n; i; i--){
		cin>>A[i]>>B[i];
		comp.pb(A[i]);
		comp.pb(++B[i]);
		shit=shit*powmod(B[i]-A[i], mod-2)%mod;
	}
	/*
	debug2(A[1], B[1])
	debug2(A[2], B[2])*/
	
	comp.pb(-1);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	m=comp.size()-1;
	
	for (int i=0; i<m; i++) for (int j=0; j<=n; j++) ent[i][j]=C(comp[i+1]-comp[i]+j-1, j);
	
	for (int i=1; i<=n; i++){
		A[i]=lower_bound(all(comp), A[i])-comp.begin();
		B[i]=lower_bound(all(comp), B[i])-comp.begin();
	}
	dp[0][0][0]=1;
	for (int i=1; i<=n; i++){
		//dp[i][0][0]=1;
		for (int j=A[i]; j<B[i]; j++){
			for (int k=1; k<=i; k++){
				//dp[i][j][k]=dp[i-1][j][k];
				if (k>1) dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k-1])%mod;
				else for (int jj=0; jj<j; jj++) dp[i][j][k]=(dp[i][j][k]+dp[i-1][jj][0])%mod;
			}
			for (int kk=1; kk<=i; kk++) dp[i][j][0]=(dp[i][j][0]+dp[i][j][kk]*ent[j][kk])%mod;
		}
	}
	
	for (int j=1; j<=m; j++) ans=(ans+dp[n][j][0])%mod;
	//debug(ans)
	ans=ans*shit%mod;
	cout<<ans<<'\n';
	
	return 0;
}