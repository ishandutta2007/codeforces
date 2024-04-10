#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cstring>
#include<random>
#define errlog(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
std::mt19937 Rand((unsigned ll)(new int*));
inline ull Ranll()
{return(Rand()*(1llu<<32llu))+(Rand());}
inline ll random(ll l,ll r)
{return Ranll()%(r-l+1)+l;}
int popcnt(int n){return n?popcnt(n>>1)+(n&1):0;}
void solve0(int n)
{
	if(popcnt(n+1)==1)
	{
		puts("YES");
		register int i;
		for(i=1;i<=n;i++)
			printf("%d ",i>>1);
		return;
	}puts("NO");
}
void solve1(int n)
{
	if(popcnt(n+1)!=1)
	{
		puts("YES");
		register int i;
		for(i=1;i<=n;i++)
			printf("%d ",i>>1);
		return;
	}puts("NO");
}
int tt=0;
int fa[1111111];
int stk[1111111];
void solve(int n,int k,int f=0)
{
	int cur=++tt;
	fa[cur]=f;
	if(n==11&&k==3)
	{
		fa[++tt]=cur;
		int rs=tt;
		fa[++tt]=cur;
		cur=tt;
		fa[++tt]=rs;
		fa[++tt]=rs;
		fa[++tt]=cur;
		fa[++tt]=cur;
		cur=tt;
		fa[++tt]=cur;
		fa[++tt]=cur;
		cur=tt;
		fa[++tt]=cur;
		fa[++tt]=cur;
		return;
	}
	if(k==2&&(popcnt(n-1)==1))
	{
		int ls=++tt,rs=++tt;
		fa[ls]=fa[rs]=cur;
		fa[++tt]=rs,fa[++tt]=rs;
		n-=4,cur=ls;
		register int i;
		stk[1]=cur;
		for(i=2;i<=n;i++)stk[i]=++tt;
		for(i=2;i<=n;i++)fa[stk[i]]=stk[i>>1];
		return;
	}if(k==1)
	{
		register int i;
		stk[1]=cur;
		for(i=2;i<=n;i++)stk[i]=++tt;
		for(i=2;i<=n;i++)fa[stk[i]]=stk[i>>1];
		return;
	}
	else fa[++tt]=cur,solve(n-2,k-1,cur);
}
void exec()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n%2==0)return puts("NO"),void();
	if(n==1)
	{
		if(k==0)
		{
			puts("YES");
			puts("0");
			return;
		}else puts("NO");
		return;
	}
	if(n==3)
	{
		if(k==0)
		{
			puts("YES");
			puts("0 1 1");
			return;
		}else puts("NO");
		return;
	}
	if(n==5)
	{
		if(k==1)
		{
			puts("YES");
			puts("0 1 1 3 3");
			return;
		}else puts("NO");
		return;
	}
	if(n==7)
	{
		if(k==0)
		{
			puts("YES");
			puts("0 1 1 2 2 3 3");
			return;
		}else if(k==2)
		{
			puts("YES");
			puts("0 1 1 2 2 4 4");
		}else puts("NO");
		return;
	}
	if(n==9)
	{
		if(k==1)
		{
			puts("YES");
			puts("0 1 1 2 2 3 3 4 4");
			return;
		}else if(k==3)
		{
			puts("YES");
			puts("0 1 1 2 2 4 4 6 6");
		}else puts("NO");
		return;
	}
	if(k>n/2-1){puts("NO");return;}
	if(k<2)
	{
		if(k==0)solve0(n);
		if(k==1)solve1(n);
		return;
	}puts("YES");
	solve(n,k);
	register int i;
	for(i=1;i<=n;i++)printf("%d ",fa[i]);puts("");
}
int main(int argc,char*argv[])
{
	srand((unsigned ll)(new int*));
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}