#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=4e5+3;
#define ll long long
int he[N],to[M],len[M],ne[M],st[N],w[N],tp,b[N];
ll f[N],p[N],q[N],s[N],o[N],ans2;
int getc(int x,int y){
	if(b[x])return x;
	b[x]=2;
	for(int i=he[x],j,k;i;i=ne[i])if((j=to[i])!=y){
		k=getc(j,x);
		if(k)return st[++tp]=x,w[tp]=len[i],b[x]=1,k==x?0:k;
	}
	return 0;
}
void dfs(int x,int y){
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y&&b[j]!=1){
		dfs(j,x),ans2=max(ans2,f[x]+f[j]+len[i]),f[x]=max(f[x],f[j]+len[i]);
	}
}
int main(){
	int n,i,j,k,l,t=0;
	ll ans=1e18,u,v,o,q;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d%d",&j,&k,&l);
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	getc(1,0);
	for(i=1;i<=tp;++i)dfs(st[i],0);
	for(i=1,u=v=0;i<tp;++i){
		s[i+1]=max(s[i],f[st[i]]+u+v),u=max(u,f[st[i]]-v),p[i+1]=max(p[i],f[st[i]]+v+w[1]),v+=w[i+1];
	}
	for(i=tp,u=v=o=q=0;i;--i){
		o=max(o,f[st[i]]+u+v),u=max(u,f[st[i]]-v),q=max(q,f[st[i]]+v),ans=min(ans,max(max(s[i],o),p[i]+q)),v+=w[i];
	}
	printf("%lld",max(ans,ans2));
	return 0;
}