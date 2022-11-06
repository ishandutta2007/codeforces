#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int n;
string s;
int hotel[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			for (int j = 0; j < 10; j++)
			{
				if (hotel[j] == 0)
				{
					hotel[j] = 1;
					break;
				}
			}
		}
		else if (s[i] == 'R')
		{
			for (int j = 9; j >= 0; j--)
			{
				if (hotel[j] == 0)
				{
					hotel[j] = 1;
					break;
				}
			}
		}
		else
		{
			hotel[s[i] - '0'] = 0;
		}
	}

	for (int i = 0; i < 10; i++) cout << hotel[i];
}