#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 102;

int n, m, k;
int a[N];
int ans;
int main()
{
	int i, j,ii,x;
	cin >> n >> k >> m;
	for (i = 0; i < m; ++i)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < k; ++j)
		{
			cin >> x;
			for (ii = 0; ii < m; ++ii)
			{
				if (a[ii] == x)
				{
					for (; ii > 0; --ii)
					{
						++ans;
						swap(a[ii], a[ii - 1]);
					}
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}