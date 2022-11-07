#include <stdio.h>
#include <queue>

std::priority_queue<int> pq;
int arr[2000];

int main()
{
	int n,k,a,m,r=0,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		pq.push(a);
	}
	while(!pq.empty())
	{
		m=pq.top();
		for(i=0;!pq.empty()&&i<k;i++)
			pq.pop();
		r+=2*(m-1);
	}
	printf("%d",r);
	return 0;
}