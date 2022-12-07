#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1005;
int T;
int n;
struct qq{int l,r;}a[N];
int ans[N];
queue<int> q;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=n;u++)	
			scanf("%d%d",&a[u].l,&a[u].r);
		memset(ans,0,sizeof(ans));
		int now=0;
		for (int u=1;u<=5000;u++)
		{
			while (now<n&&a[now+1].l<=u)	{now++;q.push(now);}
			while (!q.empty())
			{
				int x=q.front();q.pop();
				if (a[x].r<u) continue;
				ans[x]=u;
				break;
			}
			if (q.empty()&&now>=n) break;
		}
		for (int u=1;u<=n;u++) printf("%d ",ans[u]);
		printf("\n");
	}
	return 0;
}