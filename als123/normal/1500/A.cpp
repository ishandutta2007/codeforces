#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
int a[N];
int id[N];
vector<int> vec[N];
bool cmp (int x,int y)	{return a[x]<a[y];}
pair<int,int> f[5000005];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) id[u]=u;
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	sort(id+1,id+1+n,cmp);
	int x=-1;
	for (int u=2;u<=n;u++)
	{
		if (a[id[u]]==a[id[u-1]])
		{
			if (x==-1) x=u;
			else
			{
				printf("YES\n");
				printf("%d %d %d %d\n",id[u],id[x-1],id[x],id[u-1]);
				return 0;
			}
			u++;
		}
	}
//	printf("%d\n",x);
	f[a[id[x]]*2].first=id[x];
	f[a[id[x]]*2].second=id[x-1];
	for (int u=1;u<=n;u++)
	for (int i=u+1;i<=n;i++)
	{
		if (a[id[u]]==a[id[x]]&&u!=x) continue;
		if (a[id[i]]==a[id[x]]&&i!=x) continue;
		int x=a[id[u]]+a[id[i]];
		//printf("%d %d %d\n",u,i,x);
		if (f[x].first!=0)
		{			
			printf("YES\n");
			printf("%d %d %d %d\n",id[u],id[i],f[x].first,f[x].second);
			return 0;
		}
		f[x].first=id[u];
		f[x].second=id[i];
	}
	printf("NO\n");
	return 0;
}