#include<cstdio>
using namespace std;
typedef long long LL;
const int MOD=998244353;
const int inv=499122177;
const int N=200005;
int add (int x,int y)	{x=x+y;return x>=MOD?x-MOD:x;}
int dec (int x,int y)	{x=x-y;return x<0?x+MOD:x;}
int mul (int x,int y)	{return (LL)x*y%MOD;}
int Pow (int x,int y)
{
	int t=1;
	while (y)
	{
		if (y&1) t=mul(t,x);
		y>>=1;x=mul(x,x);
	}
	return t;
}
int n,m,A;
int b[N];
int main()
{
	scanf("%d%d%d",&n,&m,&A);
	for (int u=1;u<=m;u++) scanf("%d",&b[u]);
	int cnt=n-2*b[m];
	int ans=Pow(A,cnt);
	for (int u=m;u>=1;u--)
	{
		int p=b[u]-b[u-1];
		cnt=add(Pow(A,p*2),Pow(A,p));
		cnt=mul(cnt,inv);
	//	printf("%d ",cnt);
		ans=mul(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}