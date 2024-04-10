#include<bits/stdc++.h>
using namespace std;
int T,n,m,head[200100],cnt,dis[200100],dsu[200100],fi[200100],fp[200100];
struct node{int to,next,val;}edge[400100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void dfs(int x,int fa){
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa){
		if(edge[i].val==-1)dsu[y]=y,dis[y]=dis[x],fi[y]=i,fp[y]=dsu[x];
		else dsu[y]=dsu[x],dis[y]=dis[x]^edge[i].val;
		dfs(y,x);
	}
}
vector<int>v[200100];
int col[200100];
bool dye(int x){
	for(auto y:v[x]){
		int z=0;if(y<0)z=1,y=-y;
		if(col[y]==-1){
			col[y]=col[x]^z;
			if(!dye(y))return false;
		}else if(col[y]^col[x]^z)return false;
	}
	return true;
}
int main(){
	scanf("%d",&T),memset(head,-1,sizeof(head)),memset(col,-1,sizeof(col));
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
		dsu[1]=1,fi[1]=-1,dfs(1,0);
//		for(int i=1;i<=n;i++)printf("%d ",dsu[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",dis[i]);puts("");
		for(int i=1,x,y,z;i<=m;i++)
			scanf("%d%d%d",&x,&y,&z),z^=__builtin_parity(dis[x]^dis[y]),
			x=dsu[x],y=dsu[y],
//			printf("[%d %d %d]\n",x,y,z),
			v[x].push_back(z?-y:y),v[y].push_back(z?-x:x);
		bool ok=true;
		for(int i=1;i<=n;i++)if(dsu[i]==i&&col[i]==-1){col[i]=0;if(!dye(i)){ok=false;break;}}
		if(!ok)puts("NO");
		else{
			for(int i=2;i<=n;i++)if(dsu[i]==i)
				edge[fi[i]].val=edge[fi[i]^1].val=col[i]^col[fp[i]];
			puts("YES");
			for(int i=0;i<cnt;i+=2)printf("%d %d %d\n",edge[i^1].to,edge[i].to,edge[i].val);
		}
		for(int i=1;i<=n;i++)head[i]=col[i]=-1,v[i].clear();cnt=0;
	}
	return 0;
}
/*
1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1

2 4 0
3 4 1
2 3 1
*/