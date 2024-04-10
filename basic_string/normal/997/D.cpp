#include<bits/stdc++.h>
using namespace std;
const int N=4009,K=79,P=998244353;
int f[N][K],g[N][K],id[N],ps[N],ct,fc[K],iv[K],fciv[K],he[N],to[N<<1],ne[N<<1],sz[N],mx[N],a[K],a2[K],rt,n,w;
bool b[N];
void getr(int x,int y){
	sz[x]=1,mx[x]=0,ps[id[x]=++ct]=x;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]]&&j!=y){
		getr(j,x),sz[x]+=sz[j];
		if(mx[x]<sz[j])mx[x]=sz[j];
	}
	if((mx[x]=max(mx[x],n-sz[x]))<mx[rt])rt=x;
}
void calc(int x){
	int i,j,k,l,o;
	for(i=1;i<=ct;++i)memset(f[i],0,w+1<<2),memset(g[i],0,w+1<<2);
	f[id[x]][0]=g[id[x]][0]=1;
	for(i=1;i<=w;++i)for(j=1;j<=ct;++j)for(k=he[ps[j]];k;k=ne[k])if(!b[l=to[k]]){
		if(o=id[l],i==1||l!=x)f[j][i]=(f[j][i]+f[o][i-1])%P;
		g[j][i]=(g[j][i]+g[o][i-1])%P;
	}
	for(i=0,j=id[x];i<=w;++i)a[i]=(a[i]+g[j][i])%P;
	for(i=0;i<=w;++i)for(j=0,l=i;j<=i;++j,--l)for(k=1;k<=ct;++k)if(ps[k]!=x)a[i]=(a[i]+f[k][j]*1ll*g[k][l])%P;
}
void work(int x){
	calc(x),b[x]=1;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]])mx[rt=ct=0]=n=sz[j],getr(j,0),work(rt);
}
int main(){
	int m,i,j,k,t=0,ans=0;
	scanf("%d%d%d",&n,&m,&w),fc[0]=fc[1]=iv[1]=fciv[0]=fciv[1]=1;
	for(i=2;i<=w;++i)iv[i]=(P-P/i)*1ll*iv[P%i]%P,fc[i]=fc[i-1]*1ll*i%P,fciv[i]=fciv[i-1]*1ll*iv[i]%P;
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t; 
	}
	mx[0]=n,getr(1,0),work(rt),memcpy(a2,a,w+1<<2),memset(a,0,w+1<<2),memset(he,0,sizeof(he)),memset(b,0,sizeof(b)),t=0,n=m;
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t; 
	}
	mx[rt=ct=0]=n,getr(1,0),work(rt);
	for(i=0;i<=w;++i)ans=(ans+a[i]*1ll*a2[w-i]%P*fc[w]%P*fciv[i]%P*fciv[w-i])%P;
	printf("%d",ans);
	return 0;
}