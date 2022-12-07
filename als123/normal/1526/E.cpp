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
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}
int JC[N],inv[N];
void Init (int n)
{
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	inv[n]=Pow(JC[n],MOD-2);
	for (int u=n;u>=1;u--) inv[u-1]=mul(inv[u],u);
}
int C (int x,int y)	{return x<y?0:mul(JC[x],mul(inv[y],inv[x-y]));}
int a[N];
int id[N];
int n,k;
bool cmp (int x,int y)	{return a[x]<a[y];}
int main()
{
	Init(200000);
	scanf("%d%d",&n,&k);a[n+1]=0;
	for (int u=1;u<=n;u++)	{int x;scanf("%d",&x);x++;a[x]=u;id[u]=u;}
	sort(id+1,id+1+n,cmp);
	int cnt=0;
	for (int u=1;u<n;u++)
	{
		int x=id[u]+1,y=id[u+1]+1;
		if (a[x]<a[y]) cnt++;
		//printf("%d %d %d\n",x,y,cnt);
	}
	//printf("%d\n",cnt);
	int ans=0;
	for (int u=0;u<=cnt;u++)
	{
		int o=n-u;
		ans=add(ans,mul(C(cnt,u),C(k,o)));
	}
	printf("%d\n",ans);
	return 0;
}