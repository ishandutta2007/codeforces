#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int n;
vector<int> vec[N];
int dep[N],tot[N];
int du[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		du[x]++;du[y]++;
	}
	for (int u=1;u<=n;u++)
	if (du[u]==2)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}