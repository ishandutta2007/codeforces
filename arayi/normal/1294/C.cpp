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
int mod = 600;

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
int t, n;

int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int n1 = n;
		vector <pair<int, int> > pat;
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0) 
			{
				int sm = 0;
				while (n % i == 0) n /= i, sm++;
				pat.PB(MP(i, sm));
			}
		}
		if (n > 1) pat.PB(MP(n, 1));
		n = n1;
		if (pat.size() == 1)
		{
			if (pat[0].sc < 6)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
				cout << pat[0].fr << " " << pat[0].fr * pat[0].fr << " " << n / (pat[0].fr * pat[0].fr * pat[0].fr) << endl;
			}
			continue;
		}
		if (pat.size() == 2)
		{
			if (pat[0].sc + pat[1].sc < 4)
			{
				cout << "NO\n";
			}
			else
			{
				cout << "YES\n";
				cout << pat[0].fr << " " << pat[1].fr << " " << n / (pat[0].fr * pat[1].fr) << endl;
			}
			continue;
		}
		cout << "YES\n";
		cout << pat[0].fr << " " << pat[1].fr << " " << n / (pat[0].fr * pat[1].fr) << endl;
	}
	return 0;
}