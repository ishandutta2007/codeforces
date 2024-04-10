#include<cstdio>
#define G 3
#define mod 998244353
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
inline ll mpow(ll x,int y=mod-2){ll ans=1;while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}
const ll invG=mpow(G);
int tr[200039],n,m,k,x,y,z;
ll f0[200039],f1[200039],f2[200039],g[200039];
ll a[200039],ans,a1[200039],a2[200039],a3[200039],b1[200039],b2[200039],b3[200039];
inline void make(int x){for(int i=0;i<x;i++) tr[i]=(tr[i>>1]>>1)|((i&1)?x>>1:0);}
inline void swap(ll &x,ll &y){x^=y^=x^=y;}
inline void ntt(ll *f,int n,int flag){
	register int i,j,k;ll pus,now,key;
	for(i=0;i<n;i++) if(i<tr[i]) swap(f[i],f[tr[i]]);
	for(i=2;i<=n;i<<=1){
		for(key=mpow(flag?G:invG,(mod-1)/i),j=0;j<n;j+=i){
			for(pus=1,k=j;k<j+i/2;k++) now=f[k+i/2]*pus%mod,f[k+i/2]=(f[k]-now+mod)%mod,f[k]=(f[k]+now)%mod,pus=pus*key%mod;
		}
	}
}
using namespace std;
inline void solve(int l,int r){
	if(l==r){f0[l]=(f0[l]+g[l]*l%mod*l)%mod;f1[l]=(f1[l]+g[l]*(l+1)%mod*(l+1))%mod;f2[l]=(f2[l]+g[l]*(l+2)%mod*(l+2))%mod;return;}
	int mid=l+r>>1,m=(r-l+1)<<1,i,invn=mpow(m);solve(l,mid);make(m);
	for(i=0;i<m;i++) a1[i]=b1[i]=a2[i]=b2[i]=a3[i]=b3[i]=0;
	for(i=0;i<=mid-l;i++) a1[i]=f0[l+i];ntt(a1,m,1);for(i=0;i<=r-l;i++) b1[i]=g[i]*i%mod*i%mod;ntt(b1,m,1);
	for(i=0;i<=mid-l;i++) a2[i]=f1[l+i];ntt(a2,m,1);for(i=0;i<=r-l;i++) b2[i]=g[i]*(i+1)%mod*(i+1)%mod;ntt(b2,m,1);
	for(i=0;i<=mid-l;i++) a3[i]=f2[l+i];ntt(a3,m,1);for(i=0;i<=r-l;i++) b3[i]=g[i]*(i+2)%mod*(i+2)%mod;ntt(b3,m,1);
	for(i=0;i<m;i++) a[i]=a1[i]*b1[i];ntt(a,m,0);
	for(i=mid-l;i<r-l;i++) f0[l+i+1]=(f0[l+i+1]+a[i]*invn)%mod;
	for(i=0;i<m;i++) a[i]=a2[i]*b2[i];ntt(a,m,0);
	for(i=max(mid-l-2,0);i<r-l-2;i++) f0[l+i+3]=(f0[l+i+3]+a[i]*invn)%mod;
	for(i=mid-l;i<r-l;i++) f2[l+i+1]=(f2[l+i+1]+a[i]*invn)%mod;
	for(i=0;i<m;i++) a[i]=a2[i]*b1[i];ntt(a,m,0);
	for(i=mid-l;i<r-l;i++) f1[l+i+1]=(f1[l+i+1]+a[i]*invn)%mod;
	for(i=0;i<m;i++) a[i]=a3[i]*b2[i];ntt(a,m,0);
	for(i=max(mid-l-2,0);i<r-l-2;i++) f1[l+i+3]=(f1[l+i+3]+a[i]*invn)%mod;
	for(i=0;i<m;i++) a[i]=a3[i]*b3[i];ntt(a,m,0);
	for(i=max(mid-l-2,0);i<r-l-2;i++) f2[l+i+3]=(f2[l+i+3]+a[i]*invn)%mod;
	solve(mid+1,r);
}
int main(){
	register int i;
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d",&n);
	for(m=1;m<n;m<<=1);g[0]=1;g[2]=1;
	for(i=4;i<=m;i++) g[i]=(g[i-2]+g[i-4])%mod;
	solve(0,m-1);ans=n*(g[n-1]+g[n-3])%mod*(n-1)%mod*(n-1)%mod;
	for(i=2;i<=n-2;i++) ans=(ans+(g[i-1]*f0[n-i-1]+2*g[i-2]*f1[n-i-2]+(i^2&&i^(n-2))*g[i-3]*f2[n-i-3])%mod*i%mod*(i-1)%mod*(i-1))%mod;
	printf("%lld\n",ans);
}