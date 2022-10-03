#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=10000000000000010LL;
const int MAXN=300010, LOG=20;

ll n, mod, k, u, v, l, r, t, p, ans;
ll A[MAXN], F[MAXN], I[MAXN], phi;
vector<int> prime;

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
int get(int n, int p){
	if (!n) return 0;
	return n/p + get(n/p, p);
}
ll nCr(ll n, ll r){
	if (r<0 || r>n) return 0;
	ll res=F[n]*I[r]%mod*I[n-r]%mod;
	for (int p:prime) res=res*powmod(p, get(n, p)-get(r, p)-get(n-r, p))%mod;
	return res;
}
ll Solve(ll n, ll r){
	if (r<0) return 0;
	return nCr(n, (n+1)/2)-nCr(n, (n+r)/2+1);
}
ll Solve2(ll n){
	return Solve(n, r)-Solve(n, l-1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>mod>>l>>r;
	int tmp=mod;
	for (int i=2; i*i<=tmp; i++) if (tmp%i==0){
		prime.pb(i);
		while (tmp%i==0) tmp/=i;
	}
	if (tmp>1) prime.pb(tmp);
	phi=mod;
	for (int p:prime) phi=phi/p*(p-1);
	
	F[0]=1;
	for (int i=1; i<MAXN; i++){
		A[i]=i;
		for (int p:prime) while (A[i]%p==0) A[i]/=p;
		F[i]=F[i-1]*A[i]%mod;
	}
	I[MAXN-1]=powmod(F[MAXN-1], phi-1);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*A[i]%mod;
	
	for (int i=0; i<=n; i++) ans=(ans + nCr(n, i)*Solve2(n-i))%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<"\n";
	
	return 0;
}