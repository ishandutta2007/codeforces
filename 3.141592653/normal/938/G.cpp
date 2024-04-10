#include<cstdio>
#include<cstring>
#define retrun return
#define cpnst const
struct LIB
{
	int dat[33];
	bool ins(int x)
	{
		for(register int i=30;~i;i--)
			if(x&(1<<i))
			{
				if(!dat[i])return dat[i]=x,1;
				x^=dat[i];
			}
		return 0;
	}
	int qmin(int x)
	{for(register int i=30;~i;i--)if((x^dat[i])<x)x^=dat[i];return x;}
}cur;
struct pii{int x,y,l;pii(){}pii(int a,int b,int v){x=a,y=b,l=v;}};
struct UFS
{
	int fa[1111111],len[1111111],siz[1111111];
	void init()
	{for(register int i=1;i<=1000000;i++)fa[i]=i;}
	int getfa(register int&x)
	{int ret=0;for(;fa[x]^x;x=fa[x])ret^=len[x];return ret;}
	pii stk[1111111];
	int top;
	int merge(int x,int y,int l)
	{
		int dx=getfa(x),dy=getfa(y);
		if(siz[x]>siz[y])x^=y^=x^=y;
		stk[++top]=pii(x,y,siz[y]);
		if(x^y)return fa[x]=y,len[x]=dx^dy^l,siz[y]+=(siz[x]==siz[y]),0;
		else return dx^dy^l;
	}
	void pop(int __count=1)
	{
		for(;__count--;top--)
		{
			int x=stk[top].x,y=stk[top].y,l=stk[top].l;
			if(stk[top].x==stk[top].y)continue;
			fa[x]=x,siz[y]=l;
		}
	}
}U;
#include<vector>
std::vector<pii>opt[1111111];
#include<map>
typedef long long ll;
std::map<ll,pii>mp;
#define rf(x,y) ((x*(1ll<<30))|y)
int n,m,q;
void push(int l,int r,pii g,int p=1,int pl=1,int pr=q)
{
	if(l>pr||pl>r)return;
	if(l<=pl&&pr<=r)return opt[p].push_back(g);
	int mid=(pl+pr)>>1;
	push(l,r,g,p<<1,pl,mid),push(l,r,g,p<<1|1,mid+1,pr);
}
int ask(int x,int y)
{return cur.qmin(U.getfa(x)^U.getfa(y));}
int op[1111111],x[1111111],y[1111111],d[1111111];
void solve(int l=1,int r=q,int p=1)
{
	for(auto g:opt[p])
	{int Tp=U.merge(g.x,g.y,g.l);cur.ins(Tp);}
	if(l==r)
	{if(op[l]==3)printf("%d\n",ask(x[l],y[l]));U.pop(opt[p].size());return;}
	int mid=(l+r)>>1;
	LIB tmp=cur;
	solve(l,mid,p<<1),cur=tmp,solve(mid+1,r,p<<1|1),cur=tmp,
	U.pop(opt[p].size());
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	U.init();
	for(i=1;i<=m;i++)
	{
		int tx,ty,l;
		scanf("%d%d%d",&tx,&ty,&l);
		mp[rf(tx,ty)]=pii(l,1,0);
	}scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",op+i,x+i,y+i);
		if(op[i]==1)scanf("%d",d+i),mp[rf(x[i],y[i])]=pii(d[i],i,0);
		else if(op[i]==2)
		{
			pii tp=mp[rf(x[i],y[i])];
			push(tp.y,i,pii(x[i],y[i],tp.x)),mp[rf(x[i],y[i])]=pii(0,0,1);
		}
	}for(auto tp:mp)
		if(!tp.second.l)push(tp.second.y,q,
		pii(tp.first>>30,tp.first&((1<<30)-1),tp.second.x));
	solve();
}
/*
Just go for it.
*/