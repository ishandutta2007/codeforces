#include<bits/stdc++.h>
using namespace std;
int n,m;
namespace RSG{
	int cnt,fa[400100],sz[400100];
	vector<int>u[400100];
	vector<pair<int,int> >w[400100];
	void AE(int x,int y){u[x].push_back(y),u[y].push_back(x);}
	void dfs(int x){for(auto y:u[x])if(y!=fa[x])fa[y]=x,dfs(y);}
}using namespace RSG;
namespace GRA{
	vector<int>v[200100];
	int low[200100],dfn[200100],stk[200100],tot,tp;
	void Tarjan(int x){
		low[x]=dfn[x]=++tot,stk[++tp]=x;
		for(auto y:v[x]){
			if(!dfn[y]){
				Tarjan(y),low[x]=min(low[x],low[y]);
				if(dfn[x]>low[y])continue;
				++cnt;int z;do AE(z=stk[tp--],cnt);while(z!=y);
				AE(x,cnt);
			}else low[x]=min(low[x],dfn[y]);
		}
	}
}using namespace GRA;
int in[200100];
int S,T;
vector<int>p,q,r;
void iter(int x,int fa){
	in[x]=1,p.push_back(x);
	for(auto y:v[x]){
		if(y==fa)continue;
		if(!in[y])iter(y,x);
		else S=y;
		return;
	}
}
void reit(int x,int fa){
	q.push_back(x),in[x]=2;
	for(auto y:v[x]){
		if(y==fa||y==S)continue;
		if(!in[y])reit(y,x);
		else if(in[y]==1)T=y;
		if(T)return;
	}
	q.pop_back();
}
int main(){
	scanf("%d%d",&n,&m),cnt=n;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i),tp=0;
	for(int i=1;i<=n;i++)if(!fa[i])dfs(i);
	for(int x=1;x<=n;x++){
		for(auto y:v[x]){
			if(fa[x]==fa[y])w[fa[x]].emplace_back(x,y);
			else if(fa[fa[x]]==y)w[fa[x]].emplace_back(x,y);
			else if(fa[fa[y]]==x)w[fa[y]].emplace_back(x,y);
			else assert(0);
		}
		v[x].clear();
	}
	for(int i=n+1;i<=cnt;i++){
		if(w[i].size()<=(u[i].size()<<1))continue;
		puts("YES");
		for(auto x:w[i])v[x.first].push_back(x.second);
		for(S=1;S<=n;S++){
			if(v[S].size()<=2)continue;
			p.clear(),q.clear(),r.clear();
			memset(in,0,sizeof(in));
//			printf("%d\n",S);
			iter(S,0);
//			printf("%d:",S);for(auto x:p)printf("%d ",x);puts("");
//			for(int x=1;x<=n;x++)printf("%d",in[x]);puts("");
			p.push_back(S); 
			reverse(p.begin(),p.end());
			while(p.back()!=S)in[p.back()]=false,p.pop_back();
			for(auto y:v[S])if(y!=p[1]&&y!=p[p.size()-2]){
				q.push_back(S);
				if(in[y])T=y;else reit(y,S);
				q.push_back(T);
//				printf("%d\n",T);
				while(p.back()!=T)r.push_back(p.back()),p.pop_back();
				r.push_back(T);
				printf("%d ",p.size());for(auto x:p)printf("%d ",x);puts("");
				printf("%d ",q.size());for(auto x:q)printf("%d ",x);puts("");
				printf("%d ",r.size());for(auto x:r)printf("%d ",x);puts("");
				return 0;
			}
		}
		return 0;
	}
	puts("NO");
	return 0;
}