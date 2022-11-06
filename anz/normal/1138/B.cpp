#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int n;
string c, a;

int num[4] = {0, 0, 0, 0};
//00, 01, 10, 11

int main()
{
	cin >> n >> c >> a;
	for (int i = 0; i < n; i++)
	{
		if (c[i] == '0')
		{
			if (a[i] == '0')
				num[0]++;
			else
				num[2]++;
		}
		else
		{
			if (a[i] == '0')
				num[1]++;
			else
				num[3]++;
		}
	}

	bool flag = false;
	int t[4] = { 0,0,0,0 };
	for (int i = 0; i <= num[0]; i++)
	{
		for (int j = 0; j <= num[3]; j++)
		{
			if (i - j + num[2] + num[3] == n / 2)
			{
				t[0] = i;
				t[3] = j;
				int tmp = num[2] + num[3] - 2 * t[3];
				if (tmp < 0) continue;
				flag = true;

				if (num[1] < tmp)
				{
					t[1] = num[1];
					t[2] = tmp - num[1];
					{
						if (t[2] > num[2])
						{
							flag = false;
							continue;
						}
					}
				}
				else
				{
					t[1] = tmp;
					t[2] = 0;
				}
				break;
			}
		}
		if (flag) break;
	}

	int counter = 0;
	if (!flag)
	{
		cout << "-1";
		return 0;
	}
	else
	{
		for (int i = 0; i < 4; i++) if (t[i] > num[i]) return 1;
		if (t[0] + t[1] + t[2] + t[3] != n / 2) return 2;
		for (int i = 0; i < n; i++)
		{
			if (!t[0] && !t[1] && !t[2] && !t[3]) break;
			if (c[i] == '0' && a[i] == '0' && t[0])
			{
				cout << i + 1 << ' ';
				t[0]--;
				counter++;
			}
			if (c[i] == '1' && a[i] == '0' && t[1])
			{
				cout << i + 1 << ' ';
				t[1]--;
				counter++;
			}
			if (c[i] == '0' && a[i] == '1' && t[2])
			{
				cout << i + 1 << ' ';
				t[2]--;
				counter++;
			}
			if (c[i] == '1' && a[i] == '1' && t[3])
			{
				cout << i + 1 << ' ';
				t[3]--;
				counter++;
			}
		}
	}
	if (counter != n / 2) return 3;
}