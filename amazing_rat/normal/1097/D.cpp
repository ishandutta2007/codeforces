#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
ll n,N,dp[100],s,ans;
int k,cnt,tot;
ll p[100];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	dp[0]=ans=1; read(n); read(k); N=n;
	for (ll z=2;z*z<=N;z++)
		if (n%z==0) {
			p[++tot]=z;
			while (n%z==0) n/=z;
		}
	if (n>1) p[++tot]=n; n=N; ll z;
	for (int I=1;I<=tot;I++) {
		z=p[I];
		cnt=0; while (n%z==0) cnt++,n/=z;
		for (int i=1;i<=cnt;i++)
			dp[i]=dp[i-1]*z%mod;
		for (int i=1;i<=k;i++) {
			s=1;
			for (int j=1;j<=cnt;j++) {
				s=(s+dp[j])%mod;
				dp[j]=s*ksm(j+1,mod-2)%mod;
			}
		} ans=ans*dp[cnt]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}