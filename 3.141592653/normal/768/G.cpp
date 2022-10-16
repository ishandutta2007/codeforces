#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int n,rt;
#include<vector>
std::vector<int>v[1111111];
int fa[1111111],siz[1111111],ds[1111111];
void dfs(int p=rt,int f=0)
{
	fa[p]=f,siz[p]=1;
	for(auto t:v[p])
		if(t^f)
			{dfs(t,p),siz[p]+=siz[t];if(siz[t]>siz[ds[p]])ds[p]=t;}
}
int dfn[1111111],dfr[1111111],rev[1111111],tt,top[1111111];
void split(int p=rt,int f=0,int T=rt)
{
	rev[dfn[p]=++tt]=p,top[p]=T;
	if(ds[p])split(ds[p],p,T);
	for(auto t:v[p])if((t^f)&&(t^ds[p]))split(t,p,t);
	dfr[p]=tt;
}
namespace segtree
{
	struct node
	{
		int s[2],siz;
	}tr[5555555];
	#define ls(x) tr[x].s[0]
	#define rs(x) tr[x].s[1]
	void check(int x)
	{
		if(tr[x].siz != tr[ls(x)].siz+tr[rs(x)].siz)
		{
			puts("Check failed");
			printf("at %d siz= %d ls= %d rs= %d\n",
			x,tr[x].siz,tr[ls(x)].siz,tr[rs(x)].siz);
		}
	}
	int nw=111111;
	int rank(int L,int R,int v,int pl=1,int pr=n)
	{
		if(pl>v)return 0;
		if(pr<=v)return tr[R].siz-tr[L].siz;
		int mid=(pl+pr)>>1;
		return rank(ls(L),ls(R),v,pl,mid)+rank(rs(L),rs(R),v,mid+1,pr);
	}
	int qkth(int L,int R,int k,int pl=1,int pr=n)
	{
		if(!k)return -1e9;
		if(k>tr[R].siz-tr[L].siz)return 1e9;
		if(pl==pr)return pl;
		int mid=(pl+pr)>>1;
		if(k>tr[ls(R)].siz-tr[ls(L)].siz)
			return qkth(rs(L),rs(R),k-(tr[ls(R)].siz-tr[ls(L)].siz),mid+1,pr);
		return qkth(ls(L),ls(R),k,pl,mid);
	}
	int bound(int L,int R,int v,int op)
	{return qkth(L-1,R,rank(L-1,R,v)+op);}
	void insert(int p,int f,int v,int pl=1,int pr=n)
	{
		tr[p].siz=tr[f].siz+1;
		if(pl==pr)return;
		int mid=(pl+pr)>>1,dir=v>mid;
		tr[p].s[!dir]=tr[f].s[!dir],tr[p].s[dir]=++nw;
		dir?pl=mid+1:pr=mid;
		insert(tr[p].s[dir],tr[f].s[dir],v,pl,pr);
	}void init()
	{for(register int i=1;i<=n;i++)insert(i,i-1,siz[rev[i]]);}
}
int min(int x,int y){return(x<y)?x:y;}
int max(int x,int y){return(x<y)?y:x;}
int(*rc[2])(int,int)={&max,&min};
int qbound(int p,int x,int op)
{
	int ret=op?1e9:0;
	if(dfr[p]^n)ret=segtree::bound(dfr[p]+1,n,x,op);
	for(p=top[p];p;p=top[fa[p]])
	{
		int Ls=dfn[fa[p]]+1,Rs=dfn[p]-1;
		if(Ls<=Rs)ret=rc[op](ret,segtree::bound(Ls,Rs,x,op));
	}return ret;
}
int fir[1111111],sec[1111111],las[1111111];
int Q(int p,int x){return(~x)?siz[x]:n-siz[p];}
void upd(int x,int y)
{
	if((!fir[x])||Q(x,fir[x])<Q(x,y))sec[x]=fir[x],fir[x]=y;
	else if((!sec[x])||Q(x,sec[x])<Q(x,y))sec[x]=y;
	if((!las[x])||(Q(x,las[x])>Q(x,y)))las[x]=y;
}
int ans[1111111];
#include<set>
std::multiset<int>S;
void sumize(int p=rt,int f=0)
{
	for(auto t:v[p])
		if(t^f)
			S.insert(siz[t]),sumize(t,p),S.erase(S.find(siz[t]));
	if(!sec[p])ans[p]=n-1;
	else if(fir[p]==-1)
	{
		int A=Q(p,las[p]),B=Q(p,fir[p]);
		int delta=(B-A)>>1,LP=qbound(p,delta,0),RP=qbound(p,delta,1);
		auto t=S.lower_bound(delta+siz[p]);
		if(t!=S.end())RP=min(RP,(*t)-siz[p]);
		if(t!=S.begin())LP=max(LP,(*--t)-siz[p]);
		ans[p]=max(Q(p,sec[p]),min(min(max(A+LP,B-LP),B),max(A+RP,B-RP)));
	}else
	{
		int tp=fir[p],A=Q(p,las[p]),B=Q(p,fir[p]),delta=(B-A)>>1,
		LP=segtree::bound(dfn[tp],dfr[tp],delta,0),
		RP=segtree::bound(dfn[tp],dfr[tp],delta,1);
		ans[p]=max(Q(p,sec[p]),min(min(max(A+LP,B-LP),B),max(A+RP,B-RP)));
	}
}
void calc()
{
	register int i;
	segtree::init();
	for(i=1;i<=n;i++)
		for(auto ii:v[i])
			upd(i,(fa[i]==ii)?-1:ii);
	sumize();
}
int main()
{
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	register int i;
	for(i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(!x)rt=y;
		else if(!y)rt=x;
		else v[x].push_back(y),v[y].push_back(x);
	}dfs(),split(),calc();
	for(i=1;i<=n;i++)printf("%d\n",ans[i]);
}
/*
Just go for it.
*/