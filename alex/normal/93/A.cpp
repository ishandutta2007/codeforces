#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define seta(a, b) memset(a, b, sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define int64 long long

int a, b, n, m, x, y, d;

int main()
{
	cin >> n >> m >> a >> b;
	a--;
	x = a % m;
	y = b % m;
	d = b / m - a / m - 1;
	if (x == 0) d++;

	if (a / m == (b - 1) / m)
	{
		cout << 1 << endl;
		return 0;
	}

	if (x == 0 && b == n)
	{
		cout << 1 << endl;
		return 0;
	}
	if (x == 0 && y == 0) cout << 1 << endl;
	else if (d == 0 || x == y || x == 0 || y == 0) cout << 2 << endl;
	else if (b == n) cout << 2 << endl;
	else cout << 3 << endl;

	return 0;
}