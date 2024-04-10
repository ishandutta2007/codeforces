#include<cstdio>
#include<algorithm>
#define LL long long
#define mod 1000000007
using namespace std;
int n,p,Test_num,ok;
LL res,cnt;
int a[1000002];
inline LL Pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline LL Add(LL x,LL y)
{
	x+=y;
	if(x>=mod)x-=mod;
	if(x<=-mod)x+=mod;
	return x;
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d",&n,&p),res=cnt=ok=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		if(p==1)
		{
			printf("%d\n",(n&1));
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=n;i;--i)
		{
			if(ok>0 || (!ok && cnt>=0))res=Add(res,-Pow(p,a[i])),--cnt;
			else res=Add(res,Pow(p,a[i])),++cnt;
			if(!ok && cnt)
			{
				for(int j=a[i-1];j<a[i];++j)
					if(abs(cnt*=p)>=n)
					{
						ok=(cnt>0? 1:-1);
						break;
					}
			}
		}
		if(!ok)ok=(cnt>0? 1:-1);
		printf("%lld\n",Add(ok*res,mod));
	}
	return 0;
}