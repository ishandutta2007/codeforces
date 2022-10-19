#include<bits/stdc++.h>
using namespace std;
int n,m,q,id[300100],lim,tree[300100],totans;
int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int deco(){
	int x=(read()+totans)%n;
	if(!x)x=n;
//	printf("DECO:%d\n",x);
	return id[x];
}
namespace ECC{
	int dfn[300100],low[300100],tot,stk[300100],tp,head[300100],cnt,col[300100],c;
	struct node{
		int to,next;
	}edge[1200100];
	void ae(int u,int v){
//		printf("%d %d\n",u,v);
		edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
	}
	void Tarjan(int x,int fa){
		low[x]=dfn[x]=++tot,stk[++tp]=x;
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			if(!dfn[y=edge[i].to])Tarjan(y,i),low[x]=min(low[x],low[y]);
			else if((i^fa)!=1)low[x]=min(low[x],dfn[y]); 
		}
		if(low[x]!=dfn[x])return;
		c++;
		int y;
		do col[y=stk[tp--]]=c;while(y!=x);
	}
}
namespace Tree{
	vector<int>v[300100];
	int dfn[300100],tot,anc[300100][20],dep[300100];
	int LCA(int x,int y){
		if(dep[x]>dep[y])swap(x,y);
		for(int i=19;i>=0;i--)if(dep[x]<=dep[y]-(1<<i))y=anc[y][i];
		if(x==y)return x;
		for(int i=19;i>=0;i--)if(anc[x][i]!=anc[y][i])x=anc[x][i],y=anc[y][i];
		return anc[x][0];
	}
	void dfs(int x,int fa,int ID){
		tree[x]=ID,dfn[x]=++tot,dep[x]=dep[fa]+1,anc[x][0]=fa;
		for(int i=1;anc[x][i-1];i++)anc[x][i]=anc[anc[x][i-1]][i-1];
		for(auto y:v[x])if(y!=fa)dfs(y,x,ID);
	}
	namespace imag{
		int stk[300100],tp,num[300100],len,ed,inq[300100],all,U[300100],V[300100];
		vector<int>sp;
		void ins(int x){
			sp.push_back(x);
		    if(!tp){stk[++tp]=x;return;}
		    int lca=LCA(x,stk[tp]);
		    while(tp>=2&&dep[lca]<dep[stk[tp-1]])ECC::ae(stk[tp-1],stk[tp]),tp--;
		    if(tp&&dep[lca]<dep[stk[tp]])ECC::ae(lca,stk[tp--]);
		    if(!tp||stk[tp]!=lca)stk[++tp]=lca,sp.push_back(lca);
		    stk[++tp]=x;
		}
		void fin(){
			while(tp>=2)ECC::ae(stk[tp-1],stk[tp]),tp--;
        	tp=0;
		}
		bool solve(int ip){
			all=len=read(),ed=read();
			for(int i=1;i<=len;i++)inq[i]=num[i]=deco();
			for(int i=1;i<=ed;i++)U[i]=deco(),V[i]=deco(),num[++all]=U[i],num[++all]=V[i];
			sort(num+1,num+all+1,[](int x,int y){return tree[x]==tree[y]?dfn[x]<dfn[y]:tree[x]<tree[y];});
			all=unique(num+1,num+all+1)-num-1;
//			printf("QWQ:");for(int i=1;i<=len;i++)printf("%d ",inq[i]);puts("");
//			for(int i=1;i<=ed;i++)printf("(%d,%d)",U[i],V[i]);puts("");
//			printf("%d::",all);for(int i=1;i<=all;i++)printf("%d ",num[i]);puts("");
			ECC::tot=ECC::cnt=ECC::c=0;
			for(int i=1;i<=ed;i++)ECC::ae(U[i],V[i]);
			for(int i=1;i<=all;i++){
				if(tree[num[i]]!=tree[num[i-1]]){
					fin();
					if(num[i]!=tree[num[i]])sp.push_back(tree[num[i]]),stk[++tp]=tree[num[i]];
				}
				ins(num[i]);
			}
			fin();
			for(int i=1;i<=all;i++)if(!ECC::dfn[num[i]])ECC::Tarjan(num[i],-1);
			bool ok=true;
			for(int i=2;i<=len;i++)if(ECC::col[inq[i]]!=ECC::col[inq[i-1]])ok=false;
			for(auto i:sp)ECC::head[i]=-1,ECC::col[i]=ECC::dfn[i]=ECC::low[i]=0;
			sp.clear();
			if(!ok)return false;
			(totans+=ip)%=n;
			return true;
		}
	}
}
int main(){
	n=read(),m=read(),q=read(),memset(ECC::head,-1,sizeof(ECC::head));
	for(int i=1,x,y;i<=m;i++)x=read(),y=read(),ECC::ae(x,y);
	for(int i=1;i<=n;i++)if(!ECC::dfn[i])ECC::Tarjan(i,-1);
	lim=ECC::c;for(int i=1;i<=n;i++)id[i]=ECC::col[i];
	for(int i=1;i<=n;i++)for(int j=ECC::head[i];j!=-1;j=ECC::edge[j].next)if(id[i]!=id[ECC::edge[j].to])Tree::v[id[i]].push_back(id[ECC::edge[j].to]);
	for(int i=1;i<=lim;i++)ECC::head[i]=-1,ECC::col[i]=ECC::dfn[i]=ECC::low[i]=0;
	for(int i=1;i<=lim;i++)if(!tree[i])Tree::dfs(i,0,i);
//	for(int i=1;i<=n;i++)printf("%d ",id[i]);puts("");
//	for(int i=1;i<=lim;i++)printf("%d ",tree[i]);puts("");
	for(int i=1;i<=q;i++)puts(Tree::imag::solve(i)?"YES":"NO");
	return 0;
}
/*
15 14 5
1 2
2 3
2 4
4 5
4 6
6 7
6 8
8 9
8 10
10 11
11 12
12 13
13 14
13 15

4 2
12 13 14 4
14 5
7 14
*/