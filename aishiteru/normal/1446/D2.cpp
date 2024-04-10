#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,k,a[N],cnt[N],m[N],ans,s[N],x[N],pos[N*2],mx,u;
vector<int> g[N];
void cal()
{
	if(u==0)
		return;
	int k;
	x[u+1]=n+1;
	for(k=0;k<=u;++k)
	{
		if(pos[s[k]+N]==-1)
			pos[s[k]+N]=x[k];
		else
			ans=max(ans,x[k+1]-1-pos[s[k]+N]);
		//cout<<x[k+1]-1-pos[s[k]+N]<<endl;
	}
	//cout<<endl;
	for(k=0;k<=u;++k)
		pos[s[k]+N]=-1;
}
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
		if(i!=mx&&g[i].size())
		if(g[i].size()>300||n<=5000)
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
			cal();
		}
		else
		{
			int las=-N;
			u=0;
			for(k=0;k<g[i].size();++k)
			{
				int l=lower_bound(g[mx].begin(),g[mx].end(),g[i][k])-g[mx].begin();
				//cout<<l<<' '<<g[i][k]<<endl;
				if(l-las>g[i].size())
				{
					cal();
					u=0;
					for(j=max(0,l-(int)g[i].size()-1);j<l;++j)
					{
						++u;
						s[u]=s[u-1]-1;
						x[u]=g[mx][j];
					}
				}
				++u;
				s[u]=s[u-1]+1;
				x[u]=g[i][k];
				for(j=l;j<g[mx].size()&&j<=l+g[i].size()&&(k+1==g[i].size()||g[mx][j]<g[i][k+1]);++j)
				{
					++u;
					s[u]=s[u-1]-1;
					x[u]=g[mx][j];
				}
				las=j-1;
			}
			cal();
		}
	cout<<ans;
}