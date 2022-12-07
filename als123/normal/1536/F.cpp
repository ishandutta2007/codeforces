#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
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
int JC[N],inv[N];
int n;
int C (int y,int x)	{return x<y?0:mul(JC[x],mul(inv[y],inv[x-y]));}
void Init (int x)
{
	JC[0]=1;for (int u=1;u<=x;u++) JC[u]=mul(JC[u-1],u);
	inv[x]=Pow(JC[x],MOD-2);
	for (int u=x-1;u>=0;u--) inv[u]=mul(inv[u+1],u+1);
}
int main()
{
	Init(1000000);
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int u=1;u<=n/2;u++)
	{
		int i=u*2;
		ans=add(ans,mul(JC[i],C(n-i,i)));
		ans=add(ans,mul(JC[i],C(n-i-1,i-1)));
	}
	ans=mul(ans,2);
	printf("%d\n",ans);
	return 0;
}