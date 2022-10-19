#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,mxd[100100],son[100100],smd[100100],cc[100100],dep[100100],dis,anc[100100][17];
vector<int>v[100100];
int dfs_dis(int x,int fa){
	if(x==b)return 0;
	for(auto y:v[x])if(y!=fa){int d=dfs_dis(y,x);if(d!=-1)return d+1;}
	return -1;
}
void dfs_DP1(int x,int fa){
	mxd[x]=smd[x]=cc[x]=0;
	for(auto y:v[x])if(y!=fa){
		dfs_DP1(y,x);
		if(mxd[y]+1>=dis)cc[x]++;
		if(mxd[y]+1>mxd[x])smd[x]=mxd[x],mxd[x]=mxd[y]+1;
		else smd[x]=max(smd[x],mxd[y]+1);
	}
}
void dfs_DP2(int x,int fa){
	for(auto y:v[x])if(y!=fa){
		int mdd=(mxd[y]+1==mxd[x]?smd[x]:mxd[x])+1;
		if(mdd>=dis)cc[y]++;
		if(mdd>mxd[y])smd[y]=mxd[y],mxd[y]=mdd;
		else smd[y]=max(smd[y],mdd);
		dfs_DP2(y,x);
	}
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=16;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[y][i];
	if(x==y)return x;
	for(int i=16;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
	return anc[x][0];
}
int KAC(int x,int k){for(int i=16;i>=0;i--)if(k>=(1<<i))x=anc[x][i],k-=1<<i;return x;}
void dfs_build(int x,int fa){
	dep[x]=dep[fa]+1,mxd[x]=0,son[x]=x;
	anc[x][0]=fa;for(int i=1;i<=16;i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(auto y:v[x])if(y!=fa){
		dfs_build(y,x);
		if(mxd[x]<mxd[y]+1)mxd[x]=mxd[y]+1,son[x]=son[y];
	}
}
void mina(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dis=dfs_dis(a,0);
	dfs_DP1(1,0),dfs_DP2(1,0);
	bool ok=false;
	for(int i=1;i<=n;i++)if(cc[i]>=3){
//		printf("HEHE:%d\n",i);
		dfs_build(i,0);
		for(int j=1;j<=n;j++){
			int c=LCA(a,b);
//			printf("%d,%d,%d,%d,%d,%d\n",a,b,c,dep[b],dep[c],mxd[a]);
			if(dep[b]-dep[c]<=mxd[a]){ok=true;break;}
			b=KAC(b,mxd[a]),a=son[a];
			swap(a,b);
		}
		break;
	}
	puts(ok?"YES":"NO");
	for(int i=1;i<=n;i++)v[i].clear();
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
10 8 9
1 2
1 3
3 4
4 5
1 6
1 7
7 8
7 9
6 10
*/