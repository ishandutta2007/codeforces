#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;
const int N = 5005;
int n, s = 1;

int dis[N][N];
int color[N];

vector < pair<int, int> > dots;

bool dfs(int k, int v, int c)
{
	color[v] = c;
	for(int i = 0; i < n; i ++)
	{
		if(v != i && dis[v][i] > k)
		{
			if(color[i] == c)
			{
				return false;
			}
			if(color[i] == 0)
			{
				bool b = dfs(k, i, 3 - c);
				if(b == false)
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool isval(int k)
{
	s = 1;
	for(int i = 0; i < n; i ++)
	{
		color[i] = 0;
	}
	for(int i = 0; i < n; i ++)
	{
		if(color[i] == 0)
		{
			s *= 2;
			s %= mod;
			bool b = dfs(k, i, 1);
			if(b == false)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		dots.push_back({x, y});
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
		{
			dis[i][j] = abs(dots[i].first - dots[j].first) + abs(dots[i].second - dots[j].second);
		}
	}
	int dw = -1, up = 2 * N;
	while(up - dw > 1)
	{
		int md = (up + dw) / 2;
		if(isval(md) == true)
		{
			up = md;
		}
		else
		{
			dw = md;
		}
	}
	bool b = isval(up);
	cout << up << endl;
	cout << s;
	return 0;
}