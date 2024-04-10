#include<cstdio>
#include<algorithm>
using namespace std;
struct f{
	long long s,k;
}d[400004],r[400005];
bool cmp(f a,f b)
{
	return a.s<b.s;
}
int cnt,m,a,b,c,k,ans[400004];
long long fk[200004];
const int mod=1e9+7;
int exgcd(int a,int b,long long& x,long long& y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int gcd=exgcd(b,a%b,x,y);
	long long t=x;x=y;y=t-a/b*y;
	return gcd;
}
long long sol(long long s)
{
	s%=mod;
    long long x,y;
    int gcd=exgcd(s,mod,x,y);
    x%=mod;
    if(x<0)
    x+=mod;
    return x;
}
long long C(long long j,long long i)
{
	if (i<0||j<i) return 0;
	return fk[j]*sol(fk[i])%mod*sol(fk[j-i])%mod;
}
int main()
{
	fk[0]=1;
	for(int i=1;i<=200000;i++)
	fk[i]=fk[i-1]*i%mod;
	scanf("%d%d",&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		r[i*2-1].s=a; r[i*2-1].k=1;
		r[i*2].s=b+1;r[i*2].k=-1;
	}
	sort(r+1,r+m*2+1,cmp);
	for(int i=1;i<=m*2;)
	{
		cnt++;
		d[cnt].s=r[i].s;
		while(d[cnt].s==r[i].s)
		{
			d[cnt].k+=r[i].k;
			i++;
		}
	}
	long long tmp=0;
	long long ans=0;
	d[cnt+1].s=d[cnt].s+1;
	for(int i=1;i<=cnt;i++)
	{
	tmp+=d[i].k;
	ans=(ans+(d[i+1].s-d[i].s)*C(tmp,k))%mod;
	}
	printf("%lld",ans);
}