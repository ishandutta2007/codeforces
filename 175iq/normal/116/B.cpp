#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	std::vector<std::vector<char>> board;
	board.resize(n, std::vector<char>(m, '.'));

	int cp=0;
	int cw=0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(board[i][j]=='P')
			{
				if((i+1)<=(n-1) && board[i+1][j]=='W')
				{
					cp++;
					continue;
				}
				if((j+1)<=(m-1) && board[i][j+1]=='W')
				{
					cp++;
					continue;					
				}
				if((i-1)>=0 && board[i-1][j]=='W')
				{
					cp++;
					continue;
				}
				if((j-1)>=0 && board[i][j-1]=='W')
				{
					cp++;
					continue;
				}
			}
			else if(board[i][j]=='W')
			{
				if((i+1)<=(n-1) && board[i+1][j]=='P')
				{
					cw++;
					continue;
				}
				if((j+1)<=(m-1) && board[i][j+1]=='P')
				{
					cw++;
					continue;					
				}
				if((i-1)>=0 && board[i-1][j]=='P')
				{
					cw++;
					continue;
				}
				if((j-1)>=0 && board[i][j-1]=='P')
				{
					cw++;
					continue;
				}
			}
		}
	}

	int ans=min(cp,cw);
	cout<<ans;
	return 0;
}