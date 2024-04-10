#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define m_p make_pair
const int N=100005;

int n;
vector<int> a[N];
vector<int> b[N];

int c[N];

vector<int> v;
void dfs(int x)
{
	c[x]=1;
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(!c[h])
			dfs(h);
	}
	v.push_back(x);
}

int k;
void dfs1(int x)
{
	c[x]=k;
	for(int i=0;i<b[x].size();++i)
	{
		int h=b[x][i];
		if(!c[h])
			dfs1(h);
	}
}

vector<int> g[N];
vector<int> gg[N];

int cc[N];

void dfs3(int x,int p)
{
	cc[x]=p;
	for(int i=0;i<gg[x].size();++i)
	{
		int h=gg[x][i];
		if(!cc[h])
			dfs3(h,p);
	}
}

int main()
{
	cin>>n;
	for(int x=1;x<=n;++x)
	{
		int y;
		cin>>y;
		a[x].push_back(y);
		b[y].push_back(x);
	}
	for(int x=1;x<=n;++x)
		if(!c[x])
			dfs(x);
	reverse(v.begin(),v.end());
	for(int x=1;x<=n;++x)
		c[x]=0;
	for(int i=0;i<v.size();++i)
	{
		int x=v[i];
		if(!c[x])
		{
			++k;
			dfs1(x);
		}
	}
	if(k==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int x=1;x<=n;++x)
	{
		for(int i=0;i<a[x].size();++i)
		{
			int y=a[x][i];
			if(c[x]!=c[y])
			{
				g[c[x]].push_back(c[y]);
				gg[c[y]].push_back(c[x]);
			}
		}
	}
	v.clear();
	for(int x=1;x<=k;++x)
	{
		if(g[x].empty())
		{
			dfs3(x,x);
			v.push_back(x);
		}
	}
	vector<int> t[N];
	for(int x=1;x<=k;++x)
	{
		t[cc[x]].push_back(x);
	}
	vector<pair<int,int> > ans;
	for(int i=0;i<v.size();++i)
	{
		int x=v[i];
		int y=v[(i+1)%v.size()];
		for(int j=0;j<t[y].size();++j)
		{
			if(!gg[t[y][j]].size())
			{
				ans.push_back(m_p(x,t[y][j]));
			}
		}
	}
//////////////////////////////////////////////////
	int cx[N];
	for(int x=1;x<=n;++x)
		cx[c[x]]=x;
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i)
	{
		cout<<cx[ans[i].first]<<' '<<cx[ans[i].second]<<endl;
	}
	return 0;
}