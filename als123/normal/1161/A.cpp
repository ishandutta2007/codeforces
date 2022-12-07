#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n,k; 
int a[N];
int c[N],d[N];
vector<int> vec[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=k;u++) 
	{
		scanf("%d",&a[u]);
		vec[a[u]].push_back(u);
	}
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		if (u>1)//u-1 
		{
			if (vec[u].empty()) ans++;
			else
			{
				int x=vec[u][0];
                if (vec[u-1].empty()||vec[u-1].back()<x) ans++; 
			}
		}
		if (vec[u].empty()) ans++;
		if (u<n)//u+1
		{
			if (vec[u].empty()) ans++;
			else
			{
				int x=vec[u][0];
                if (vec[u+1].empty()||vec[u+1].back()<x) ans++; 
			}
		}
		//printf("%d %d\n",u,ans);
	}
	printf("%d\n",ans);
	return 0;
}