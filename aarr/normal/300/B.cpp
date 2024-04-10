#include <iostream>

#include <vector>

using namespace std;

vector<int> clrs[50];
int color[50];
int main()
{
	int n, m, nc = 1;
	bool b = true;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		if(color[x] == 0 && color[y] == 0)
		{
			if(nc > n / 3)
			{
				b = false;
				continue;
			}
			color[x] = nc;
			color[y] = nc;
			clrs[nc].push_back(x);
			clrs[nc].push_back(y);
			nc ++;
			continue;
		}
		if(color[x] != 0 && color[y] != 0 && color[x] != color[y])
		{
			b = false;
			continue;
		}
		if(color[x] != 0 && color[y] == 0)
		{
			if(clrs[color[x]].size() < 3)
			{
				clrs[color[x]].push_back(y);
				color[y] = color[x];
				continue;
			}
			else
			{
				b = false;
				continue;
			}
		}
		if(color[x] == 0 && color[y] != 0)
		{
			if(clrs[color[y]].size() < 3)
			{
				clrs[color[y]].push_back(x);
				color[x] = color[y];
				continue;
			}
			else
			{
				b = false;
				continue;
			}
		}
	}
	int j = 1;
	if(b == false)
	{
		cout << -1;
		return 0;
	}
	for(int i = 1; 3 * i <= n; i ++)
	{
		while(clrs[i].size() < 3)
		{
			if(color[j] == 0)
			{
				color[j] = i;
				clrs[i].push_back(j);
			}
			j ++;
		}
	}
	for(int i = 1; i * 3 <= n; i ++)
	{
		cout << clrs[i][0] << " " << clrs[i][1] << " " << clrs[i][2] << endl;
	}
	return 0;
}