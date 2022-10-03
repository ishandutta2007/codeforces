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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=998244353;
const int N=(1<<17);
typedef vector<ll> Poly;

int n, m, k, u, v, x, y, t, a, b;
int rev[N<<2];
Poly C(N, 0);

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

void NTT(Poly &A, bool inv){
	int n=A.size(), lg=0;
	while ((1<<lg)<n) lg++;
	A.resize(n=(1<<lg), 0);
	for (int i=1; i<n; i++){
		rev[i]=(rev[i>>1]>>1) | ((i&1)<<(lg-1));
		if (rev[i]<i) swap(A[rev[i]], A[i]);
	}
	for (int len=1; len<n; len<<=1){
		ll wn=powmod(3, mod/2/len);
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<n; i+=2*len){
			ll w=1;
			for (int j=i; j<i+len; j++){
				ll x=A[j], y=A[j+len]*w;
				A[j]=(x+y)%mod;
				A[j+len]=(x-y)%mod;
				w=w*wn%mod;
			}
		}
	}
	if (inv){
		ll invn=powmod(n, mod-2);
		for (int i=0; i<n; i++) A[i]=A[i]*invn%mod;
	}
}

Poly Inverse(Poly A){ // A[0]!=0
	Poly B={powmod(A[0], mod-2)};
	for (int n=1; n<A.size(); n<<=1){
		Poly C(4*n, 0), D(4*n, 0);
		for (int i=0; i<2*n; i++) C[i]=A[i];
		for (int i=0; i<n; i++) D[i]=B[i];
		NTT(C, 0);
		NTT(D, 0);
		for (int i=0; i<4*n; i++) C[i]=C[i]*D[i]%mod*D[i]%mod;
		NTT(C, 1);
		B.resize(2*n, 0);
		for (int i=0; i<2*n; i++) B[i]=(2*B[i]-C[i])%mod;
	}
	return B;
}

Poly Sqrt(Poly A){ // A[0]=1
	Poly B={1};
	for (int n=1; n<A.size(); n<<=1){
		B.resize(2*n, 0);
		Poly C=A, D=Inverse(B);
		C.resize(2*n, 0);
		C.resize(4*n, 0);
		D.resize(4*n, 0);
		NTT(C, 0);
		NTT(D, 0);
		for (int i=0; i<4*n; i++) C[i]=C[i]*D[i]%mod;
		NTT(C, 1);
		for (int i=0; i<2*n; i++) B[i]=(B[i]+C[i])*(mod+1)/2%mod;
	}
	return B;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (n--) cin>>x, C[x]++;
	for (int i=0; i<N; i++) C[i]=((i==0)-4*C[i])%mod;
	C=Sqrt(C);
	C[0]++;
	C=Inverse(C);
	for (int i=1; i<=m; i++){
		ll ans=2*C[i]%mod;
		if (ans<0) ans+=mod;
		cout<<ans<<'\n';
	}
	
	return 0;
}