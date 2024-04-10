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
const int MAXN = 1000010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, cnt, inv;
ll F[MAXN];
int A[MAXN];

struct FENWICK{
	int fen[MAXN];
	void add(int x, int w){
		fen[0]+=w;
		for (; x<MAXN; x+=x&-x) fen[x]+=w;
	}
	int get(int x){
		int res=0;
		for (; x; x-=x&-x) res+=fen[x];
		return res;
	}
} fen1, fen2;

ll C2(ll n){
	return n*(n-1)/2%mod;
}
ll f(ll n, ll k){
	return (C2(k)%mod*F[n-1] + k*F[n-1]%mod*C2(n-1)%mod*(mod+1)/2)%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], fen2.add(i, +1);
	for (int i=1; i<=n; i++){
		fen1.add(A[i], +1);
		fen2.add(A[i], -1);
		ll ted=A[i]-fen1.get(A[i]);
		
		ans=(ans + F[n-i]*ted%mod*inv + f(n-i+1, ted))%mod;
		ans=(ans + cnt*ted%mod*F[n-i])%mod;
		cnt=cnt - (fen1.fen[0]-fen1.get(A[i]));
		cnt=cnt + fen2.get(A[i]);
		inv+=fen1.fen[0]-fen1.get(A[i]);
		inv%=mod;
		cnt%=mod;
//		debug2(i, cnt)
	}
	ans=(ans + inv)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}