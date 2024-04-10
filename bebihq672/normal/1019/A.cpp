#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q[3030],Q;
int p[3030],c[3030];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int mi=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i],&c[i]);
		if(p[i]==1)
			mi++;
	}
	long long ans=1e15;
	for(int i=max(mi,1);i<=n;i++)
	{
		long long sum=0;
		int si=mi;
		for(int j=1;j<=m;j++)
		{
			while(!q[j].empty())
				q[j].pop();
		}
		for(int j=1;j<=n;j++)
			q[p[j]].push(-c[j]);
		for(int j=2;j<=m;j++)
		while(q[j].size()>=i)
		{
			si++;
			sum-=q[j].top();
			q[j].pop();
		}
		while(!Q.empty())
			Q.pop();
		for(int j=2;j<=m;j++)
		while(!q[j].empty())
		{
			Q.push(q[j].top());
			q[j].pop();
		}
		while(si<i)
		{
			si++;
			sum-=Q.top();
			Q.pop();
		}
		ans=min(ans,sum);
	}
	printf("%I64d\n",ans);
	return 0;
}