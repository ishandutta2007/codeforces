#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=N*2; 
int he[N],to[M],ne[M],len[M],d[N],n;
struct T{
int r,l[N],t,f[N][19],g[N][19],sn[N],u[N],p[N],rk[N],s[N];
void dfs(int x,int y){
	if(d[x]>d[r])r=x;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)d[j]=d[x]+len[i],dfs(j,x);
}
void cp(int x){
	int i=he[x],j,k;
	for(;i;i=ne[i])if((j=to[i])!=f[x][0]){
		for(f[j][0]=x,g[j][0]=len[i],k=0;f[j][k];++k)f[j][k+1]=f[f[j][k]][k],g[j][k+1]=g[j][k]+g[f[j][k]][k];
		if(cp(j),l[j]+len[i]>l[x])l[x]=l[j]+len[i],sn[x]=j;
	}
	for(i=he[x];i;i=ne[i])if((j=to[i])!=f[x][0]&&j!=sn[x])u[p[++t]=j]=l[j]+len[i];
}
void get(int x){
	int i,j;
	d[x]=0,dfs(x,0),cp(r),u[p[++t]=r]=l[r],sort(p+1,p+t+1,[=](int x,int y){return u[x]>u[y];});
	for(i=1;i<=t;++i)s[i]=s[i-1]+u[p[i]];
	for(i=1;i<=t;++i)for(j=p[i];j;j=sn[j])rk[j]=i;
}
int p1(int x,int y){
	int w=l[x],i=18;
	for(;~i;--i)if(rk[f[x][i]]>=y)w+=g[x][i],x=f[x][i];
	return s[y-1]+g[x][0]+w;
}
int p2(int x,int y){
	int w=l[x],i=18;
	for(;~i;--i)if(rk[f[x][i]]>y)w+=g[x][i],x=f[x][i];
	return s[y]+g[x][0]+w-l[f[x][0]];
}
int qry(int x,int y){return y=2*y-1,rk[x]>y?max(p1(x,y),p2(x,y)):s[y];}
}A,B;
int main(){
	int q,i,j,k,l,t=0,o=0;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l),++d[j],++d[k],o+=l;
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	for(i=1,k=l=0;i<=n;++i)k+=d[i]==1;
	for(A.get(1),B.get(A.r);q--;){
		scanf("%d%d",&i,&j),i=(i+l-1)%n+1,j=(j+l-1)%n+1;
		printf("%d\n",l=2*j<k?max(A.qry(i,j),B.qry(i,j)):o);
	}
	return 0;
}