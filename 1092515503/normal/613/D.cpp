#include<bits/stdc++.h>
using namespace std;
int n,m,dfn[200100][20],DFN[100100],TOT,LG[200100],dep[100100],in[100100],tot,sz[100100];
namespace real{
	vector<int>v[100100];
	void dfs(int x,int fa){
		dfn[in[x]=++tot][0]=x,dep[x]=dep[fa]+1,DFN[x]=++TOT;
		for(auto y:v[x])if(y!=fa)dfs(y,x),dfn[++tot][0]=x;
	}	
}
int MIN(int x,int y){
	return dep[x]<dep[y]?x:y;
}
int LCA(int x,int y){
	x=in[x],y=in[y];
	if(x>y)swap(x,y);
	int k=LG[y-x+1];
	return MIN(dfn[x][k],dfn[y-(1<<k)+1][k]);
}
namespace imag{
	int stk[100100],tp,sz[100100],res,a[100100];
	vector<int>v[100100];
	bool cmp(int x,int y){
		return DFN[x]<DFN[y];
	}
	void ins(int x){
		sz[x]=1;
		if(!tp){stk[++tp]=x;return;}
		int lca=LCA(x,stk[tp]);
		while(tp>=2&&dep[lca]<dep[stk[tp-1]])v[stk[tp-1]].push_back(stk[tp]),tp--;
		if(tp&&dep[lca]<dep[stk[tp]])v[lca].push_back(stk[tp--]);
		if(!tp||stk[tp]!=lca)stk[++tp]=lca;
		stk[++tp]=x;
	}
	void fin(){
		while(tp>=2)v[stk[tp-1]].push_back(stk[tp]),tp--;
		tp--;
	}
	void dfs1(int x){
		for(auto y:v[x]){
			if(sz[x]&&sz[y]&&dep[y]==dep[x]+1)res=-1;
			dfs1(y);
		}
	}
	void dfs2(int x){
		int tmp=sz[x];
		for(auto y:v[x]){
			dfs2(y);
			if(tmp&&sz[y])res++;
			if(!tmp)sz[x]+=sz[y];
		}
		if(!tmp&&sz[x]>1)sz[x]=0,res++;
	}
	void dfs3(int x){
		sz[x]=0;
		for(auto y:v[x])dfs3(y);
		v[x].clear();
	}
	void work(){
		int q;
		res=0,scanf("%d",&q);
		for(int i=1;i<=q;i++)scanf("%d",&a[i]);
		sort(a+1,a+q+1,cmp);
		if(a[1]!=1)stk[++tp]=1;
		for(int i=1;i<=q;i++)ins(a[i]); 
		fin();
		dfs1(1);
		if(res==-1)puts("-1");
		else dfs2(1),printf("%d\n",res);
		dfs3(1);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),real::v[x].push_back(y),real::v[y].push_back(x);
	real::dfs(1,0);
	for(int i=2;i<=tot;i++)LG[i]=LG[i>>1]+1;
	for(int j=1;j<=LG[tot];j++)for(int i=1;i+(1<<j)<=tot;i++)dfn[i][j]=MIN(dfn[i][j-1],dfn[i+(1<<(j-1))][j-1]);
	scanf("%d",&m);
	while(m--)imag::work();
	return 0;
}