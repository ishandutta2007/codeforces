#include<cstdio>
#include<queue>
using namespace std;
int n,v[100001],sum;
queue<pair<int,int> > l;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]),sum+=v[i];
		if(v[i]==0)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(sum<2*n-2)
	{
		printf("NO\n");
		return 0;
	}
	if(n==2)
	{
		printf("YES 1\n1\n1 2\n");
		return 0;
	}
	int ans=2;
	for(int i=1;i<=n;i++)
	if(v[i]>=2)ans++;
	if(ans>n)ans=n;
	printf("YES %d\n%d\n",ans-1,n-1);
	int las=0,f=0;
	for(int i=1;i<=n;i++)
	if(v[i]>=2)
	{
		if(!las)f=i;
		else printf("%d %d\n",las,i);
		las=i;
	}
	if(f!=las)
	l.push(make_pair(f,v[f]-1)),
	l.push(make_pair(las,v[las]-1));
	else
	l.push(make_pair(f,v[f]));
	for(int i=1;i<=n;i++)
	if(v[i]>2&&i!=f&&i!=las)
	l.push(make_pair(i,v[i]-2));
	for(int i=1;i<=n;i++)
	if(v[i]==1)
	{
		pair<int,int> s=l.front();l.pop();
		printf("%d %d\n",s.first,i);
		if(s.second>1)
		l.push(make_pair(s.first,s.second-1));
	}
}//fuck