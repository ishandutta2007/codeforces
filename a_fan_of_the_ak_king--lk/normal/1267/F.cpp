#include<bits/stdc++.h>
using namespace std;
int n,m,ka,kb,a[100005],b[100005],i,t[200005],la,lb;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
	scanf("%d %d %d %d",&n,&m,&ka,&kb);
	if(ka>m-1||kb>n-1)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(i=1;i<=ka;++i)
		scanf("%d",&a[i]);
	while(ka<m-1)
	{
		++ka;
		a[ka]=n;
	}
	for(i=1;i<=kb;++i)
		scanf("%d",&b[i]);
	while(kb<n-1)
	{
		++kb;
		b[kb]=n+m;
	}
	for(i=1;i<=ka;++i)
		++t[a[i]];
	for(i=1;i<=kb;++i)
		++t[b[i]];
	for(i=1;i<=n+m;++i)
		if(!t[i])
			q.push(i);
	la=lb=1;
	for(i=1;i<=n+m-2;++i)
	{
		int y=q.top();
		q.pop();
		if(y>n)
		{
			printf("%d %d\n",y,a[la]);
			--t[a[la]];
			if(t[a[la]]==0)
				q.push(a[la]);
			++la;
		}
		else
		{
			printf("%d %d\n",y,b[lb]);
			--t[b[lb]];
			if(t[b[lb]]==0)
				q.push(b[lb]);
			++lb;
		}
	}
	printf("%d ",q.top());
	q.pop();
	printf("%d",q.top());
}