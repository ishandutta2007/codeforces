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


const int N = 2e6 + 30;
const lli mod = 998244353;

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

int n;
vector <int> a[N];
vector <int> fp;
lli pat;
bool col[N];
int qn;
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, mn = 1e7;
		cin >> l;
		a[i].resize(l);
		bool bl = false;
		for (int j = 0; j < l; j++)
		{
			cin >> a[i][j];
			mn = min(mn, a[i][j]);
			if (a[i][j] > mn)
			{
				bl = true;
			}
		}
		if (bl)
		{
			pat += 2LL*(n - qn) - 1, col[i] = true;
			qn++;
		}
		else
			fp.PB(mn);
	}
	sort(fp.begin(), fp.end());
	for (int i = 0; i < n; i++)
	{
		if (col[i]) continue;
		int mx = 0;
		for (auto p : a[i]) mx = max(mx, p);
		pat += lower_bound(fp.begin(), fp.end(), mx) - fp.begin();
	}
	cout << pat << endl;
	return 0;
}