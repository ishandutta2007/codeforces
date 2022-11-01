#include <bits/stdc++.h>
using namespace std;
#define N (101*1000)

int n,num[N];
bool mark[N];
vector <int> e[N];

int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int v,u;
		cin>>v>>u;
		e[v].push_back(u);
		e[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(e[i].size()==1)
		{
			queue <int> q;
			q.push(i);
			while(q.size())
			{
				int x=q.front();q.pop();
				mark[x]=1;
				for(int j=0;j<e[x].size();j++)
					if(e[e[x][j]].size()<=2 && !mark[e[x][j]])
						q.push(e[x][j]);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=0;!mark[i] && j<e[i].size();j++)
			if(mark[e[i][j]])
				num[i]++;
	for(int i=1;i<=n;i++)
	{
		int p=0;
		for(int j=0;j<e[i].size();j++)
			if(!mark[e[i][j]] && (e[e[i][j]].size()-num[e[i][j]]>1 || num[e[i][j]]>2))	
				p++;
		if(p>2)return cout<<"No",0;		
	}
	cout<<"Yes";
	return 0;
}