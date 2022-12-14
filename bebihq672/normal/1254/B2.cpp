#include<bits/stdc++.h>
using namespace std;

int a[1010101];

vector<long long> v;

int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	long long sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i];
	long long ans=1e18;
	for(long long i=2;i*i<=sum;i++)
	{
		if(sum%i==0)
		{
			v.push_back(i);
			while(sum%i==0)
				sum/=i;
		}
	}
	if(sum>1)
		v.push_back(sum);
	
	if(v.empty())
	{
		puts("-1");
		return 0;
	}
	
	for(int k=0;k<(int)v.size();k++)
	{
		long long p=v[k];
		sum=0;
		long long _ans=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			sum%=p;
			if(sum<(p+2)/2)
				_ans+=sum;
		}
		if(p>2)
		{
			sum=0;
			for(int i=n;i>=1;i--)
			{
				sum+=a[i];
				sum%=p;
				if(sum<(p+2)/2)
					_ans+=sum;
			}
		}
		ans=min(ans,_ans);
	}
	printf("%lld\n",ans);
	
	return 0;
}