#include<cstdio>
using namespace std;
#define N 1500005
long long s[N],s2[N],n,r,k,s3;
int main()
{
	scanf("%lld%lld%lld",&n,&r,&k);
	for(int i=1;i<=n;i++)
	scanf("%lld",&s[i]);
	long long lb=0,rb=2e18,ans=0;
	while(lb<=rb)
	{
		long long mid=(lb+rb)>>1,tmp=0,fg=1;
		for(int i=1;i<=n;i++)
		s2[i]=s[i];
		for(int i=n+1;i<=n*2;i++)
		s2[i]=0;
		{
			int ls=1-r,rs=r+1;long long sum=0;
			for(int i=1;i<rs;i++)
			sum+=s2[i];
			for(int i=1;i<=n;i++)
			{
				sum+=s2[rs];
				if(ls>0)sum-=s2[ls-1];
				if(sum<mid)
				{
					long long tmp1=mid-sum;
					tmp+=tmp1;
					if(tmp>k)fg=0;
					s2[rs]+=tmp1;
					sum+=tmp1;
				}
				ls++,rs++;
			}
		}
		if(fg)
		ans=mid,lb=mid+1;
		else
		rb=mid-1;
	}
	printf("%lld\n",ans);
}//wkrakioi