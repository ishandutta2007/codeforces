#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,k,a[N],cnt[N],m[N],ans,s[N],x[N],pos[N*2],mx,u;
vector<int> g[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		g[a[i]].push_back(i);
	}
	for(i=1;i<=n;++i)
	{
		++cnt[a[i]];
		if(cnt[a[i]]>=cnt[mx])
			mx=a[i];
	}
	memset(pos,-1,sizeof(pos));
	for(i=1;i<=n;++i)
		//if(g[i].size()>300)
		if(g[i].size()&&i!=mx)
		{
			int l1=0,l2=0;
			u=0;
			while(l1<g[i].size()&&l2<g[mx].size())
				if(g[i][l1]<g[mx][l2])
				{
					++u;
					s[u]=s[u-1]+1;
					x[u]=g[i][l1++];
				}
				else
				{
					++u;
					s[u]=s[u-1]-1;
					x[u]=g[mx][l2++];
				}
			while(l1<g[i].size())
			{
				++u;
				s[u]=s[u-1]+1;
				x[u]=g[i][l1++];
			}
			while(l2<g[mx].size())
			{
				++u;
				s[u]=s[u-1]-1;
				x[u]=g[mx][l2++];
			}
			x[u+1]=n+1;
			for(k=0;k<=u;++k)
			{
				if(pos[s[k]+N]==-1)
					pos[s[k]+N]=x[k];
				ans=max(ans,x[k+1]-1-pos[s[k]+N]);
			}
			for(k=0;k<=u;++k)
				pos[s[k]+N]=-1;
		}
	cout<<ans;
}