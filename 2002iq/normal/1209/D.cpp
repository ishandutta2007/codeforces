#include <bits/stdc++.h>
using namespace std;
int par[100005];
int find(int x)
{
	if (par[x]!=x)
	par[x]=find(par[x]);
	return par[x];
}
int Union(int x,int y)
{
	x=find(x);
	y=find(y);
	if (x==y)
	return 0;
	par[x]=y;
	return 1;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=k;
	for (int i=1;i<=n;i++)
	par[i]=i;
	for (int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ans-=Union(a,b);
	}
	printf("%d",ans);
}