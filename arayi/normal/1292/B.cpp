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
#define x0 aa
#define y0 bb
#define ld long double
using namespace std;

lli gcd(lli a, lli b) { return (b == 0 ? a : gcd(b, a % b)); }

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 5e5 + 3;
const lli mod = 1e16 + 7;

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

lli x0, y0, ax, ay, bx, by, x, y, t;
vector <pair<lli, lli> > fp;
int pat, sm;
int main()
{
	fastio;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by >> x >> y >> t;
	fp.PB(MP(x0, y0));
	while (max(x0, y0) <= mod)
	{
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
		fp.PB(MP(x0, y0));
	}
	//cout << "SM" << endl;
	for (int i = fp.size() - 1; i >= 0; i--)
	{
		sm = 0;
		lli t1 = t;
		t1 -= abs(fp[i].fr - x) + abs(fp[i].sc - y);
		if (t1 < 0) continue;
		sm++;

		for (int j = i - 1; j >= 0; j--)
		{
			t1 -= abs(fp[j].fr - fp[j + 1].fr) + abs(fp[j].sc - fp[j + 1].sc);
			if (t1 < 0) break;
			sm++;
		}
		//cout << i << " " << sm << " ";
		if (abs(fp[i + 1].fr - fp[0].fr) + abs(fp[i + 1].sc - fp[0].sc) <= t1)
		{
			sm++;
			t1 -= abs(fp[i + 1].fr - fp[0].fr) + abs(fp[i + 1].sc - fp[0].sc);
			for (int j = i + 1; j < fp.size() - 1; j++)
			{
				t1 -= abs(fp[j].fr - fp[j + 1].fr) + abs(fp[j].sc - fp[j + 1].sc);
				if (t1 < 0) break;
				sm++;
			}
		}
		//cout << sm << endl;
		//cout << sm << " ";
		pat = max(pat, sm);
	}
	cout << pat << endl;
	return 0;
}