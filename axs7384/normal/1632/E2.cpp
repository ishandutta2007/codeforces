#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int dep[N],mxdep[N],f[N];
vector<int> e[N];
int t,n;
inline void dfs(int x,int y)
{
	int mx1=dep[x],mx2=dep[x];
	for (int z:e[x])
		if (z!=y)
		{
			dep[z]=dep[x]+1;
			dfs(z,x);
			if (mxdep[z]>mx1)
			{
				mx2=mx1;
				mx1=mxdep[z];
			}
			else
				mx2=max(mx2,mxdep[z]);
		}
	mxdep[x]=mx1;
	if (mx2>=2)
		f[mx2-1]=max(f[mx2-1],mx1+mx2-2*dep[x]);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			e[i].clear();
		for (int i=1,u,v;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i=0;i<=n;++i)
			f[i]=0;
		dfs(1,0);
		for (int i=n-1;i;--i)
			f[i]=max(f[i],f[i+1]);
		int ans=1;
		// cout<<mxdep[1]<<"?"<<endl;
		for (int i=1;i<=n;++i)
		{
			while ((f[ans]+1)/2+i>ans&&ans<mxdep[1])
				++ans;
			printf("%d ",ans);
		}
		puts("");
	}
	return 0;
}