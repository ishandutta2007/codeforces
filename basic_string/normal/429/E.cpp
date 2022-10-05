#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=4e5+3;
int he[N],to[M],ne[M],x[N],y[N],a[N],d[N],g[N];
bool f[N],b[N]; 
void dfs(int x){b[x]=1;for(int i,j;i=he[x];)if(he[x]=ne[i],!f[j=i>>1])f[j]=1,dfs(to[i]),g[j]=i&1;}
int main(){
	int n,i,j,k,m=0,t=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i),a[++m]=x[i],a[++m]=++y[i];
	sort(a+1,a+m+1),m=unique(a+1,a+m+1)-a-1;
	for(i=1;i<=n;++i){
		j=lower_bound(a+1,a+m+1,x[i])-a,k=lower_bound(a+1,a+m+1,y[i])-a,++d[j],++d[k];
		ne[++t]=he[j],to[t]=k,he[j]=t,ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	for(i=1,j=0;i<=m;++i)if(d[i]&1){if(j)ne[++t]=he[j],to[t]=i,he[j]=t,ne[++t]=he[i],to[t]=j,he[i]=t,j=0;else j=i;}
	for(i=1;i<=m;++i)if(!b[i])dfs(i);
	for(i=1;i<=n;++i)printf("%d ",g[i]);
	return 0;
}