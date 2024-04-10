#include<cstdio>
#define Mx 300000
#define LL long long
#define mod 998244353
int n;
bool ok;
LL pw[300002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[300002];
	inline void modify(int x)
	{
		int t=0;
		while(x<=n)sum[x]=(sum[x]+pw[t])%mod,t+=lowbit(x),x+=lowbit(x);
	}
	inline int query(int x)
	{
		int res=0,t=0;
		while(x)res=(res+pw[t]*sum[x])%mod,t+=lowbit(x),x-=lowbit(x);
		return res;
	}
}pre,suf;
inline int min(int x,int y)
{
	return x<y? x:y;
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<1)%mod;
	scanf("%d",&n),ok=0;
	for(int i=1;i<=n;++i)pre.sum[i]=suf.sum[i]=0;
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d",&x),pre.modify(x),suf.modify(n-x+1),y=min(x-1,n-x);
		if((pre.query(x+y)-pw[y]*pre.query(x)-suf.query(n-x+1+y)+pw[y]*suf.query(n-x+1))%mod)
		{
			for(ok=1;(++i)<=n;)scanf("%d",&x);
			break;
		}
	}
	return 0&puts(ok? "YES":"NO");
}