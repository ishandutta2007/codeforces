#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
int gcd(int x,int y)
{
	if(x<0)x=-x;if(y<0)y=-y;
	int r=y;for(;r;r=x%y,x=y,y=r);
	return x;
}
struct pii
{int x,y;}P[333333];
bool operator<(cpnst pii x,cpnst pii y)
{return(x.y^y.y)?x.y<y.y:x.x<y.x;}
int Rl[1111111],Rr[1111111],col[1111111];
int tt=0;
int ex[1111111],ey[1111111];
int stk[1111111],top,cn;
#include<map>
std::map<pii,int>Mp;
int kth(int dx,int dy)
{
	int g=gcd(dx,dy),t;
	dx/=g,dy/=g;
	pii p=pii{dx,dy};
	if((t=Mp[p]))return t;
	return Mp[p]=++cn;
}
void readp()
{
	scanf("%d",&top);
	register int i;
	for(i=1;i<=top;i++)scanf("%d%d",ex+i,ey+i);
	for(i=1;i<top;i++)stk[i]=kth(ex[i+1]-ex[i],ey[i+1]-ey[i]);
	stk[top]=kth(ex[1]-ex[top],ey[1]-ey[top]);
}
struct query
{int l,r,k;}q[1111111];
bool operator<(cpnst query x,cpnst query y){return x.r<y.r;}
#define lowbit(x) (x&-x)
int t[1111111];
int ask(int x){int r=0;for(;x;x-=lowbit(x))r+=t[x];return r;}
void ins(int x,int d){for(;x<=4e5;x+=lowbit(x))t[x]+=d;}
#include<algorithm>
int ans[1111111],las[1111111];
void insert(int x,int tp)
{
	if(las[x])ins(las[x],-1);
	ins(tp,1),las[x]=tp;
}
int main()
{
	int n;
	scanf("%d",&n);
	register int i,ii;
	for(i=1,ii=0;i<=n;Rr[i]=ii,i++)
		for(readp(),Rl[i]=ii+1;top;)col[++ii]=stk[top--];
	int m;
	for(scanf("%d",&m),i=1;i<=m;i++)
		scanf("%d%d",&q[i].l,&q[i].r),
		q[i].k=i,q[i].l=Rl[q[i].l],q[i].r=Rr[q[i].r];
	std::sort(q+1,q+m+1);
	for(i=ii=1;i<=m;i++)
	{
		for(;ii<=q[i].r;ii++)insert(col[ii],ii);
		ans[q[i].k]=ask(ii)-ask(q[i].l-1);
	}for(i=1;i<=m;i++)printf("%d\n",ans[i]);
}
/*
Just go for it.
*/