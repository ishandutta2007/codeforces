#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
const int N = 10003;

int n, k, a[N];
int m, z2, z4, z1;
bool ans = true;
int tz4(int x)
{
	if (z4>x / 4)
	{
		z4 -= x / 4;
		x %= 4;
		return x;
	}
	else
	{
		x -= (z4 * 4);
		z4 = 0;
		return x;
	}
}
int tz2(int x)
{
	if (z2>x / 2)
	{
		z2 -= x / 2;
		x %= 2;
		return x;
	}
	else
	{
		x -= (z2 * 2);
		z2 = 0;
		return x;
	}
}
int tz1(int x)
{
	if (z1>x / 1)
	{
		z1 -= x / 1;
		x %= 1;
		return x;
	}
	else
	{
		x -= (z1 * 1);
		z1 = 0;
		return x;
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i<k; ++i)
		cin >> a[i];
	z2 = n * 2;
	z4 = n;
	for (int i = 0; i<k; ++i)
	{
		a[i] = tz4(a[i]);
		a[i] = tz2(a[i]);
		if (a[i])
		{
			if (a[i] <= 2)
			{
				if (z4 && a[i] == 1)
				{
					--z4;
					++z2;
					a[i] = 0;
				}
				else if (z4 && a[i] == 2)
				{
					--z4;
					++z1;
					a[i] = 0;
				}
				else if (z2)
				{
					--z2;
					a[i] = 0;
				}
				else
				{
					goto kov;
				}
			}
			if (a[i] == 3)
			{
				if (z4)
				{
					--z4;
					a[i] = 0;
				}
				else if (z2 > 1)
				{
					z2 -= 2;
					a[i] = 0;
				}
				else
				{
					goto kov;
				}
			}
			if (a[i]>3)
			{
				goto kov;
			}
		}
		kov:
		a[i] = tz1(a[i]);
		if (a[i])
		{
			ans = false;
			break;
		}
	}
	if (ans)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
//	system("pause");
	return 0;
}