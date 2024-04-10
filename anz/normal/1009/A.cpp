#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> c, a;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		c.push_back(t);
	}
	for (int j = 0; j < m; j++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}

	int index_c = 0;
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		while (true)
		{
			if (index_c >= c.size()) break;

			if (a[i] >= c[index_c])
			{
				result++;
				index_c++;
				break;
			}

			index_c++;
		}
	}

	cout << result;
}