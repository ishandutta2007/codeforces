#include <bits/stdc++.h>

using namespace std;

#define debug(x) {cerr<<#x<<"="<<x<<"\n";}
#define debug2(x, y) {cerr<<"{"#x<<", "<<#y<<"}={"<<x<<" "<<y<<"}\n";}
typedef long long ll;
typedef complex<double> point;
const double pi=acos(-1);
const int mod=998244353;
const int N=(1<<20);

int rev[N];

void FFT(point *A, int n, bool inv){
	int lg=__builtin_ctz(n);
	for (int i=1; i<n; i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
		if (rev[i]<i) swap(A[i], A[rev[i]]);
	}
	for (int len=1; len<n; len<<=1){
		double theta=pi/len;
		if (inv) theta*=-1;
		point wn=point(cos(theta), sin(theta));
		for (int i=0; i<n; i+=2*len){
			point w=1;
			for (int j=i; j<i+len; j++){
				point x=A[j], y=w*A[j+len];
				A[j]=x+y;
				A[j+len]=x-y;
				w*=wn;
			}
		}
	}
	if (inv){
		for (int i=0; i<n; i++) A[i]/=n;
	}
}
ll powmod(ll a, ll b){
	ll res=1;
	for (; b; b>>=1, a=a*a%mod) if (b&1) res=res*a%mod;
	return res;
}
inline void fix(ll &x){
	if (x<0) x+=mod;
	if (x>=mod) x-=mod;
}
void NTT(ll *A, int n, bool inv){
	int lg=__builtin_ctz(n);
	for (int i=1; i<n; i++){
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
		if (rev[i]<i) swap(A[i], A[rev[i]]);
	}
	for (int len=1; len<n; len<<=1){
		ll wn=powmod(5, mod/2/len);
		if (inv) wn=powmod(wn, mod-2);
		for (int i=0; i<n; i+=2*len){
			ll w=1;
			for (int j=i; j<i+len; j++){
				ll x=A[j], y=w*A[j+len]%mod;
				fix(A[j]=x+y);
				fix(A[j+len]=x-y);
				w=w*wn%mod;
			}
		}
	}
	if (inv){
		ll nn=powmod(n, mod-2);
		for (int i=0; i<n; i++) A[i]=A[i]*nn%mod;
	}
}

ll A[N];

int main(){
	int n, x, k;
	cin>>n>>k;
	while (k--) cin>>x, A[x]++;
	NTT(A, N, 0);
	for (int i=0; i<N; i++) A[i]=powmod(A[i], n/2);
	NTT(A, N, 1);
	ll ans=0;
	for (int i=0; i<N; i++) ans=(ans + A[i]*A[i])%mod;
	fix(ans);
	cout<<ans<<"\n";
	
	return 0;
}