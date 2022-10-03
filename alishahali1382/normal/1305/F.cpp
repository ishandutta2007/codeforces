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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 1500010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN], B[MAXN];
bool sieve[MAXN];
bool mark[MAXN];

void upd(ll p){
	if (p<2) return ;
	if (p<MAXN && mark[p]) return ;
	if (p<MAXN) mark[p]=1;
	ll tmp=0;
	for (int i=1; i<=n; i++){
		if (A[i]<=p) tmp+=p-A[i];
		else{
			ll x=A[i]%p;
			tmp+=min(x, p-x);
		}
		if (tmp>=ans) return ;
	}
	ans=min(ans, tmp);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=2; i*i<MAXN; i++) if (!sieve[i]) for (int j=i*i; j<MAXN; j+=i) sieve[j]=1;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	ans=n;
	//for (int p=2; p<8000; p++) if (!sieve[p]) upd(p);
	
	sort(A+1, A+n+1); // ??
	ll N=0, l=max(A[1]-ans, 2ll), r=A[1]+ans;
	for (ll i=l; i<=r; i++) B[N++]=i;
	
	for (ll p=2; p<MAXN; p++) if (!sieve[p]){
		for (ll x=(l+p-1)/p*p; x<=r; x+=p){
			if (x-l<0 || x-l>=N) continue ;
			upd(p);
			while (B[x-l]%p==0 && B[x-l]) B[x-l]/=p;
		}
	}
	for (ll i=0; i<N; i++) if (B[i]>1){
		upd(B[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}
/*
10
1000000007 1000000007 1000000007 1000000007 1000000007 1000000007 1000000007 1000000007 1000000007 1000000009

*/