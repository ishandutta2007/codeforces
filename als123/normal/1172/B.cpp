#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
const int MOD=998244353;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int du[N]; 
int JC[N];
int main()
{
	int n;
	scanf("%d",&n);
	if (n==2)	{printf("2\n");return 0;}
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		du[x]++;du[y]++;
	}
	int rt;
	for (int u=1;u<=n;u++) if (du[u]!=1) rt=u; 
	int ans=n;
	for (int u=1;u<=n;u++) 
	{
		ans=mul(ans,JC[du[u]]);
	}
	printf("%d\n",ans);
	return 0;
}