/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,X[200100],Y[200100],K;
vector<int>v[100100];
int dsu[100100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
int anc[100100][20],dep[100100];
bool merge(int x,int y){x=find(x),y=find(y);if(x==y)return false;dsu[x]=y;return true;}
int dfn[100100],sz[100100],tot;
int dif[100100];
void dfs(int x,int fa){
	anc[x][0]=fa,dep[x]=dep[fa]+1;for(int i=1;i<20;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	dfn[x]=++tot,sz[x]=1;for(auto y:v[x])if(y!=fa)dfs(y,x),sz[x]+=sz[y];
}
int locate(int x,int y){
	for(int i=19;i>=0;i--)if(dep[x]<dep[y]-(1<<i))y=anc[y][i];
	return y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)dsu[i]=i;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(merge(x,y))v[x].push_back(y),v[y].push_back(x);else ++K,X[K]=x,Y[K]=y;
	}
	dfs(1,0);
	for(int i=1;i<=K;i++){
		int x=X[i],y=Y[i];
		if(dfn[x]>dfn[y])swap(x,y);
		if(dfn[x]+sz[x]-1>=dfn[y]+sz[y]-1)
			x=locate(x,y),
			dif[1]++,dif[dfn[x]]--,
			dif[dfn[y]]++,dif[dfn[y]+sz[y]]--,
			dif[dfn[x]+sz[x]]++;
		else dif[dfn[x]]++,dif[dfn[x]+sz[x]]--,dif[dfn[y]]++,dif[dfn[y]+sz[y]]--;
	}
	for(int i=1;i<=n;i++)dif[i]+=dif[i-1];
	for(int i=1;i<=n;i++)printf("%d",dif[dfn[i]]==K);
	return 0;
}