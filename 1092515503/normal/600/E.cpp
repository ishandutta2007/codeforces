#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,buc[100100],col[100100],mx,son[100100],sz[100100];
ll sum[100100],res[100100];
vector<int>v[100100];
void dfs1(int x,int fa){
	sz[x]=1;
	for(auto y:v[x])if(y!=fa){
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void Push(int x){sum[buc[x]]-=x,buc[x]++,sum[buc[x]]+=x;if(mx<buc[x])mx=buc[x];}
void Pop(int x){sum[buc[x]]-=x,buc[x]--,sum[buc[x]]+=x;if(!sum[mx])mx--;}
void dfs2(int x,int fa){//only push bucket
	Push(col[x]);
	for(auto y:v[x])if(y!=fa)dfs2(y,x);
}
void dfs3(int x,int fa){//only pop bucket
	Pop(col[x]);
	for(auto y:v[x])if(y!=fa)dfs3(y,x);
}
void dfs4(int x,int fa){//push bucket and get answer
	for(auto y:v[x])if(y!=fa&&y!=son[x])dfs4(y,x),dfs3(y,x);
	if(son[x])dfs4(son[x],x);
	Push(col[x]);
	for(auto y:v[x])if(y!=fa&&y!=son[x])dfs2(y,x);
	res[x]=sum[mx];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs1(1,0);
	dfs4(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",res[i]);
	return 0;
}