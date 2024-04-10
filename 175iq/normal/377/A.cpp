#include <bits/stdc++.h>
using namespace std;

void dfs(vector<std::vector<char> >& adjmat,vector<std::vector<bool> >& visited, int n, int m, int& count,int i,int j,int value)
{
	if(i>(n-1) || i<0 || j>(m-1) || j<0)
	{
		return;
	}
	
	if(adjmat[i][j]=='#')
	{
		return;
	}
	if(visited[i][j])
	{
		return;
	}

	count++;
	visited[i][j]=1;

	if(count==value)
	{
		return;
	}
	if(count<value)
	{
	    dfs(adjmat,visited,n,m,count,i+1,j,value);
	}
	if(count<value)
	{
	    dfs(adjmat,visited,n,m,count,i,j+1,value);
	}
	if(count<value)
	{
	    dfs(adjmat,visited,n,m,count,i-1,j,value);
	}
	if(count<value)
	{
	    dfs(adjmat,visited,n,m,count,i,j-1,value);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;

	cin>>n>>m>>k;

	std::vector<std::vector<char> > adjmat(n,std::vector<char> (m,'.'));
	std::vector<std::vector<bool> > visited(n,std::vector<bool> (m,0));

	int s=0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>adjmat[i][j];	
			if(adjmat[i][j]=='.')
			{
				s++;
			}
		}
	}	
	int count=0;
	bool mark=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(adjmat[i][j]=='.')
			{
				dfs(adjmat,visited,n,m,count,i,j,s-k);
				mark=1;
				break;
			}
		}
		if(mark)
		{
			break;
		}
	}
	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(adjmat[i][j]=='#')
			{
				cout<<'#';
			}
			else
			{
				if(visited[i][j])
				{
					cout<<'.';
				}
				else
				{
					cout<<'X';
				}
			}
		}
		cout<<endl;
	}	
	return 0;
}