#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
struct pii{int x,y;}P[1111111];
bool operator<(cpnst pii x,cpnst pii y){return(x.y^y.y)?x.y>y.y:x.x<y.x;}
int n,m,b;
int ans[1111111];
namespace lft
{
	#define Ls(x) tr[x].s[0]
	#define Rs(x) tr[x].s[1]
	#define Sz(x) tr[x].sz
	#define Mx(x) tr[x].mx
	cpnst double alp=0.3,all=alp/(1-alp),eps=1e-6;
	struct nod
	{
		int s[2],sz,mx,dm,it,tg;
		nod(int l=0,int r=0){s[0]=l,s[1]=r,sz=mx=dm=it=tg=0;}
	}tr[35111111];
	int tt=1;
	void push(int p,int d)
	{tr[p].tg+=d;}
	void pushm(int p,int d)
	{tr[p].dm+=d,tr[p].mx-=d;}
	void pushd(int p)
	{
		if(tr[p].tg)push(Ls(p),tr[p].tg),push(Rs(p),tr[p].tg),tr[p].tg=0;
		if(tr[p].dm)pushm(Ls(p),tr[p].dm),pushm(Rs(p),tr[p].dm),tr[p].dm=0;
	}void pushu(int p)
	{tr[p].mx=tr[Rs(p)].mx,Sz(p)=Sz(Ls(p))+Sz(Rs(p));}
	struct allq{int q,Id,c;};
	void extract(int p,allq*ds,int&tp)
	{
		if(!p)return;
		if(!Ls(p)){ds[++tp]=allq{tr[p].mx,tr[p].it,tr[p].tg};return;}
		pushd(p),extract(Ls(p),ds,tp),extract(Rs(p),ds,tp);
	}
	int merge(int x,int y)
	{
		if(!(x&&y))return x+y;
		if(eps+Sz(x)>=Sz(y)*all&&eps+Sz(y)>=Sz(x)*all)
			return tr[++tt]=nod(x,y),pushu(tt),tt;
		if(Sz(x)<Sz(y))
		{
			pushd(y);
			if(alp*(Sz(x)+Sz(y))<=Sz(Rs(y))+eps)
				return merge(merge(x,Ls(y)),Rs(y));
			return pushd(Ls(y)),merge(merge(x,Ls(Ls(y))),merge(Rs(Ls(y)),Rs(y)));
		}pushd(x);
		if(alp*(Sz(x)+Sz(y))<=Sz(Ls(x))+eps)
			return merge(Ls(x),merge(Rs(x),y));
		return pushd(Rs(x)),merge(merge(Ls(x),Ls(Rs(x))),merge(Rs(Rs(x)),y));
	}
	pii split(int x,int k)
	{
		if(!x)retrun pii{0,0};
		if(!(Ls(x)))return(Mx(x)<=k)?pii{x,0}:pii{0,x};
		pii tp;
		pushd(x);
		if(Mx(Ls(x))>k)return tp=split(Ls(x),k),pii{tp.x,merge(tp.y,Rs(x))};
		return tp=split(Rs(x),k),pii{merge(Ls(x),tp.x),tp.y};
	}
	int rt=0;
	void ins(int q,int Id,int c=0)
	{
		int nw=++tt;
		tr[nw].mx=q,tr[nw].it=Id,tr[nw].sz=1,tr[nw].tg=c;
		pii A=split(rt,q);
		rt=merge(A.x,merge(nw,A.y));
	}
	allq stk[1111111];
	int top;
	void rebuild()
	{
		top=0,extract(rt,stk,top);
		register int i;
		for(i=0;i<=tt;i++)tr[i]=nod();
		tt=1,rt=0;
		for(i=1;i<=top;i++)ins(stk[i].q,stk[i].Id,stk[i].c);
	}
	void qry(int c)
	{
		pii A=split(rt,c-1),B=split(A.y,(c<<1)-1);
		top=0,extract(B.x,stk,top);
		register int i;
		push(B.y,1),pushm(B.y,c),rt=merge(A.x,B.y);
		for(i=1;i<=top;i++)ins(stk[i].q-c,stk[i].Id,stk[i].c+1);
		if(tt>=2e7)rebuild();
	}
	void solve()
	{
		top=0,extract(rt,stk,top);
		register int i;
		for(i=1;i<=top;i++)ans[stk[i].Id]=stk[i].c;
		for(i=1;i<=m;i++)printf("%d ",ans[i]);puts("");
	}
}
#include<algorithm>
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)scanf("%d%d",&P[i].x,&P[i].y);
	std::sort(P+1,P+n+1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)scanf("%d",&b),lft::ins(b,i);
	for(i=1;i<=n;i++)lft::qry(P[i].x);
	lft::solve();
}
/*
Just go for it.
*/