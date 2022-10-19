#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
const int N = 100030;
int n, m, a[60][60], b[60][60], c[60][60], d[60][60];
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			c[i][j] = min(a[i][j], b[i][j]);
			d[i][j] = max(a[i][j], b[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << c[i][j] << " ";
			if ((c[i + 1][j] <= c[i][j] && c[i + 1][j]) || (c[i][j + 1] <= c[i][j] && c[i][j + 1]))
			{
				cout << "Impossible";
				return 0;
			}
			if ((d[i + 1][j] <= d[i][j] && d[i + 1][j]) || (d[i][j + 1] <= d[i][j] && d[i][j + 1]))
			{
				cout << "Impossible";
				return 0;
			}
		}
		//cout << endl;
	}
	cout << "Possible";
	return 0;
}