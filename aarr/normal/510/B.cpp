#include <iostream>

using namespace std;

const int N = 60;
string s[N];
int mark[N][N];
pair<int, int> par[N][N];
int nparts = 1, n, m;
bool b = false;
void dfs(int i, int j)
{
	mark[i][j] = nparts;
	if(i - 1 >= 0 && s[i][j] == s[i - 1][j])
	{
		if(mark[i - 1][j] != 0 && (par[i][j].first != i - 1 || par[i][j].second != j))
		{
			b = true;
		}
		if(mark[i - 1][j] == 0)
		{
			par[i - 1][j] = {i, j};
			dfs(i - 1, j);
		}
	}
	if(j - 1 >= 0 && s[i][j] == s[i][j - 1])
	{
		if(mark[i][j - 1] != 0 && (par[i][j].first != i || par[i][j].second != j - 1))
		{
			b = true;
		}
		if(mark[i][j - 1] == 0)
		{
			par[i][j - 1] = {i, j};
			dfs(i, j - 1);
		}
	}
	if(i + 1 < n && s[i][j] == s[i + 1][j])
	{
		if(mark[i + 1][j] != 0 && (par[i][j].first != i + 1 || par[i][j].second != j))
		{
			b = true;
		}
		if(mark[i + 1][j] == 0)
		{
			par[i + 1][j] = {i, j};
			dfs(i + 1, j);
		}
	}
	if(j + 1 < m && s[i][j] == s[i][j + 1])
	{
		if(mark[i][j + 1] != 0 && (par[i][j].first != i || par[i][j].second != j + 1))
		{
			b = true;
		}
		if(mark[i][j + 1] == 0)
		{
			par[i][j + 1] = {i, j};
			dfs(i, j + 1);
		}
	}
}
int main()
{
	cin >> n;
	cin >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> s[i];
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < m; j ++)
		{
			if(mark[i][j] == 0)
			{
				dfs(i, j);
				nparts ++;
			}
		}
	}
	if(b)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}