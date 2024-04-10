#include<bits/stdc++.h>
using namespace std;
const int N=300005;
struct rob
{
	int x,p,id;
	bool operator<(const rob &a)const
	{
		return x<a.x;
	}
}a[N];
int n,m,t;
char c[100];
int ans[N];
stack<rob> st[2];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i].x);
		for (int i=1;i<=n;++i)
		{
			scanf("%s",c);
			if (c[0]=='L')
				a[i].p=1;
			else
				a[i].p=0;
			a[i].id=i;
		}
		for (int i=1;i<=n;++i)
			ans[i]=-1;
		sort(a+1,a+1+n);
		for (int i=1;i<=n;++i)
		{
			int q=a[i].x%2;
			if (a[i].p)
			{
				if (st[q].empty())
				{
					st[q].push(a[i]);
					st[q].top().x=-st[q].top().x;
				}
				else
				{
					ans[a[i].id]=ans[st[q].top().id]=(a[i].x-st[q].top().x)/2;
					st[q].pop();
				}
			}
			else
				st[q].push(a[i]);
		}
		for (int q=0;q<=1;++q)
		{
			while (!st[q].empty())
			{
				rob x,y;
				x=st[q].top();
				st[q].pop();
				if (st[q].empty())
					break;
				y=st[q].top();
				st[q].pop();
				ans[x.id]=ans[y.id]=(2*m-x.x-y.x)/2;
			}
		}
		for (int i=1;i<=n;++i)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}