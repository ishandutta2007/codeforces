#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
const int mod=998244353;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int power(int a,int b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,a[400010],b[400010],cnt[(1<<25)+10];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int T=1;T<=25;T++)
	{
		fill(cnt,cnt+(1<<T)+1,0);
		for(int i=1;i<=n;i++)b[i]=a[i]%(1<<T),cnt[b[i]+1]++;
		for(int i=1;i<=(1<<T);i++)cnt[i]+=cnt[i-1];
		long long cur=0;
		const int M=(1<<T),M2=(1<<(T-1)),M3=(1<<(T+1));
		for(int i=1;i<=n;i++)
		{
			cur+=(cnt[max(M-b[i],0)]-cnt[max(M2-b[i],0)]);
			cur+=(cnt[min(M,M3-b[i])]-cnt[min(M,M+M2-b[i])]);
		}
		for(int i=1;i<=n;i++)if(((b[i]<<1)>>(T-1))&1)cur--;
		cur>>=1;
		if(cur&1)ans|=(1<<(T-1));
	}
	printf("%d\n",ans);
	return 0;
}