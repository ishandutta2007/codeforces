#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
long long H,K;
int N,M;
long long A[101010];
long long C[101010];
bool used[101010];
long long start[101010];
multiset<long long> costs;
int main()
{
	scanf("%lld%d%d%lld",&H,&N,&M,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%lld%lld",A+i,C+i);
		A[i]--;
		if(A[i]%K==0)
		{
			used[i]=true;
			costs.insert(C[i]);
		}
	}
	for(int i=0;i<K;i++) start[i]=((H+K)/K)*K+i;
	start[0]=0;
	for(int i=0;i<M;i++)
	{
		//for(int i=0;i<K;i++) printf("%lld ",start[i]);
		//puts("");
		int qt;
		scanf("%d",&qt);
		if(qt==1)
		{
			long long d;
			scanf("%lld",&d);
			long long cycno=K/__gcd(d,K);
			for(int i=0;i<__gcd(d,K);i++)
			{
				long long now=start[i];
				for(int j=0;j<2*cycno;j++)
				{
					now=min(now,start[now%K]);
					start[now%K]=now;
					now+=d;
				}
			}
			for(int i=0;i<N;i++)
			{
				if(used[i]) continue;
				if(start[A[i]%K]<=A[i])
				{
					costs.insert(C[i]);
					used[i]=true;
				}
			}
		}
		else if(qt==2)
		{
			int tr;
			long long dc;
			scanf("%d%lld",&tr,&dc);
			tr--;
			if(used[tr])
			{
				costs.erase(costs.find(C[tr]));
				C[tr]-=dc;
				costs.insert(C[tr]);
			}
			else C[tr]-=dc;
		}
		else
		{
			if(costs.size()==0)
			{
				puts("0");
				continue;
			}
			auto it=costs.end();
			it--;
			printf("%lld\n",*it);
			costs.erase(it);
		}
	}
	return 0;
}