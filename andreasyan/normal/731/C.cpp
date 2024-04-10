#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n,m,k,a[200002],ans,sq,maxu;
vector<int> b[200002];
map<int,int> q;
map<int,int>::iterator j;
bool c[200002];
void dfs(int x)
{
	int i;
	for(i=0;i<b[x].size();i++)
	{
		if(c[b[x][i]]==false)
		{
			sq++;
			q[a[b[x][i]]]++;
			c[b[x][i]]=true;
			dfs(b[x][i]);
		}
	}
}
int main()
{
	int i,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for(i=1;i<=n;i++)
		if(c[i]==false)
		{
			maxu=0;
			q.clear();
			q[a[i]]++;
			sq=1;
			c[i]=true;
			dfs(i);
			for(j=q.begin();j!=q.end();++j)
				if(q[j->first]>maxu)
					maxu=q[j->first];
			ans+=sq-maxu;
		}
	cout<<ans<<endl;
	return 0;
}