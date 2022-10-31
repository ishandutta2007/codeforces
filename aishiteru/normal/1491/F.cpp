#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,i,j,f[N],vis[N],siz[N],u,v;
int Q(vector<int> A,vector<int> B)
{
	printf("? %d %d\n",A.size(),B.size());
	for(auto it:A)
		printf("%d ",it);
	printf("\n");
	for(auto it:B)
		printf("%d ",it);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void dfs(vector<int> a,int p)
{
	if(a.size()==1)
	{
		//vector<int> e;
		//e.push_back(p);
		//if(Q(a,e))
			vis[a[0]]=1;
		return;
	}
	vector<int> g;
	int j;
	for(j=0;j<a.size()/2;++j)
		g.push_back(a[j]);
	vector<int> e;
	e.push_back(p);
	if(Q(g,e))
		dfs(g,p);
	else
	{
		g.clear();
		for(j=a.size()/2;j<a.size();++j)
			g.push_back(a[j]);
		dfs(g,p);
	}
}
int main()
{
/*#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		vector<int> A,B;
		for(j=1;j<=i;++j)
			A.push_back(j);
		B.push_back(i+1);
		if(Q(A,B))
		{
			vis[i+1]=1;
			break;
		}
	}
	vector<int> A;
	for(j=1;j<=i;++j)
			A.push_back(j);
	dfs(A,i+1);
	for(j=i+2;j<=n;++j)
	{
		vector<int> A,B;
		A.push_back(i+1);
		B.push_back(j);
		if(Q(A,B))
			vis[j]=1;
	}
	printf("! ");
	int s=0;
	for(j=1;j<=n;++j)
		if(!vis[j])
			++s;
	printf("%d ",s);
	for(j=1;j<=n;++j)
		if(!vis[j])
			printf("%d ",j);
	printf("\n");
	fflush(stdout);
	}
}