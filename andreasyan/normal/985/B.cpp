#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 2002;

int n, m;
char a[N][N];
int s[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '1')
				s[j]++;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		bool z = false;
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] == '1' && s[j] == 1)
			{
				z = true;
				break;
			}
		}
		if (!z)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}