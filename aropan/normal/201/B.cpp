#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1023;

int a[MAXN][MAXN];
int row[MAXN];
int col[MAXN];
int n, m;

long long x[MAXN], y[MAXN];


template <typename T> T sqr(T x) { return x * x; }

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
		
	for (int i = 0; i <= n; i++)
		for (int j = 1; j <= n; j++)
			x[i] += row[j] * (long long)sqr(abs(4 * i - (4 * j - 2)));
		
	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= m; j++)
			y[i] += col[j] * (long long)sqr(abs(4 * i - (4 * j - 2)));
			
	int li, lj;
	li = lj = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (x[i] + y[j] < x[li] + y[lj])
			{
				li = i;
				lj = j;
			}
	cout << x[li] + y[lj] << endl;
	cout << li << " " << lj << endl;
	return 0;
}