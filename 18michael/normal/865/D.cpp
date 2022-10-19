#include<cstdio>
#include<queue>
#include<vector>
#define LL long long
using namespace std;
int n;LL ans=0;
priority_queue<int,vector<int>,greater<int> > pq;
int main()
{
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x),pq.push(x);
		if(pq.top()<x)ans+=x-pq.top(),pq.pop(),pq.push(x);
	}
	return 0&printf("%lld",ans);
}