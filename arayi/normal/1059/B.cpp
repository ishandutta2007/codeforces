#include <iostream>
using namespace std;
int b[1001][1001];
char b1[1001][1001];
bool stug(int i, int j)
{
	if (b[i - 1][j - 1] && b[i - 1][j] && b[i - 1][j + 1] && b[i][j - 1] && b[i][j + 1] && b[i + 1][j - 1] && b[i + 1][j] && b[i + 1][j + 1])
	{
		return 1;
	}
	return 0;
}
void maqr(int i, int j)
{
	b[i - 1][j - 1]++;
	b[i - 1][j]++;
	b[i - 1][j + 1]++;
	b[i][j - 1]++;
	b[i][j + 1]++;
	b[i + 1][j - 1]++;
	b[i + 1][j]++;
	b[i + 1][j + 1]++;
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> b1[i];
		for (int j = 0; j < m; j++)
		{
			if (b1[i][j] == '#')
			{
				b[i][j] = 1;
			}
			else
			{
				b[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m-1; j++)
		{
			if (stug(i, j))
				maqr(i, j);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (b[i][j] == 1)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}