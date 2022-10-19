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

int aqan, bqan, n, bb;
int sm;
string pat;
void cn()
{
	cout << endl;
	cin >> sm;
	if (sm == 0) exit(0);
}
int main()
{
	fastio;
	for (int i = 0; i < 300; i++) cout << "a";
	cn();
	aqan = 300 - sm;
	for (int i = 0; i < 300; i++) cout << "b";
	cn();
	bqan = 300 - sm;
	n = aqan + bqan;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < i; j++) cout << "a";
		cout << "b";
		for (int j = i + 1; j < n; j++) cout << "a";
		cn();
		if (sm == bqan - 1) pat += "b", bb++;
		else pat += "a";
	}
	if (bb == bqan) pat += "a";
	else pat += "b";
	cout << pat;
	cn();
	return 0;
}