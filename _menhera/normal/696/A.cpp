#include<cstdio>
#include<map>
using namespace std;
int main()
{
	int Q;
	scanf("%d",&Q);
	
	map<long long, long long> price;
	for(int i=0; i<Q; i++)
	{
		int t; 
		scanf("%d",&t); //query type 
		if(t==1)
		{
			long long u, v, w;
			scanf("%lld%lld%lld",&u,&v,&w);
			while(u!=v)
			{
				long long& t = u>v?u:v;
				price[t] = price[t] + w;
				t/=2;
			}
			
		}
		else
		{
			long long u, v;
			scanf("%lld%lld",&u,&v);
			long long ans = 0;
			while(u!=v)
			{
				long long& t = u>v?u:v;
				ans += price[t];
				t/=2;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}