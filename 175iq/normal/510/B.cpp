#include <bits/stdc++.h>
using namespace std;

typedef long long int longl;
int iscycle=0;
std::vector<std::vector<char> > board(50,std::vector<char> (50));
std::vector<std::vector<bool> > visited(50,std::vector<bool> (50,0));

int dirx[]={1,0,-1,0};
int diry[]={0,1,0,-1};

bool isvalid(int i,int j)
{
	if(i<0 || i>=50)
	{
		return 0;
	}
	if(j<0 || j>=50)
	{
		return 0;
	}
	return 1;
}

void dfs_cycle(int i,int j,int parx,int pary)
{
	if(!isvalid(i,j))
	{
		return ;
	}
	visited[i][j]=1;
	int x,y;
	for (int k = 0; k<4 ; ++k)
	{
		x=i+dirx[k];
		y=j+diry[k];
		if(isvalid(x,y))
		{
			if(x== parx && y==pary)
			{
				continue;
			}
			else
			{
				if(board[x][y]==board[i][j])
				{
					if(visited[x][y])
					{
						iscycle=1;
					}
					else
					{
						dfs_cycle(x,y,i,j);
					}
				}
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,m;
	cin>>n>>m;
	string S;
	for (int i = 0; i < n; ++i)
	{
		cin>>S;
		for (int j = 0; j <m; ++j)
		{
			board[i][j]=S[j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <m ; ++j)
		{
			if(!visited[i][j])
			{
				dfs_cycle(i,j,-1,-1);
			}
		}
	}
	if(iscycle)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}