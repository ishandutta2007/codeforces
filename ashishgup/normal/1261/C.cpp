#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;

int n, m;
string a[N];
vector<vector<int> > v, mark, v2;

void precompute()
{
	v = v2 = mark = vector<vector<int> > (n + 2, vector<int> (m + 2, 0));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			v[i][j] = (a[i][j] == 'X');
			v[i][j] += v[i][j - 1];
 		}
	}
	for(int j = 1; j <= m; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			v[i][j] += v[i - 1][j];
		}
	}
}

int get(int x1, int y1, int x2, int y2)
{
	return v[x2][y2] - v[x2][y1 - 1] - v[x1 - 1][y2] + v[x1 - 1][y1 - 1];
}

int check(int t)
{
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= m + 1; j++)
			mark[i][j] = 0, v2[i][j] = 0;
	for(int i = t + 1; i + t <= n; i++)
	{
		for(int j = t + 1; j + t <= m; j++)
		{
			int cnt = get(i - t, j - t, i + t, j + t);
			if(cnt == (2 * t + 1) * (2 * t + 1))
			{
				mark[i][j] = 1;
				v2[i - t][j - t] += 1;
				v2[i + t + 1][j + t + 1] += 1;
				v2[i + t + 1][j - t] += -1;
				v2[i - t][j + t + 1] += -1;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			v2[i][j] += v2[i][j - 1];
	for(int j = 1; j <= m; j++)
		for(int i = 1; i <= n; i++)
			v2[i][j] += v2[i - 1][j];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int isBurnt = (v2[i][j] > 0);
			int shouldBeBurnt = (a[i][j] == 'X');
			if(isBurnt != shouldBeBurnt)
				return 0;
		}
	}
	return 1;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= m + 1; j++)
			a[i] += '$';
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	}
	precompute();
	int ans = binsearch(0, min(n, m));
	cout << ans << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(mark[i][j])
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
	return 0;
}