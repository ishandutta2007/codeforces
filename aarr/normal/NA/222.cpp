#include <iostream>

#include <vector>

using namespace std;

vector <int> v[205];
int mark[205];
void dfs(int i)
{
	if(mark[i] == 0)
	{
		mark[i] = 1;
		for(int j = 0; j < v[i].size(); j ++)
		{
			dfs(v[i][j]);
		}
	}
}
int main()
{
	int n, m, s = 0;
	bool d = true, e = false;
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < x; j ++)
		{
			int y;
			cin >> y;
			v[i].push_back(y + n);
			v[y + n] . push_back(i);
			e = true;
		}
	}
	while(d)
	{
		d = false;
		for(int i = 1; i <= n; i ++)
		{
			if(mark[i] == 0)
			{
				dfs(i);
				s ++;
				d = true;
			}
		}
	}
	if(e)
	{
		s --;
	}
	cout << s;
	return 0;
}