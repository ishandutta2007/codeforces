#include<cstdio>
#include<cmath>
#define mod 998244353
#define N 100039
#define ll long long
#define I inline
#define re register
using namespace std;
int lazy[N],k,ks,n,a[N],b[N],g[N],pre[N];ll dp[N],f[129][N*2],tot;
I void add(int x){re int now=x/ks;tot+=dp[x];f[now][N-lazy[now]]+=dp[x];b[x]=-lazy[now];}
I void gets(int l,int r){
	re int now=l/ks,i;
	for(i=l;i<=r;i++) tot-=(b[i]+lazy[now]==k?dp[i]:0),f[now][b[i]+N]-=dp[i],b[i]++,f[now][b[i]+N]+=dp[i];
}
I void get(int l,int r){
	if(l/ks==r/ks)return gets(l,r);gets(l,l/ks*ks+ks-1);gets(r/ks*ks,r);
	for(re int i=l/ks+1;i<r/ks;i++) tot-=f[i][k-lazy[i]+N],lazy[i]++;
}
I void dels(int l,int r){
	re int now=l/ks,i;
	for(i=l;i<=r;i++) f[now][b[i]+N]-=dp[i],b[i]--,tot+=(b[i]+lazy[now]==k?dp[i]:0),f[now][b[i]+N]+=dp[i];
}
I void del(int l,int r){
	if(l/ks==r/ks)return dels(l,r);dels(l,l/ks*ks+ks-1);dels(r/ks*ks,r);
	for(re int i=l/ks+1;i<r/ks;i++) lazy[i]--,tot+=f[i][k-lazy[i]+N];
}
int main(){
//	freopen("1.in","r",stdin);
	re int i;scanf("%d%d",&n,&k);ks=sqrt(n*9);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) pre[i]=g[a[i]],g[a[i]]=i;dp[0]=1;add(0);
	for(i=1;i<=n;i++)pre[i]&&(del(pre[pre[i]],pre[i]-1),0),get(pre[i],i-1),tot%=mod,dp[i]=tot,add(i);
	printf("%lld\n",(dp[n]+mod)%mod);
}