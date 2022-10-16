#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
typedef long long ll;
int n,m,k;
int fa[1111111];
#include<vector>
std::vector<int>v[1111111];
int t[1111111],w[1111111];
ll max(ll x,ll y){return(x<y)?y:x;}
struct pii{int x;ll v;};
int Id[1111111],ttt;
bool operator<(cpnst pii x,cpnst pii y)
{return x.x<y.x;}
#include<set>
std::set<pii>S[1111111];
void merge(int&x,int&y)
{
	if(S[x].size()<S[y].size())x^=y^=x^=y;
	for(auto g:S[y])
	{
		auto It=S[x].lower_bound(g);
		if((*It).x==g.x)g.v+=(*It).v,S[x].erase(It),S[x].insert(g);
		else S[x].insert(g);
	}
}
void adjust(int X,int T,ll V)
{
	pii tp=pii{T,V};
	ll SS=0;
	for(auto It=S[X].upper_bound(tp);It!=S[X].end();It=S[X].upper_bound(tp))
	{
		SS+=(*It).v;
		int pos=(*It).x;
		S[X].erase(It);

		if(SS>V)
		{
			S[X].insert(pii{pos,SS-V});
			break;
		}
	}auto It=S[X].lower_bound(tp);
	if(It!=S[X].end())if((*It).x==T)tp.v+=(*It).v,S[X].erase(It);
	S[X].insert(tp);
}
void dfs(int p=1)
{
	Id[p]=++ttt;
	for(auto tp:v[p])dfs(tp),merge(Id[p],Id[tp]);
	if(w[p])adjust(Id[p],t[p],w[p]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	register int i;
	for(i=2;i<=n;i++)scanf("%d",fa+i),v[fa[i]].push_back(i);
	int x,y,z;
	for(i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&z),t[x]=y,w[x]=z;
	dfs();
	ll ans=0;
	for(auto g:S[Id[1]])ans+=g.v;
	printf("%lld\n",ans);
}
/*
Just go for it.
*/