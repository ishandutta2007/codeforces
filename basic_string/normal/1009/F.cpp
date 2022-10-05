#include<cstdio>
const int N=1000009;
int he[N],to[N<<1],ne[N<<1],d[N],sn[N],ans[N],p[N],id[N],ct;
void dfs(int x,int y){
	for(register int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j!=y){
			dfs(j,x);
			if(d[x]<d[j])d[x]=d[j];
			if(d[sn[x]]<d[j])sn[x]=j;
		}
	}
	++d[x];
}
void dp(int x,int y){
	register int *f=&p[id[x]=++ct];
	f[ans[x]=0]=1;
	if(!sn[x])return;
	dp(sn[x],x),ans[x]=ans[sn[x]]?(ans[sn[x]]+1):0;
	for(register int i=he[x],j,k,*g;i;i=ne[i]){
		j=to[i];
		if(j==y||j==sn[x])continue;
		dp(j,x),g=&p[id[j]];
		for(k=1;k<=d[j];++k){
			f[k]+=g[k-1];
			if(f[k]>f[ans[x]]||(f[k]==f[ans[x]]&&k<ans[x]))ans[x]=k;
		}
	}
}
int main(){
	register int n,i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs(1,0),dp(1,0);
	for(i=1;i<=n;++i)printf("%d\n",ans[i]);
	return 0;
}