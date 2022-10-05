#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=2e5+9;
typedef int ar[N];
long long ans;
int to[M],len[M],ne[M],po[M],*pw=po+N,m,id,o;
ar d,up,dn,sz,fa,sn,he,l,r,p;
int inv(int a,int b){return a?(b*1ll*(a-inv(b%a,a))+1)/a%b:1;}
void dfs(int x,int y){
	fa[x]=y,sz[x]=1,p[l[x]=++id]=x;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y){
		up[j]=(up[x]+len[i]*1ll*pw[d[x]])%m,dn[j]=(dn[x]*10ll+len[i])%m,d[j]=d[x]+1,dfs(j,x),sz[x]+=sz[j];
		if(sz[j]>sz[sn[x]])sn[x]=j;
	}
	r[x]=id;
}
unordered_map<int,int>m1,m2;
void cal(int x){ans+=m1[(up[o]+(dn[o]*1ll*pw[d[x]-d[o]]%m+m-dn[x])*pw[d[o]*2-d[x]])%m]+m2[((up[o]-up[x]+m)*1ll*pw[-d[o]]+dn[o])%m*pw[-d[o]]%m];}
void ins(int x){++m1[up[x]],++m2[dn[x]*1ll*pw[-d[x]]%m];}
void dp(int x){
	int i=he[x],j,k;
	for(;i;i=ne[i])if((j=to[i])!=fa[x]&&j!=sn[x])dp(j),m1=m2={};
	if(sn[x])dp(sn[x]);
	for(i=he[o=x];i;i=ne[i])if((j=to[i])!=fa[x]&&j!=sn[x]){
		for(k=l[j];k<=r[j];++k)cal(p[k]);
		for(k=l[j];k<=r[j];++k)ins(p[k]);
	}
	cal(x),ins(x);
}
int main(){
	int n,i,j,k,l,t=0;
	scanf("%d%d",&n,&m),pw[0]=1,l=inv(10,m);
	for(i=1;i<n;++i)pw[i]=pw[i-1]*10ll%m,pw[-i]=pw[1-i]*1ll*l%m;
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l),++j,++k;
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	dfs(1,0),dp(1),printf("%lld",ans);
	return 0;
}