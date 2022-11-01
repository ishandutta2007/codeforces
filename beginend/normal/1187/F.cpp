#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=200005;
const int MOD=1000000007;

int n,l[N],r[N],p[N],q[N];

int add(int x,int y) {return x+y<MOD?x+y:x+y-MOD;}
int dec(int x,int y) {return x-y<0?x-y+MOD:x-y;}
int mul(int x,int y) {return (LL)x*y%MOD;}

int ksm(int x,int y)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%MOD;
		x=(LL)x*x%MOD;y>>=1;
	}
	return ans;
}

int get(int i)
{
	int ans=1;
	ans=dec(ans,p[i]);
	ans=dec(ans,p[i+1]);
	int L=std::max(l[i-1],std::max(l[i],l[i+1])),R=std::min(r[i-1],std::min(r[i],r[i+1]));
	if (L<R) ans=add(ans,(LL)(R-L)*ksm((LL)(r[i-1]-l[i-1])*(r[i]-l[i])%MOD*(r[i+1]-l[i+1])%MOD,MOD-2)%MOD);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&l[i]);
	for (int i=1;i<=n;i++) scanf("%d",&r[i]),r[i]++;
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		int L=std::max(l[i],l[i-1]),R=std::min(r[i],r[i-1]);
		if (L<R) p[i]=mul(R-L,ksm(mul(r[i]-l[i],r[i-1]-l[i-1]),MOD-2));
		q[i]=dec(1,p[i]);
		sum=add(sum,q[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		ans=add(ans,q[i]);
		int s=dec(sum,q[i]);
		if (i>2) ans=add(ans,get(i-1)),s=dec(s,q[i-1]);
		if (i<n) ans=add(ans,get(i)),s=dec(s,q[i+1]);
		ans=add(ans,mul(s,q[i]));
	}
	printf("%d\n",ans);
	return 0;
}