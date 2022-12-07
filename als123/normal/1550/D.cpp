#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int MOD=1e9+7;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int T,t;
int n,l,r;
int C (int x,int m)
{
	if (x<m||m<0) return 0;
	int t=1;
	for (int u=1;u<=m;u++) t=mul(t,mul((x-u+1),Pow(u,MOD-2)));
	return t;
}
int ans;
int calc (int x,int y)
{
	int r=x-y;
	return C(r+y+1,y);
}
void get (int nn)
{
	int A=1-l,B=r-n;
	int AA=max(A,B),BB=min(A,B);
	ans=add(ans,mul(BB,C(n,n/2)));
	int tt=C(n-1,nn-1);
	/*printf("AA:%d BB:%d %d %d %d\n",AA,BB,n-1,nn-1,C(n,nn));
	printf("A:%d\n",ans);*/
/*	for (int u=BB+1,i=1;u<=AA;u++,i++)
	{
		ans=add(ans,tt);
		tt=mul(tt,nn-i);
		tt=mul(tt,Pow(n-i,MOD-2));
	}
	printf("B:%d\n",ans);*/
	if (BB!=AA) ans=add(ans,dec(calc(n-1,nn-1),calc(n-1-(AA-BB),nn-1-(AA-BB))));
	int t=AA+1;
	
	int CC=min(n,(n-(l+t)+1))+min(n,(r-t))-n;
	tt=C(CC,nn-1);
	//printf("%d %d\n",t,CC);
	for (int u=1;;u++,CC-=2)
	{
		int d=nn-u;
		if (CC<d) break;
	//	printf("%d %d\n",CC,d);
	//ans=add(ans,C(CC,d));
		ans=add(ans,tt);
		tt=mul(tt,Pow(CC,MOD-2));
		tt=mul(tt,Pow(CC-1,MOD-2));
		tt=mul(tt,d);
		tt=mul(tt,CC-d);
	}
//	printf("C:%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&l,&r);
		int nn=n/2;
		ans=0;get(nn);
		if (n&1) get(nn+1);
		printf("%d\n",ans);
	}
	return 0;
}