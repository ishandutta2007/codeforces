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
const ld mod = 1e6;

int q;
lli a, b;
int main()
{
	fastio;
	cin >> q;
	while (q--)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		lli sm = (sqrt(8LL * (b - a) + 1LL) - 1LL) / 2LL;
		if (sm * (sm + 1LL) == 2LL * (b - a))
		{
			cout << sm << endl;
			continue;
		}
		sm++;
		a += (sm * (sm + 1LL)) / 2LL;
		if ((a - b) % 2LL == 0) cout << sm << endl;
		else
		{
			sm++;
			a += sm;
			if ((a - b) % 2LL == 0) cout << sm << endl;
			else cout << sm + 1LL << endl;
		}
	}
	return 0;
}