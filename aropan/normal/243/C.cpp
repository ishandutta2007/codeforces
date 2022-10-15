#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int
	dx[4] = {-1, 0, 1, 0},
	dy[4] = { 0,-1, 0, 1};
const char ds[5] = "ULDR";

vector <long long> x, y, d;
vector <long long> X, Y;
int k;
int n, m;

vector < vector <int> > a;

void rec(int x, int y)
{
	if (x < 0 || y < 0 || n <= x || m <= y || a[x][y]) return;
	a[x][y] = -1;
	rec(x + 1, y);
	rec(x - 1, y);
	rec(x, y + 1);
	rec(x, y - 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d\n", &k);
	x.resize(k + 1);
	y.resize(k + 1);
	d.resize(k + 1);
	x[0] = y[0] = 0;
	for (int i = 1; i <= k; i++)
	{
		char c;
		int l;
		scanf("%c %d\n", &c, &l);
		int j = strchr(ds, c) - ds;
		x[i] = x[i - 1] + l * dx[j];
		y[i] = y[i - 1] + l * dy[j];
		d[i] = j;
	}
	X.push_back(-(long long)1e+10);
	X.push_back(+(long long)1e+10);
	Y.push_back(-(long long)1e+10);
	Y.push_back(+(long long)1e+10);
	
	for (int i = 0; i <= k; i++)
	{
		X.push_back(x[i]);
		X.push_back(x[i] + 1);
		X.push_back(x[i] - 1);
		Y.push_back(y[i]);
		Y.push_back(y[i] + 1);
		Y.push_back(y[i] - 1);
	}
	sort(X.begin(), X.end());
	X.resize(unique(X.begin(), X.end()) - X.begin());
	sort(Y.begin(), Y.end());
	Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
	
	for (int i = 0; i <= k; i++)
	{
		x[i] = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
		y[i] = lower_bound(Y.begin(), Y.end(), y[i]) - Y.begin();
	}
	n = X.size();
	m = Y.size();
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i].resize(m);
	a[x[0]][y[0]] = 1;
	for (int i = 1; i <= k; i++)
	{
		long long X = x[i - 1], Y = y[i - 1];
		while (X != x[i] || Y != y[i])
		{
			X += dx[d[i]];
			Y += dy[d[i]];
			a[X][Y] = 1;
		}
	}
	rec(0, 0);
	long long ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] >= 0)
				ans += (X[i] - X[i - 1]) * (Y[j] - Y[j - 1]);
	cout << ans << endl;
	return 0;
}