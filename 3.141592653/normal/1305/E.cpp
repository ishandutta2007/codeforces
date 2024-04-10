#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int a[111111];
inline int F(int n)
{return((n>>1)*((n-1)>>1));}
int n,k;
inline void arrange(int x,int y)
{
	register int i;
	for(i=1;i<=x;i++)a[i]=i;
	a[x]+=y*2;
}
int main()
{
	register int i;
	scanf("%d%d",&n,&k);
	if(k>F(n))return puts("-1"),0;
	for(i=n;i;i--)
	{
		int t=F(i-1);
		a[i]=1e8+i*10000;
		if(t>k)continue;
		arrange(i,F(i)-k);
		break;
	}for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/