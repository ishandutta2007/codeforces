#include<bits/stdc++.h>
using namespace std;
int fa[100011],s[511],g[511][511],n,m,p,t1,t2,t3;
int fd(int x){return x==fa[x]?x:fa[x]=fd(fa[x]);}
void in(int x,int y){
	x=fd(x),y=fd(y);
	if(x!=y)fa[x]=y;
}
int main(){
	scanf("%d%d%d",&n,&m,&p),memset(g,0x3f3f3f3f,sizeof(g));
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=p;i++)scanf("%d",&s[i]),s[i]+=s[i-1],g[i][i]=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&t1,&t2,&t3);
		if(!t3)in(t1,t2);
		t1=lower_bound(s+1,s+p+1,t1)-s,t2=lower_bound(s+1,s+p+1,t2)-s;
//		printf("%d %d\n",t1,t2);
		g[t1][t2]=g[t2][t1]=min(g[t1][t2],t3);
	}
	for(int i=1;i<=p;i++)for(int j=s[i-1]+1;j<s[i];j++)if(fd(j)!=fd(j+1)){puts("No");return 0;}
	puts("Yes");
	for(int k=1;k<=p;k++)for(int i=1;i<=p;i++)for(int j=1;j<=p;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=p;i++){for(int j=1;j<=p;j++)printf("%d ",g[i][j]==0x3f3f3f3f?-1:g[i][j]);puts("");}
	return 0;
}