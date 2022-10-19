#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
const int N=100005;

int n,m;
vector<int> a[N];
int c[N];
int qan[N];
long long ans[N];
long long sum[N];
map<int,int> b[N];
map<int,int>::iterator it;
void dfs(int x,int p)
{
	int i,j,k,h;
	++b[x][c[x]];
	qan[x]=1;
	sum[x]=c[x];
	for(i=0;i<a[x].size();++i)
	{
		h=a[x][i];
		if(h==p)
			continue;
		dfs(h,x);
		if(b[h].size()>b[x].size())
		{
			swap(b[h],b[x]);
			swap(qan[h],qan[x]);
			swap(sum[h],sum[x]);
		}
		for(it=b[h].begin();it!=b[h].end();++it)
		{
			b[x][it->first]+=b[h][it->first];
			if(b[x][it->first]>qan[x])
			{
				qan[x]=b[x][it->first];
				sum[x]=it->first;
			}
			else if(b[x][it->first]==qan[x])
			{
				sum[x]+=it->first;
			}
		}
	}
	ans[x]=sum[x];
}
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&c[i]);
	for(i=0;i<n-1;++i)
	{
		scanf("%d%d",&j,&k);
		a[j].push_back(k);
		a[k].push_back(j);
	}
	dfs(1,-1);
	for(i=1;i<=n;++i)
		printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}