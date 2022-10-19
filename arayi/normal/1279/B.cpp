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



const int N = 2e5 + 30;
const ld mod = 1e6;

int q;
lli n, a[N], s;
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> n >> s;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		lli pr = 0, mx = 0, ind = -1, pat = -1, mxp = 0;
		if (a[0] > s) cout << 1 << endl;
		else
		{
			for (int i = 0; i < n; i++)
			{
				pr += a[i];
				if (a[i] > mx)
				{
					ind = i, mx = a[i];
				}
				if (pr <= s)
				{
					mxp = i + 1;
					pat = -1;
				}
				else if (pr - mx <= s)
				{
					mxp = i;
					pat = ind;
				}
			}
			cout << pat + 1 << endl;
		}
	}
	return 0;
}