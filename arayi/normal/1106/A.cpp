#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <ctime>
#include <set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define lli long long int
using namespace std;
int n;
char a[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j]=='X')
			{
				if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i + 1][j - 1] && a[i][j] == a[i + 1][j + 1] && a[i][j] == a[i - 1][j + 1])
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}