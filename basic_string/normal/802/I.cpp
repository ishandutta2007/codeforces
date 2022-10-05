#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
char s[N];
int u[N],v[N],sa[N],h[N],t[N],f[N],id[N],sz[N],p[N];
long long ans;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void mg(int x,int y,int w){
	f[x]=y;
	ans+=(p[x]-w)*1ll*sz[x]*sz[x]+(p[y]-w)*1ll*sz[y]*sz[y];
	p[y]=w;
	sz[y]+=sz[x];
}
int main(){
	int*rk=u,*b=v,T,n,m,i,j,k,x,y;
	for(scanf("%d",&T);T--;printf("%lld\n",ans)){
		scanf("%s",s+1),n=strlen(s+1),m=131,k=u[n+1]=v[n+1]=ans=0;
		for(memset(t,0,m*4+4),i=1;i<=n;++i)++t[s[i]];
		for(i=1;i<=m;++i)t[i]+=t[i-1];
		for(i=n;i;--i)sa[t[rk[i]=s[i]]--]=i;
		for(i=1;k<n;i*=2,m=k){
			for(memset(t,0,m*4+4),k=0,j=n-i+1;j<=n;++j)b[++k]=j;
			for(j=1;j<=n;++j)if(++t[rk[j]],sa[j]>i)b[++k]=sa[j]-i;
			for(j=1;j<=m;++j)t[j]+=t[j-1];
			for(j=n;j;--j)sa[t[rk[b[j]]]--]=b[j];
			for(j=1,k=y=0,swap(rk,b);j<=n;++j,y=x)x=sa[j],rk[x]=b[x]==b[y]&&b[x+i]==b[y+i]?k:++k;
		}
		for(i=1,k=0;i<=n;h[rk[i++]]=k)if(rk[i]>1)for(k=max(k-1,0),j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
		for(i=1;i<=n;++i)f[i]=id[i]=i,sz[i]=1,p[i]=n-i+1;
		sort(id+2,id+n+1,[](int x,int y){return h[x]>h[y];});
		for(i=2;i<=n;++i)mg(gf(sa[id[i]]),gf(sa[id[i]-1]),h[id[i]]);
		if(p[gf(1)])ans+=n*1ll*n;
	}
	return 0;
}