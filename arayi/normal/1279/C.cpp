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
int n, m;
lli a[N], b[N], ret[N];
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> n >> m;
		int mx = 0;
		lli pat = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			ret[a[i]] = i + 1;
		}
		for (lli i = 0; i < m; i++)
		{
			cin >> b[i];
			b[i] = ret[b[i]];
			if (b[i] < mx) pat++;
			else
			{
				mx = b[i];
				pat += 2LL * (b[i] - i - 1LL) + 1LL;
			}
		}
		cout << pat << endl;
	}
	return 0;
}