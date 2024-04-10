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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=300010;

ll n, m, k, u, v, x, y, t, a, b;
ll A[MAXN];
ll F[MAXN], I[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
ll nCr(int n, int r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

ll Solve(int l, int r){
	if (A[l]==0 && A[r]!=0) return Solve(l+1, r);
	if (A[l]!=0 && A[r]==0) return Solve(l, r-1);
	if (A[l]==0 && A[r]==0){
		int x=0, y=0;
		while (A[l]==0 && l<=r) l++, x++;
		while (A[r]==0 && l<=r) r--, y++;
		if (l>r) return powmod(2, x-1);
		ll res=0;
		for (int i=0; i<=min(x, y); i++){
			res=(res + nCr(x, i)*nCr(y, i))%mod;
		}
		return res*Solve(l, r)%mod;
	}
	ll balance=0;
	while (l<=r){
		balance+=A[l++];
		while (l<=r && balance>0) balance-=A[r--];
		if (balance==0) break ;
	}
	if (balance!=0) return 1;
	
	
	int x=0, y=0;
	while (A[l]==0 && l<=r) l++, x++;
	while (A[r]==0 && l<=r) r--, y++;
	if (l>r) return powmod(2, x+1);
	ll res=1;
	for (int i=0; i<=min(x, y); i++){
		res=(res + nCr(x+1, i+1)*nCr(y+1, i+1))%mod;
	}
	return res*Solve(l, r)%mod;
}

int Main(){
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	ll ans=Solve(1, n)%mod;
	if (ans<0) ans+=mod;
	kill(ans)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
5
1 3 5 7 9


*/