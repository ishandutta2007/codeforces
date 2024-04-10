#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int T,n,m;
int cnt,rt[600100];
mt19937 rnd(17680321);
#define lson t[x].ch[0]
#define rson t[x].ch[1]
struct Treap{int ch[2],val,mvl,rd;}t[600100];
void pushup(int x){t[x].mvl=max(max(t[lson].mvl,t[rson].mvl),t[x].val);}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(t[x].rd>t[y].rd)return t[x].ch[1]=merge(t[x].ch[1],y),pushup(x),x;
	else return t[y].ch[0]=merge(x,t[y].ch[0]),pushup(y),y;
}
void splitbykey(int x,int k,int&u,int&v){
	if(!x)return u=v=0,void();
	if(t[lson].mvl>k||t[x].val>k)v=x,splitbykey(lson,k,u,lson);
	else u=x,splitbykey(rson,k,rson,v);
	pushup(x);
}
void merge(int&rt,vector<int>v){
	int a=rt,b,c;rt=0;
	for(auto x:v){
		splitbykey(a,x,a,c);
		// printf("split:%d,%d\n",a,c);
		b=++cnt;t[b].val=t[b].mvl=x,t[b].ch[0]=t[b].ch[1]=0,t[b].rd=rnd();
		rt=merge(rt,merge(a,b));
		a=c;
	}
	rt=merge(rt,a);
}
void iterate(int x){if(x)iterate(lson),printf("%d ",t[x].val-1),iterate(rson);}
namespace Tre{
vector<int>v[600100];
int c,fa[600100];
void ae(int x){v[x].push_back(c),v[c].push_back(x);}
void dfs_init(int x){for(auto y:v[x])if(y!=fa[x])fa[y]=x,dfs_init(y);}
int locate(int x,int y){return fa[x]==fa[y]||fa[fa[x]]==y?fa[x]:fa[y];}
vector<pair<int,int> >u[600100];
void insert(int x,int y){
	int z=locate(x,y);
	// printf("insert:%d,%d:%d\n",x,y,z);
	x=lower_bound(v[z].begin(),v[z].end(),x)-v[z].begin();
	y=lower_bound(v[z].begin(),v[z].end(),y)-v[z].begin();
	u[z].emplace_back(x,y);
}
set<int>s[600100];
int q[600100],Q;
list<int>ls;
vector<int>w[600100];
vector<int>cir;
list<int>::iterator it[600100];
int id[600100];
bool func(int _){
	// printf("%d:\n",_);
	// for(auto x:u[_])printf("<%d,%d>\n",x.first,x.second);
	for(auto x:u[_])s[x.first].insert(x.second),s[x.second].insert(x.first);
	for(int i=0;i<v[_].size();i++)if(s[i].size()<=2)q[Q++]=i;
	// printf("%d|",Q);for(int i=0;i<v[_].size();i++)printf("%d ",s[i].size());puts("");
	for(int i=0;i<Q;i++){
		int x=q[i];
		// printf("%d,%d\n",x,s[x].size());
		if(s[x].size()==1){ls.push_back(x);continue;}
		int y=*s[x].begin(),z=*s[x].rbegin();
		bool oky=(s[y].size()<=2),okz=(s[z].size()<=2);
		s[y].erase(x),s[z].erase(x);
		s[y].insert(z),s[z].insert(y);
		if(!oky&&s[y].size()<=2)q[Q++]=y;
		if(!okz&&s[z].size()<=2)q[Q++]=z;
	}
	bool ret=(Q==v[_].size())&&(ls.size()==2);
	if(ret){
		for(auto i=ls.begin();i!=ls.end();i++)it[*i]=i;
		// for(auto i:ls)printf("%d ",i);puts("QWQ");
		for(int i=Q-1;i>=0;i--){
			int x=q[i];
			if(s[x].size()==1)continue;
			int y=*s[x].begin(),z=*s[x].rbegin();
			// printf("%d-%d-%d\n",y,x,z);
			if(it[y]!=ls.begin()&&prev(it[y])==it[z])it[x]=ls.insert(it[y],x);
			else if(it[z]!=ls.begin()&&prev(it[z])==it[y])it[x]=ls.insert(it[z],x);
			else if(it[y]==ls.begin()&&next(it[z])==ls.end())it[x]=ls.insert(it[y],x);
			else if(it[z]==ls.begin()&&next(it[y])==ls.end())it[x]=ls.insert(it[z],x);
			else {ret=false;break;}
			// for(auto i:ls)printf("%d ",i);puts("QAQ");
		}
		if(ret){
			for(auto x:ls)cir.push_back(x);
			for(auto x:u[_])w[x.first].push_back(x.second),w[x.second].push_back(x.first);
			for(int i=0;i<cir.size();i++)id[cir[i]]=i;
			for(int i=0;i<cir.size();i++){
				int x=cir[i];
				sort(all(w[x]),[](const int&x,const int&y){return id[x]<id[y];});
				// printf("%d:\n",x);
				// for(auto y:w[x])printf("%d ",y);puts("");
				rotate(w[x].begin(),find(all(w[x]),cir[(i+1)%cir.size()]),w[x].end());
				// for(auto y:w[x])printf("%d ",y);puts("");
			}
			if(w[0][0]>w[0].back())
				for(int i=0;i<v[_].size();i++)reverse(all(w[i]));
			for(int i=0;i<v[_].size();i++){
				for(auto&x:w[i])x=v[_][x];
				// for(auto x:w[i])printf("%d ",x);puts("");
				merge(rt[v[_][i]],w[i]);
			}
		}
	}
	for(int i=0;i<v[_].size();i++)w[i].clear(),s[i].clear();cir.clear(),ls.clear();Q=0;
	u[_].clear();
	return ret;
}
}
namespace Gra{
vector<int>v[600100];
int dfn[600100],low[600100],stk[600100],tp,tot;
void Tarjan(int x){
	dfn[x]=low[x]=++tot,stk[++tp]=x;
	for(auto y:v[x]){
		if(!dfn[y]){
			Tarjan(y),low[x]=min(low[x],low[y]);
			if(low[y]<dfn[x])continue;
			Tre::c++;
			int z;do Tre::ae(z=stk[tp--]);while(z!=y);
			Tre::ae(x);
		}else low[x]=min(low[x],dfn[y]);
	}
}
void init(){
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),x++,y++,v[x].push_back(y),v[y].push_back(x);
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i),tp=0;
	for(int i=1;i<=n;i++)dfn[i]=low[i]=0;tot=0;
	for(int i=n+1;i<=Tre::c;i++)sort(all(Tre::v[i]));
	for(int i=1;i<=n;i++)if(!Tre::fa[i])Tre::dfs_init(i);
	for(int i=1;i<=n;i++)for(auto j:v[i])if(i<j)Tre::insert(i,j);
	for(int i=1;i<=n;i++)v[i].clear();
}
}
void mina(){
	scanf("%d%d",&n,&m),Tre::c=n;Gra::init();
	bool ok=true;
	for(int i=n+1;i<=Tre::c;i++)ok&=Tre::func(i);
	if(ok){
		puts("YES");
		for(int i=1;i<=n;i++)iterate(rt[i]),puts("");
	}else puts("NO");
	for(int i=1;i<=n;i++)rt[i]=0;cnt=0;
	for(int i=1;i<=Tre::c;i++)Tre::v[i].clear(),Tre::fa[i]=0;
}
int main(){
	// freopen("granddesign.in","r",stdin);
	// freopen("granddesign.out","w",stdout);
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1

4 6
1 2
2 3
3 4
4 1
1 3
2 4
*/