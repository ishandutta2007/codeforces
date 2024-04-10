#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
struct edg
{int v,c,x,y,Id;}e[333333];
struct UFS
{
	int fa[1111111];
	void init()
	{for(register int i=1;i<=1000000;i++)fa[i]=i;}
	int rt(int x){return(fa[x]^x)?fa[x]=rt(fa[x]):x;}
	bool merge(int x,int y){return x=rt(x),y=rt(y),fa[x]=y,x^y;}
}U;
int n,m,S;
typedef long long ll;
bool operator<(cpnst edg x,cpnst edg y){return x.v<y.v;}
#include<algorithm>
#include<vector>
std::vector<edg>v[333333];
int Dc;
int fa[333333][22],mx[333333][22],dep[1111111];
ll nw,cn;
bool vs[1111111];
int max(register int x,register int y){return(x<y)?y:x;}
void swap(register int&x,register int&y){x^=y^=x^=y;}
void dfs(int p=1,int f=0)
{
	fa[p][0]=f,dep[p]=dep[f]+1;
	for(register int i=0;fa[p][i];i++)
		fa[p][i+1]=fa[fa[p][i]][i],mx[p][i+1]=max(mx[p][i],mx[fa[p][i]][i]);
	for(auto t:v[p])
		if(t.y^f)
		{
			mx[t.y][0]=t.v,dfs(t.y,p);
			if(nw>cn-S/t.c)nw=cn-S/t.c,Dc=t.Id;
		}
}
int qmax(int x,int y)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	register int i;
	int ret=0;
	for(i=20;~i;i--)if(dep[fa[x][i]]>=dep[y])ret=max(ret,mx[x][i]),x=fa[x][i];
	if(x==y)return ret;
	for(i=20;~i;i--)if(fa[x][i]^fa[y][i])
		ret=max(ret,max(mx[x][i],mx[y][i])),x=fa[x][i],y=fa[y][i];
	return max(ret,max(mx[x][0],mx[y][0]));
}
void solve()
{
	register int i;
	for(i=1;i<=m;i++)
		if(!vs[i])
			if(nw>cn-qmax(e[i].x,e[i].y)+e[i].v-S/e[i].c)
				nw=cn-qmax(e[i].x,e[i].y)+e[i].v-S/e[i].c,Dc=e[i].Id;
}
bool reorder(edg x,edg y){return x.Id<y.Id;}
void answ()
{
	std::sort(e+1,e+m+1,reorder),e[Dc].v-=S/e[Dc].c,
	printf("%lld\n",nw);
	std::sort(e+1,e+m+1),U.init();
	for(register int i=1;i<=m;i++)
		if(U.merge(e[i].x,e[i].y))printf("%d %d\n",e[i].Id,e[i].v);
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	U.init();
	for(i=1;i<=m;i++)scanf("%d",&e[i].v),e[i].Id=i;
	for(i=1;i<=m;i++)scanf("%d",&e[i].c);
	for(i=1;i<=m;i++)scanf("%d%d",&e[i].x,&e[i].y);
	scanf("%d",&S),Dc=1,std::sort(e+1,e+m+1);
	for(i=1;i<=m;i++)
		if((vs[i]=U.merge(e[i].x,e[i].y)))
			v[e[i].x].push_back(e[i]),
			swap(e[i].x,e[i].y),nw+=e[i].v,
			v[e[i].x].push_back(e[i]);
	cn=nw,dfs(),solve(),answ();
}
/*
Just go for it.
*/