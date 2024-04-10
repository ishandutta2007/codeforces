#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,s;
long long ans;
struct str{
	int p,m;
}a[500005];
bool cmp(str a,str b)
{
	return a.m<b.m;
}
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d %d",&a[i].m,&a[i].p);
		sort(a+1,a+1+n,cmp);
		a[n+1].m=-1;
		s=0,ans=0;
		while(!q.empty())
			q.pop();
		for(i=n;i>=1;i--)
		{
			if(a[i].m!=a[i+1].m)
				for(j=i;a[i].m==a[j].m&&j;--j)
					q.push(a[j].p);
			if(i-1+s<a[i].m)
			{
				while(i-1+s<a[i].m&&!q.empty())
				{
					ans+=q.top();
					q.pop();
					s++;
				}
			}
		}
		printf("%lld\n",ans);
	}
}