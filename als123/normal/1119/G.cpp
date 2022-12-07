#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1000005;
int n,m;
int h[N],t[N];
vector<int> vec;
int ans[2*N],cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++) scanf("%d",&h[u]);
	vec.push_back(0);vec.push_back(n);
	int now=0;
	for (int u=1;u<m;u++)	{now=(now+h[u])%n;vec.push_back(now);}
	sort(vec.begin(),vec.end());
	for (int u=0;u<m;u++) t[u]=vec[u+1]-vec[u];
	/*for (int u=0;u<=m;u++) printf("%d ",vec[u]);
	printf("\n");
	for (int u=0;u<m;u++) printf("%d ",t[u]);
	printf("\n");*/
	now=0;
	for (int u=1;u<=m;u++)
	{
		while (h[u]>0)
		{
			h[u]=h[u]-t[now];
			ans[++cnt]=u;
			now++;now%=m;
		}
	}
	while (cnt%m!=0)	ans[++cnt]=1;
	printf("%d\n",cnt/m);	
	int sum=0;
	for (int u=0;u<m;u++) 
		printf("%d ",t[u]);
	printf("\n");
	for (int u=1;u<=cnt;u++)
	{
		printf("%d ",ans[u]);
		if (u%m==0) printf("\n");
	}
	return 0;
}