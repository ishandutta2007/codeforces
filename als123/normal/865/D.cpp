#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=300005;
int n;
int p[N];
priority_queue<int> q;
int main()
{
	scanf("%d",&n);
	LL ans=0;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		q.push(-x);
		if (x+q.top()>0)
		{
		///	printf("%d %d\n",x,q.top());
			ans=ans+x;
			ans=ans+q.top();
			q.pop();
			q.push(-x);
		}
	}
	printf("%lld\n",ans);
	return 0;
}