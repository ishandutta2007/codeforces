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



const int N = 1e5 + 30;
const lli mod = 1e9 + 7;

lli n;
vector <lli> fp;
int main()
{
	fastio;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	for (lli i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			fp.PB(i);
			while (n % i == 0)n /= i;
		}
	}
	if (n > 1) fp.PB(n);
	if (fp.size() > 1) cout << 1;
	else
		cout << fp[0];
	return 0;
}