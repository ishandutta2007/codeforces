#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int he[N],to[N*2],ne[N*2],x,d,mx;
basic_string<int>q,f[N];
void qry(){
	printf("? %u ",q.size());
	for(auto i:q)printf("%d ",i);
	puts(""),fflush(stdout),scanf("%d%d",&x,&d);
}
void dfs(int x,int y,int z){
	f[z]+=x,mx=max(mx,z);
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)dfs(j,x,z+1);
}
int main(){
	int T,n,i,j,k,t,o,l,r,m,u;
	for(scanf("%d",&T);T--;scanf("%*s")){
		scanf("%d",&n),t=mx=0,memset(he+1,0,n*4);
		for(i=1;i<n;++i){
			scanf("%d%d",&j,&k);
			ne[++t]=he[j],to[t]=k,he[j]=t;
			ne[++t]=he[k],to[t]=j,he[k]=t;
		}
		for(i=1,q.clear();i<=n;++i)q+=i;
		qry(),o=d;
		for(i=0;i<=n;++i)f[i].clear();
		dfs(x,0,0),l=o/2,r=min(mx,o);
		while(l<=r){
			m=l+r>>1,q=f[m],qry();
			if(d>o)r=m-1;
			else l=m+1,u=x;
		}
		for(i=0;i<=n;++i)f[i].clear();
		dfs(u,0,0),q=f[o],qry(),printf("! %d %d\n",u,x),fflush(stdout);
	}
	return 0;
}