#include <iostream>
#include <string>
#include <queue>
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
const int N = 1e5 + 1;
int pat[1001][2];
bool a[4][4];
string s;
bool jnj(int j, int j1)
{
	bool sm = 0;
	if (a[0][j1] && a[1][j1] && a[2][j1] && a[3][j1])
	{
		sm = 1;
		for (int x = 0; x < 4; x++)
		{
			a[x][j1] = 0;
		}
	}
	if (a[j][0] && a[j][1] && a[j][2] && a[j][3])
	{
		sm = 1;
		for (int x = 0; x < 4; x++)
		{
			a[j][x] = 0;
		}
	}
	j++;
	if (a[j][0] && a[j][1] && a[j][2] && a[j][3])
	{
		sm = 1;
		for (int x = 0; x < 4; x++)
		{
			a[j][x] = 0;
		}
	}
	j--;
	j1++;
	if (a[0][j1] && a[1][j1] && a[2][j1] && a[3][j1])
	{
		sm = 1;
		for (int x = 0; x < 4; x++)
		{
			a[x][j1] = 0;
		}
	}
	return sm;
}
void tp()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
bool sm1 = 0;
int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		sm1 = 0;
		if (s[i] == '0')
		{
			int j, j1;
			for (j = 0; j < 3; j++)
			{
				for (j1 = 0; j1 < 4; j1++)
				{
					if (!a[j][j1] && !a[j + 1][j1])
					{
						a[j][j1] = 1;
						a[j + 1][j1] = 1;
						if (jnj(j, j1))
						{
							sm1 = 1;
							pat[i][0] = j;
							pat[i][1] = j1;
							j = 3;
							break;
						}
						else
						{
							a[j][j1] = 0;
							a[j + 1][j1] = 0;
						}
					}
				}
			}
			if (!sm1)
			{
				int j, j1;
				for (j = 0; j < 3; j++)
				{
					for (j1 = 0; j1 < 4; j1++)
					{
						if (!a[j][j1] && !a[j + 1][j1])
						{
							a[j][j1] = 1;
							a[j + 1][j1] = 1;
							pat[i][0] = j;
							pat[i][1] = j1;
							j = 3;
							break;
						}
					}
				}

			}
		}
		else
		{
			int j, j1;
			for (j = 0; j < 4; j++)
			{
				for (int j1 = 0; j1 < 3; j1++)
				{
					if (!a[j][j1] && !a[j][j1 + 1])
					{
						a[j][j1] = 1;
						a[j][j1 + 1] = 1;
						if (jnj(j, j1))
						{
							sm1 = 1;
							pat[i][0] = j;
							pat[i][1] = j1;
							j = 4;
							break;
						}
						else
						{
							a[j][j1] = 0;
							a[j][j1 + 1] = 0;
						}
					}
				}
			}
			if (!sm1)
			{
				j = 0, j1 = 0;
				for (j = 0; j < 4; j++)
				{
					for (int j1 = 0; j1 < 3; j1++)
					{
						if (!a[j][j1] && !a[j][j1 + 1])
						{
							a[j][j1] = 1;
							a[j][j1 + 1] = 1;
							pat[i][0] = j;
							pat[i][1] = j1;
							j = 4;
							break;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		cout << pat[i][0] + 1 << " " << pat[i][1] + 1 << endl;
	}

	return 0;
}