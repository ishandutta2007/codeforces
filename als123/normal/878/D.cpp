#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;
typedef long long LL;
const int N=400005;
bitset<4096> f[N];
int n,k,q;
int a[15][N];
vector<pair<int,int> > v;
int main()
{
	scanf("%d%d%d",&n,&k,&q);
	for (int u=1;u<=k;u++)
	for (int i=1;i<=n;i++)
	scanf("%d",&a[u][i]);
	for (int u=1;u<4096;u++)
	for (int i=1;i<=k;i++)
	if ((1<<i-1)&u) f[i][u]=1;
	int nn=k;
	while (q--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) f[++nn]=f[x]|f[y];
		else if (op==2) f[++nn]=f[x]&f[y];
		else
		{
			v.clear();
			for (int u=1;u<=k;u++)	v.push_back(make_pair(a[u][y],u));
			sort(v.begin(),v.end());
			int now=0;
			for (int u=k-1;u>=0;u--)
			{
				now|=(1<<v[u].second-1);
				if (f[x][now])
				{
					printf("%d\n",v[u].first);
					break;
				}
			}
		}
	}
	return 0;
}