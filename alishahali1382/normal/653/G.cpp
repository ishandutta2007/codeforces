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
const int mod = 1000000007;
const int MAXN = 300010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int sieve[MAXN];
int cnt[MAXN][LOG];
ll Z[MAXN];
ll ps[MAXN];
ll F[MAXN], I[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll Choose(ll n, ll r){
	if (r<0 || r>n) return 0;
	return (F[n]*I[r]%mod)*I[n-r]%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i<MAXN; i++) if (!sieve[i]) for (int j=i; j<MAXN; j+=i) sieve[j]=i;
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x;
		while (x>1){
			int p=sieve[x], t=0;
			while (x%p==0) x/=p, t++;
			cnt[p][t]++;
			cnt[p][0]--;
		}
	}
	
	Z[1]=powmod(2, n-1)-1;
	for (int i=2; i<=n; i++){
		Z[i]=(Z[i-1]-Choose(n-1, i-2)-Choose(n-1, i-1))%mod;
	}
	for (int i=1; i<=n; i++) ps[i]=(ps[i-1]+Z[i])%mod;
	
	for (int p=2; p<MAXN; p++) if (cnt[p][0]){
		cnt[p][0]+=n;
		int sum=0;
		for (int i=0; i<LOG; i++){
			ans+=(ps[sum+cnt[p][i]]-ps[sum])*i%mod;
			sum+=cnt[p][i];
		}
	}
	ans%=mod;
	ans=-ans;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}