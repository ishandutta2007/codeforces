#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int u,v;
	apple(int u=0,int v=0):u(u),v(v){}
}ans[100005];
int mp[1005][1005],n,tt2=0,a[100005],tot=0;
set<int>s;
void solve(int c)
{
	s.clear();
	for(int i=2;i<=n;i++)if(mp[1][i])s.insert(i);
	for(set<int>::iterator it=s.begin();it!=s.end();)
	{
		set<int>::iterator it2=it;
		it2++;
		if(it2==s.end())break;
		if((*it2)-(*it)==1)
		{
			it=it2;
			continue;
		}
		int dx=*it,dy=*it2;
		for(int i=dx+1;i<dy;i++)
		{
			if(mp[dx][i]&&mp[dy][i])
			{
				if(c)ans[++tot]=apple(1,i);
				else ans[++tot]=apple(dx,dy);
				mp[dx][dy]=mp[dy][dx]=0;
				mp[1][i]=mp[i][1]=1;
				s.insert(i);
				it=s.lower_bound(dx);
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)mp[i+1][(i+1)%n+1]=mp[(i+1)%n+1][i+1]=1;
	for(int i=1;i<=n-3;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u][v]=mp[v][u]=1;
	}
	solve(0);
	tt2=tot;
	memset(mp,0,sizeof(mp));
	for(int i=0;i<n;i++)mp[i+1][(i+1)%n+1]=mp[(i+1)%n+1][i+1]=1;
	for(int i=1;i<=n-3;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u][v]=mp[v][u]=1;
	}
	solve(1);
	cout<<tot<<endl;
	for(int i=1;i<=tt2;i++)printf("%d %d\n",ans[i].u,ans[i].v);
	for(int i=tot;i>tt2;i--)printf("%d %d\n",ans[i].u,ans[i].v);
	return 0;
}