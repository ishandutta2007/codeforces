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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
ll F[MAXN], I[MAXN];
ll cnt[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (ll tmp=a; b; b>>=1, tmp=tmp*tmp%mod) if (b&1) res=res*tmp%mod;
	return res;
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>m>>k;
	swap(n, m);
	if (n==1) kill(powmod(k, n*m))
	
	for (int i=1; i<=1000; i++){
		for (int j=0; j<i; j++){
			ll tmp=C(i, j)*powmod(i-j, m)%mod;
			if (j&1) tmp=-tmp;
			cnt[i]=(cnt[i]+tmp)%mod;
		}
	}
	
	for (int i=1; i<=k && i<=m; i++) for (int j=0; j<=i; j++){
		ll tmp=powmod(cnt[i], 2) * powmod(j, (n-2)*m)%mod;
		tmp=tmp*C(k, i)%mod;
		tmp=tmp*C(k-i, i-j)%mod;
		tmp=tmp*C(i, j)%mod;
		ans=(ans+tmp)%mod;
		//debug2(i, cnt[i])
	}
	ans%=mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}