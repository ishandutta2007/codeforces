#include<bits/stdc++.h>
using namespace std;
int t,n;
pair<int,int> st[100005];
inline pair<int,int> merge(pair<int,int> a,pair<int,int> b)
{
	return {min(a.first,b.first),max(a.second,b.second)};
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int top=0;
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			st[++top]={x,x};
			while (top>=2&&st[top-1].second>st[top].first)
			{
				st[top-1]=merge(st[top-1],st[top]);
				--top;
			}
		}
		printf("%d\n",top);
	}
	return 0;
}