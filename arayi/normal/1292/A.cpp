#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <cassert>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 5e5 + 3;
const lli mod = 1e9 + 7;

lli bp(lli a, lli b = mod - 2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int n, q;
bool col[5][N];
int sm;
int main()
{
	fastio;
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		if (col[x][y])
		{
			col[x][y] = false;
			for (int j = -1; j <= 1; j++)
			{
				sm -= (col[x - 1][y + j] + col[x + 1][y + j]);
			}
		}
		else
		{
			col[x][y] = true;
			for (int j = -1; j <= 1; j++)
			{
				sm += (col[x - 1][y + j] + col[x + 1][y + j]);
			}
		}
		if (sm) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}