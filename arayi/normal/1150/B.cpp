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
const int N = 50030;
int n, a[60][60];
bool can(int i, int j)
{
	if (a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1] + a[i + 1][j + 1] == 0)
	{
		a[i][j] = -1;
		a[i + 1][j] = -1;
		a[i + 2][j] = -1;
		a[i + 1][j - 1] = -1;
		a[i + 1][j + 1] = -1;
		return true;
	}
	cout << "NO";
	exit(0);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char A;
			cin >> A;
			if (A == '#')
				a[i][j] = -1;
		}
	}
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (a[i][j] == 0)
				can(i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}