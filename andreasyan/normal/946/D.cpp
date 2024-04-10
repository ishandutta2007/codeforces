#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 505;

int n, m, k;
int a[N][N];
int ans[N];

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		vector <int> v;
		char b[N];
		cin >> b;
		for (int j = 0; j < m; ++j)
		{
			if (b[j] == '1')
				v.push_back(j);
		}
		for (int j = 0; j <= k; ++j)
		{
			a[i][j] = N;
			for (int l = 0; l <= j; ++l)
			{
				int r = v.size() - (j - l) - 1;
				if (l > r)
					a[i][j] = 0;
				else
					a[i][j] = min(a[i][j], v[r] - v[l] + 1);
			}
		}
	}
	for (int i = 1; i <= k; ++i)
		ans[i] = N*N;
	for (int i = 0; i < n; ++i)
	{
		int yans[N];
		for (int i = 0; i <= k; ++i)
			yans[i] = N*N;
		for (int j = 0; j <= k; ++j)
		{
			for (int l = 0; l <= k;++l)
			{
				if (j + l <= k)
					yans[j + l] = min(yans[j + l], ans[j] + a[i][l]);
			}
		}
		for (int j = 0; j <= k; ++j)
			ans[j] = yans[j];
	}
	cout << ans[k] << endl;
	return 0;
}