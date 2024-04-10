#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct T{
	bool operator()(long long a,long long b)const{
		return a>b;
	}
};

priority_queue<long long,vector<long long>,T> q;

int main()
{
	long long n,i,tmp,ans=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&tmp),q.push(tmp);
	if(!(n&1)) q.push(0);
	while(q.size()>=3)
	{
		tmp=q.top(),q.pop(),tmp+=q.top(),q.pop(),tmp+=q.top(),q.pop();
		ans+=tmp,q.push(tmp);
	}
	printf("%lld\n",ans);
}