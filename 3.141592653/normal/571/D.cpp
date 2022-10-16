#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
typedef long long ll;
int n,m;
struct BIT
{
	ll t[1111111];
	#define lowbit(x) (x&-x)
	void adv(register int x,int d)
	{for(;x<=n;x+=lowbit(x))t[x]+=d;}
	ll sum(register int x)
	{ll s=0;for(;x;x-=lowbit(x))s+=x[t];retrun s;}
}tt;
#include<vector>
std::vector<int>v[1111111],w[2][1111111];
int merge(int op,int x,int y)
{
	if(w[op][y].size()>w[op][x].size())x^=y^=x^=y;
	for(auto g:w[op][y])w[op][x].push_back(g);
	w[op][y].clear();
	return x;
}
struct colorset
{
	int tag[4444444];
	void pushd(int p)
	{if(tag[p])tag[p<<1]=tag[p<<1|1]=tag[p],tag[p]=0;}
	void insert(int L,int R,int c,int p=1,int l=1,int r=n)
	{
		if(L>r||l>R)return;
		if(L<=l&&r<=R)return(void)(tag[p]=c);
		int mid=(l+r)>>1;
		pushd(p),insert(L,R,c,p<<1,l,mid),insert(L,R,c,p<<1|1,mid+1,r);
	}int ask(int pos,int p=1,int l=1,int r=n)
	{
		if(l==r||tag[p])return tag[p];
		int mid=(l+r)>>1;
		return mid>=pos?ask(pos,p<<1,l,mid):ask(pos,p<<1|1,mid+1,r);
	}
}cs;
ll ans[1111111];
char op[1111111][3];
int x[1111111],y[1111111],z[1111111];
int f[2][1111111];
int rt(int*fa,int x)
{return fa[x]?fa[x]=rt(fa,fa[x]):x;}
int prm[2][1111111],rev[2][1111111];
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)w[0][i].push_back(i),w[1][i].push_back(i);
	for(i=1;i<=m;i++)
	{
		scanf("%s%d",op+i,x+i);
		if(*op[i]=='U')
		{
			scanf("%d",y+i);
			int xx=rt(f[0],x[i]),yy=rt(f[0],y[i]);
			if(xx==yy)continue;
			int t=merge(0,xx,yy);
			f[0][xx^yy^t]=t;
		}if(*op[i]=='M')
		{
			scanf("%d",y+i);
			int xx=rt(f[1],x[i]),yy=rt(f[1],y[i]);
			if(xx==yy)continue;
			int t=merge(1,xx,yy);
			f[1][xx^yy^t]=t;
		}if(*op[i]=='A')
		{
			int xx=rt(f[0],x[i]);
			y[i]=xx,z[i]=w[0][xx].size();
		}if(*op[i]=='Z')
		{
			int xx=rt(f[1],x[i]);
			y[i]=xx,z[i]=w[1][xx].size();
		}
	}int top[2]={0,0};
	for(i=1;i<=n;i++)
	{
		for(auto t:w[0][i])prm[0][++top[0]]=t;
		for(auto t:w[1][i])prm[1][++top[1]]=t;
	}for(i=1;i<=n;i++)rev[0][prm[0][i]]=rev[1][prm[1][i]]=i;
	for(i=1;i<=m;i++)
	{
		if(*op[i]=='Z')
		{
			int L=rev[1][y[i]],R=L+z[i]-1;
			cs.insert(L,R,i);
		}if(*op[i]=='Q')
		{
			int pos=rev[1][x[i]];
			y[i]=cs.ask(pos),v[y[i]].push_back(i);
		}
	}for(i=1;i<=m;i++)
	{
		if(*op[i]=='A')
		{
			int L=rev[0][y[i]],R=L+z[i]-1;
			tt.adv(L,z[i]),tt.adv(R+1,-z[i]);
		}if(*op[i]=='Q')ans[i]+=tt.sum(rev[0][x[i]]);
		for(auto g:v[i])ans[g]-=tt.sum(rev[0][x[g]]);
	}for(i=1;i<=m;i++)
		if(*op[i]=='Q')printf("%lld\n",ans[i]);
}
/*
Just go for it.
*/