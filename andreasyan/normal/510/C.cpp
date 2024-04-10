#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;
const int N=102;

int n,m;
string a[N];
bool g[30][30];
bool ok[N][N];
int c[30];
vector<char> ans;
bool stg()
{
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(ok[i][j]==false)
				return false;
		}
	}
	return true;
}
void cc()
{
	for(int i=0;i<26;++i)
		c[i]=0;
}
bool dfs(int x,int y)
{
	c[x]=1;
	if(x==y)
		return true;
	for(int i=0;i<26;++i)
	{
		if(!c[i] && g[x][i])
		{
			if(dfs(i,y))
				return true;
		}
	}
	return false;
}
bool dfs1(int x)
{
	c[x]=1;
	for(int i=0;i<26;++i)
	{
		if(!c[i] && g[x][i])
		{
			if(dfs1(i))
				return true;
		}
		if(c[i]==1 && g[x][i])
			return true;
	}
	c[x]=2;
	return false;
}
void dfs2(int x)
{
	c[x]=true;
	for(int i=0;i<26;++i)
	{
		if(!c[i] && g[x][i])
			dfs2(i);
	}
	ans.push_back(x+'a');
}
int main()
{
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>a[i];
	int k=0;
	while(1)
	{
		if(stg())
			break;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				if(ok[i][j])continue;
				if(k==a[i].length())
				{
					ok[i][j]=true;
					continue;
				}
				if(k==a[j].length())
				{
					cout<<"Impossible"<<endl;
					return 0;
				}
				if(a[i][k]==a[j][k])
					continue;
				cc();
				if(dfs(a[i][k]-'a',a[j][k]-'a'))
				{
					ok[i][j]=true;
					continue;
				}
				g[a[i][k]-'a'][a[j][k]-'a']=true;
				ok[i][j]=true;
			}
		}
		++k;
	}
	for(int i=0;i<26;++i)
	{
		cc();
		if(dfs1(i))
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	cc();
	for(int j=0;j<26;++j)
	{
		bool z=true;
		for(int i=0;i<26;++i)
		{
			if(g[i][j])
			{
				z=false;
				break;
			}
		}
		if(z)
		{
			dfs2(j);
		}
	}
	for(int i=25;i>=0;--i)
		cout<<ans[i];
	cout<<endl;
//	system("pause");
	return 0;
}