#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

typedef long long LL;

const int N=300005;

int n,k,t[N],b[N],a[N];
std::priority_queue<int> que;

bool cmp(int x,int y)
{
	return b[x]>b[y];
}

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d%d",&t[i],&b[i]),a[i]=i;
	std::sort(a+1,a+n+1,cmp);
	LL ans=0,sum=0;
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		que.push(-t[x]);
		sum+=t[x];
		if (que.size()>k) sum+=que.top(),que.pop();
		ans=std::max(ans,(LL)sum*b[x]);
	}
	printf("%lld\n",ans);
	return 0;
}