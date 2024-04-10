#include<bits/stdc++.h>
using namespace std;
int T,n,a[100100],b[100100],A[100100],B[100100];
vector<int>v[100100];
int col[100100],c,tot,dfn[100100],low[100100],stk[100100],tp,deg[100100];
void Tarjan(int x){
	dfn[x]=low[x]=++tot,stk[++tp]=x;
	for(auto y:v[x]){
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(!col[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]!=dfn[x])return;
	c++;int y;do col[y=stk[tp--]]=c;while(y!=x);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),A[i]=i;
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),B[i]=i;
		sort(A+1,A+n+1,[](int x,int y){return a[x]<a[y];});
		sort(B+1,B+n+1,[](int x,int y){return b[x]<b[y];});
		for(int i=2;i<=n;i++)v[A[i]].push_back(A[i-1]);
		for(int i=2;i<=n;i++)v[B[i]].push_back(B[i-1]);
		for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
		for(int i=1;i<=n;i++)for(auto j:v[i])if(col[i]!=col[j])deg[col[j]]++; 
		for(int i=1;i<=n;i++)printf("%d",!deg[col[i]]),dfn[i]=low[i]=col[i]=0,v[i].clear();puts("");
		for(int i=1;i<=c;i++)deg[i]=0;c=tot=0;
	}
	return 0;
}