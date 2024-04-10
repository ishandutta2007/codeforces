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


int t;
int n;
lli a[N];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		vector <lli> pat;
		lli sum = 0, sm = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sm = (sm ^ a[i]);
			sum += a[i];
		}
		pat.PB(sm);
		sum += sm;
		pat.PB(sum);
		cout << pat.size() << endl;
		for (auto p : pat) cout << p << " ";
		cout << endl;
	}
	return 0;
}