#include<cstdio>
#include<algorithm>
#define I inline
#define ll long long
#define N 500000
#define max(a,b) ((a)>(b)?(a):(b))
#define re register 
using namespace std;
int n,maxn,a[N+5],b[N+5],w[N+5];ll ans,pus,now,tot,f[N+5];const ll mod=1e9+7;
I void clear(){for(int i=1;i<=n;i++) f[i]=0;}
I void get(int x,int y){while(x<=n) f[x]+=y,x+=x&-x;}
I ll find(int x){ll ans=0;while(x) ans+=f[x],x-=x&-x;return ans%mod;}
I void swap(int &x,int &y){x^=y^=x^=y;}
I void work(int flag){
	re int i;clear();
	for(i=1;i<=n;i++) ans+=find(w[i]+flag)*a[i]%mod*(n-i+1)%mod,get(w[i],i);ans%=mod;
}
I int ls(int x){int l=0,r=n,mid;while(l+1<r) mid=l+r>>1,(b[mid]<x?l:r)=mid;return r;}
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&n);for(i=1;i<=n;i++)scanf("%d",&a[i]),ans+=(ll)a[i]*i%mod*(n-i+1)%mod,b[i]=a[i];
	sort(b+1,b+n+1);for(i=1;i<=n;i++) w[i]=ls(a[i]);
	work(0);for(i=1;i<=n/2;i++) swap(a[i],a[n-i+1]),swap(w[i],w[n-i+1]);work(-1);
	printf("%lld\n",(ans%mod+mod)%mod);
}