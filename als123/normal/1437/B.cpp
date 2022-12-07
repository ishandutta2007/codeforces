#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100006;
const int MOD=998244353;
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
int n;
char ss[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",ss+1);
		int a=0,b=0;
		for (int u=2;u<=n;u++) 
		{
			if (ss[u]==ss[u-1])
			{
				if (ss[u]=='0') a++;
				else b++;
			}
		}
		printf("%d\n",max(a,b));
	}
	return 0;
}