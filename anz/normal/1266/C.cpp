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
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int row[501], col[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int r, c; cin >> r >> c;
	if (r == 1 && c == 1)
	{
		cout << "0";
		return 0;
	}

	int num = 1;
	if (r <= c)
	{
		for (int i = 0; i < r; i++)
			row[i] = num++;
		for (int i = 0; i < c; i++)
			col[i] = num++;
	}
	else
	{
		for (int i = 0; i < c; i++)
			col[i] = num++;
		for (int i = 0; i < r; i++)
			row[i] = num++;
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << row[i] * col[j] << ' ';
		}
		cout << '\n';
	}
}