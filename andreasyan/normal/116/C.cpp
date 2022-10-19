#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m,k,t,maxu,g[2002];
vector<int> a[2002];
bool b[2002],c[2002];
queue<int> q;
int bfs(int j)
{
	int h;
	int i;
	q.push(j);
	c[j]=true;
	while(!q.empty())
	{
		j=q.front();
		q.pop();
		for(i=0;i<a[j].size();i++)
		{
			h=a[j][i];
			if(c[h]==false)
			{
				c[h]=true;
				g[h]=g[j]+1;
				q.push(h);
			}
		}
	}
	return g[j]+1;
}
int main()
{
	int i,j,x;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x==-1)
		{
			b[i]=true;
			continue;
		}
		a[x].push_back(i);
	}
	x=0;
	for(i=1;i<=n;i++)
	{
		if(b[i]==true)
			x=bfs(i);
		if(x>maxu)
			maxu=x;
	}
	cout<<maxu<<endl;
	return 0;
}