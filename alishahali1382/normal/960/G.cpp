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
const int mod = 998244353;
const int MAXN = 400010, LOG=20;

ll n, A, B, m, k, u, v, x, y, t, ans;
ll F[MAXN], I[MAXN];
int rev[MAXN];
vector<ll> vec[MAXN];

ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}

ll C(ll n, ll r){
	if (r<0 || r>n) return 0;
	return F[n]*I[r]%mod*I[n-r]%mod;
}

void NTT(vector<ll> &A, bool inv){
	int lg=ceil(log2(A.size())), n=(1<<lg);
	A.resize(n, 0);
	for (int i=1; i<n; i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
		if (rev[i]<i) swap(A[rev[i]], A[i]);
	}
	for (int len=1; len<n; len<<=1){
		ll wlen=powmod(3, mod/2/len);
		if (inv) wlen=powmod(wlen, mod-2);
		for (int i=0; i<n; i+=(len<<1)){
			ll w=1;
			for (int j=0; j<len; j++){
				ll x=A[i+j], y=A[i+len+j]*w;
				A[i+j]=(x+y)%mod;
				A[i+j+len]=(x-y)%mod;
				w=w*wlen%mod;
			}
		}
	}
	if (inv){
		ll invn=powmod(n, mod-2);
		for (int i=0; i<n; i++) A[i]=(A[i]*invn)%mod;
	}
}

void Mul(vector<ll> &A, vector<ll> &B){
	int n=ceil(log2(max(A.size(), B.size())));
	n=2<<n;
	A.resize(n, 0);
	B.resize(n, 0);
	
	//debugv(A)
	//debugv(B)
	
	NTT(A, 0);
	NTT(B, 0);
	for (int i=0; i<n; i++) A[i]=A[i]*B[i]%mod;
	NTT(A, 1);
	while (A.size() && !A.back()) A.pop_back();
//	debugv(A)
//	cerr<<'\n';
	
	//debug("done")
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=F[i-1]*i%mod;
	I[MAXN-1]=powmod(F[MAXN-1], mod-2);
	for (int i=MAXN-1; i; i--) I[i-1]=I[i]*i%mod;
	
	cin>>n>>A>>B;
	if (!A || !B) kill(0)
	if (n==1) kill(1)
	A--;
	B--;
	for (int i=1; i<n; i++) vec[i]={i-1, 1};
	for (int i=n-1; i>1; i--) Mul(vec[i>>1], vec[i]);
	if (A+B<vec[1].size()) ans=vec[1][A+B];
	//debug(ans)
	ans=ans*C(A+B, A)%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	//for (int i=1; i<=n; i++) debug2(i, (vec[1][i]+mod)%mod)
	
	return 0;
}