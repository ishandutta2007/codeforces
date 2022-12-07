#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=500005;
int n;
int a[N];
int l[N],r[N],d[N],num[N];
bool in[N];
int h[N],cnt;
int o[N];
int f[N];
vector<int> vec[N];
int main()
{
	memset(in,false,sizeof(in));
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		in[a[u]]=true;num[a[u]]++;
	}
	for (int u=1;u<=n;u++) if (in[u]) h[++cnt]=u;
	for (int u=1;u<=n;u++) r[a[u]]=u;
	for (int u=n;u>=1;u--) l[a[u]]=u;
	for (int u=1;u<=n;u++)
	{
		vec[a[u]].push_back(u);
		/*d[u]=1;
		if (a[u]==a[u-1]) d[u]=d[u-1]+1;*/
	}
	for (int u=1;u<=cnt;u++) o[r[h[u]]]=h[u];
//	for (int u=1;u<=n;u++) printf("%d ",o[u]);
	int ans=n;
	for (int u=1;u<=n;u++)
	{
		f[u]=f[u-1];
		if (o[u]!=0)
		{
			int x=o[u];
			f[u]=max(f[u],f[l[x]-1]+num[x]);
			ans=min(ans,n-f[u]);
			int siz=vec[x].size();
			int lalal=1;
			for (int i=siz-1;i>=0;i--,lalal++)
			{
				int j=vec[x][i];
				ans=min(ans,n-f[j-1]-lalal);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}