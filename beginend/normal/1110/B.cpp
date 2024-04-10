#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=100005;

int n,m,k,b[N];
std::priority_queue<int> que;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=2;i<=n;i++) que.push(-b[i]+b[i-1]+1);
	int ans=n,now=n;
	while (now>k)
	{
		now--;
		ans-=que.top();
		que.pop();
	}
	printf("%d\n",ans);
	return 0;
}