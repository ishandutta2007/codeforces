#include<bits/stdc++.h>
using namespace std;

long long f[40];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long d,m;
		scanf("%lld%lld",&d,&m);
		
		memset(f,0,sizeof(f));
		
		f[0]=1;
		long long sum=1;
		long long _2=1;
		for(int i=1;i<=32;i++)
		{
			if(_2>d)
				break; 
			long long now=min(_2*2,d+1)-_2;
			if(now<=0)
				break;
			f[i]=sum*now%m;
			sum+=f[i];
			sum%=m;
			_2*=2;
		}
		printf("%lld\n",(sum+m-1)%m);
	}
	return 0;
}