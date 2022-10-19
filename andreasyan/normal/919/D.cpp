#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=300003;

int n,m;
char g[N];
vector<int> a[N];
int c[N];
int yans[N];
bool stg(int x)
{
	c[x]=1;
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(c[h]==0)
			if(stg(h))
				return true;
		if(c[h]==1)
			return true;
	}
	c[x]=2;
	return false;
}
void dfs(int x,char u)
{
	c[x]=1;
	for(int i=0;i<a[x].size();++i)
	{
		int h=a[x][i];
		if(!c[h])
			dfs(h,u);
		if(yans[h]>yans[x])
			yans[x]=yans[h];
	}
	if(g[x-1]==u)
		yans[x]++;
}
int main()
{
	cin>>n>>m;
	cin>>g;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
	}
	for(int i=1;i<=n;++i)
		if(stg(i))
		{
			cout<<-1<<endl;
			return 0;
		}
	int ans=0;
	for(char i='a';i<='z';++i)
	{
		for(int j=1;j<=n;++j)
		{
			c[j]=0;
			yans[j]=0;
		}
		for(int j=1;j<=n;++j)
		{
			if(c[j]==0)
				dfs(j,i);
		}
		for(int j=1;j<=n;++j)
			ans=max(ans,yans[j]);
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}