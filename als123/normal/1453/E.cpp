#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
vector<int> vec[N];
int ans;
int d,f[N];
bool tf;
vector<int> son[N];
bool cmp (int x,int y)	{return f[x]<f[y];}
void dfs (int x,int fa)
{
	f[x]=0;
	int siz=vec[x].size();son[x].clear();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x);son[x].push_back(y);
	}
	siz=son[x].size();
	if (siz==0) return ;
	if (siz==1) {f[x]=f[son[x][0]]+1;ans=max(ans,f[x]);}
	else
	{
		sort(son[x].begin(),son[x].end(),cmp);
		if (x!=1) ans=max(ans,f[son[x][siz-1]]+2);
		else	
		{
			ans=max(ans,f[son[x][siz-1]]+1);
			ans=max(ans,f[son[x][siz-2]]+2);
		}
		f[x]=f[son[x][0]]+1;
	}
//	printf("%d %d\n",x,f[x]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);ans=0;
		for (int u=1;u<=n;u++) vec[u].clear();
		for (int u=1;u<n;u++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		/*int l=1,r=n;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) {ans=mid;r=mid-1;}
			else l=mid+1;
		}*/
		dfs(1,0);
		ans=max(ans,f[1]);
		printf("%d\n",ans);
	}
	return 0;
}