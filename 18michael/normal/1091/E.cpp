#include<cstdio>
#include<algorithm>
#include<cmath>
#define Mx 18
#define LL long long
#define eps 1e-12
using namespace std;
int n,t;
bool ok=0;
LL sum;
int a[500002];
LL pre[500002];
LL b[500002][19],b1[500002][19],c[500002][19];
inline bool cmp(int x,int y)
{
	return x>y? 1:0;
}
inline void init()
{
	sum=t=0;
	for(int i=n;~i;--i)
	{
		if(!t && a[i]>i)t=i;
		while(t && t<=n && a[t]>i)++t;
		if(t)sum-=t-i-1;
		b[i][0]=sum,sum+=min(a[i],i);
	}
	sum=t=0;
	for(int i=n;~i;--i)
	{
		if(!t && a[i]>i+1)t=i;
		while(t && t<=n && a[t]>i+1)++t;
		if(t)sum-=t-i-1;
		c[i][0]=sum,sum+=min(a[i],i+1);
	}
	for(int i=1;i<=n;++i)b[i][0]+=1LL*i*(i-1)-pre[i],b1[i][0]=b[i][0]+i,c[i][0]+=1LL*i*(i+1)-pre[i];
	for(int i=1;i<=Mx;++i)
		for(int j=0;j+(1<<i)-1<=n;++j)
			b[j][i]=min(b[j][i-1],b[j+(1<<(i-1))][i-1]),b1[j][i]=min(b1[j][i-1],b1[j+(1<<(i-1))][i-1]),c[j][i]=min(c[j][i-1],c[j+(1<<(i-1))][i-1]);
}
inline LL getmn(int l,int r,LL A[500002][19])
{
	int len=log(r-l+1)/log(2)+eps;
	return min(A[l][len],A[r-(1<<len)+1][len]);
}
inline bool check(int x)
{
	if(x<t)
	{
		if(getmn(0,x,b1)<0)return 0;
		if(getmn(x+1,t,b)+x<0)return 0;
		if(getmn(t,n,c)-x<0)return 0;
	}
	else
	{
		if(getmn(0,t,b1)<0)return 0;
		if(getmn(t,n,c)-x<0)return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	init(),t=n;
	for(int i=(pre[n]&1);i<=n;i+=2)
	{
		while(t && a[t]<=i)--t;
		if(check(i))printf("%d ",i),ok=1;
	}
	if(!ok)puts("-1");
	return 0;
}