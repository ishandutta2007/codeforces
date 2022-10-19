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



const int N = 1e6 + 30;
const lli mod = 1e9 + 7;
int t, n, a[N], ind[N];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int pat = n + 1;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ind[a[i]] = 0;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (ind[a[i]] == 0)
			{
				ind[a[i]] = i;
				continue;
			}
			pat = min(pat, ind[a[i]] - i + 1);
			ind[a[i]] = i;
		}
		if (pat == n + 1)
		{
			cout << -1 << endl;
		}
		else
			cout << pat << endl;
	}
	return 0;
}