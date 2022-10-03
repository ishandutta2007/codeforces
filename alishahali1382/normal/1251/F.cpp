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
const int MAXN = 800010, LOG=18;

ll n, k, q, u, v, x, y, t, a, b;
ll F[MAXN], I[MAXN];
int rev[MAXN];
int A[MAXN], B[MAXN], Q[MAXN];
ll ans[MAXN];

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a*a%mod, b>>1)%mod;
	return powmod(a*a%mod, b>>1);
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

void NTT(vector<ll> &F, bool inv){
	int n=F.size(), lg=ceil(log2(n));
	n=1<<lg;
	F.resize(n, 0);
	
	for (int i=0; i<n; i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<(lg-1));
	for (int i=0; i<n; i++) if (i<rev[i]) swap(F[i], F[rev[i]]);
	for (int len=1; len<n; len<<=1){
		ll wn=powmod(3, (mod-1)/(2*len));
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<n; i+=2*len){
			ll w=1;
			for (int j=i; j<i+len; j++){
				ll x=(F[j] + F[j+len]*w)%mod;
				ll y=(F[j] - F[j+len]*w)%mod;
				F[j]=x;
				F[j+len]=y;
				w=w*wn%mod;
			}
		}
	}
	if (inv){
		ll invn=powmod(n, mod-2);
		for (int i=0; i<n; i++) F[i]=F[i]*invn%mod;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>x, A[x]++;
	for (int j=1; j<=k; j++) cin>>B[j];
	cin>>q;
	for (int i=1; i<=q; i++) cin>>Q[i], Q[i]/=2;
	
	for (int ind=1; ind<=k; ind++){
		int x=B[ind], cnt11=0, cnt12=0;
		for (int i=1; i<x; i++) if (A[i]){
			if (A[i]==1) cnt12++;
			else cnt11+=2;   //  (1 + x)^2 = (1 + 2*x + x^2)
		}
		vector<ll> X(cnt11+1), Y(cnt12+1);
		for (int i=0; i<=cnt11; i++) X[i]=C(cnt11, i);
		for (int i=0, j=1; i<=cnt12; i++, j=j*2%mod) Y[i]=j*C(cnt12, i)%mod;
		
//		debugv(X)
//		debugv(Y)
		
		int sz=cnt11+cnt12+1;
		X.resize(sz, 0);
		Y.resize(sz, 0);
		NTT(X, 0);
		NTT(Y, 0);
		for (int i=0; i<X.size(); i++) X[i]=X[i]*Y[i]%mod;
		NTT(X, 1);
		
//		debugv(X)
//		cerr<<'\n';
		
		for (int id=1; id<=q; id++){
			int tmp=Q[id]-x-1;
			//if (id==1) debug(tmp)
			if (0<=tmp && tmp<X.size()) ans[id]=(ans[id]+X[tmp])%mod;
		}
	}
	
	for (int i=1; i<=q; i++) cout<<(ans[i]+mod)%mod<<'\n';
	
	return 0;
}
/*
5 2
3 3 1 1 1
2 4
1
12

*/