#include<bits/stdc++.h>
using std::min;
using std::max;
typedef long long ll;

int n,r,k,a[1<<20],b[1<<20];
int c[1<<20],d[1<<20];
std::vector<int>v[1<<20];
void dfs(int x)
{
	if(x>=1&&x<=n)
		a[++r]=x;
	for(int t:v[x])
	{
		//printf("%d %d %d\n",x,t,v[t].size());
		if(!v[t].size())dfs(t);
	}
	for(int t:v[x])
		if(v[t].size())dfs(t);
}
void exec()
{
	scanf("%d",&n);
	r=0;
	k=0; 
	for(int i=1;i<=n;i++)
		scanf("%d",b+i);
	for(int i=0;i<=n+1;i++)
		v[i].clear();
	int rt=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>i)k=i;
		v[b[i]].push_back(i);
		if(b[i]==0||b[i]==n+1)rt=b[i];
	}
	printf("%d\n",k);
	dfs(rt);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	puts("");
	
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}