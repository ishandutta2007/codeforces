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
const lli mod = 1e9 + 7;
int n, m;
int p[N];
int pat, l, r;
int gp(int x)
{
	if (p[x] == x) return x;
	return p[x] = gp(p[x]);
}
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[min(gp(a), gp(b))] = max(gp(a), gp(b));
	}
	while (l <= n)
	{
		r = gp(l);
		for (int i = l; i <= r; i++)
		{
			if (gp(i) != gp(l))
			{
				//cout << l << " " << i << endl;
				pat++;
				p[min(gp(i), gp(l))] = max(gp(i), gp(l));
				r = gp(l);
			}
		}
		l = r + 1;
	}
	cout << pat;
	return 0;
}