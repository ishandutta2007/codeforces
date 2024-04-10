#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	int n;
	string s;
	cin >> n >> s;

	int f[10];
	for (int i = 1; i <= 9; i++)
		cin >> f[i];

	int cache[10];
	for (int i = 0; i < 10; i++)
		cache[i] = -1;

	bool hasStarted = false;
	for (int i = 0; i < n; i++)
	{
		int current = s[i] - '0';
		int change = f[current];
		if (cache[current] == -1)
		{
			if (hasStarted)
			{
				if (change >= current)
				{
					cache[current] = 1;
					s[i] = change + '0';
				}
				else
				{
					cache[current] = 0;
					if (hasStarted)
						break;
				}
			}
			else
			{
				if (change > current)
				{
					hasStarted = true;
					cache[current] = 1;
					s[i] = change + '0';
				}
				else if (change < current)
				{
					cache[current] = 0;
				}
			}
		}
		else
		{
			if (cache[current] == 1)
			{
				s[i] = change + '0';
			}
			else
			{
				if (hasStarted)
					break;
			}
		}
	}

	cout << s;
}