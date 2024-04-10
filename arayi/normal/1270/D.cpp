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


int n, k, az;
vector <int> q;
int a[N];
pair <int, int> sm[2];
void ask()
{
	cout << "? ";
	for (auto p : q) cout << p << " ";
	cout << endl;
	int i, v;
	cin >> i >> v;
	if (sm[0].sc == 0) sm[0] = MP(v, 1);
	else if (sm[0].fr == v) sm[0].sc++;
	else sm[1].fr = v, sm[1].sc++;
}
int main()
{
	fastio;
	cin >> n >> k;
	az = n;
	for (int i = 1; i <= k + 1; i++)
	{
		q.clear();
		for (int j = 1; j <= k + 1; j++)
		{
			if (j == i) continue;
			q.PB(j);
		}
		ask();
	}
	cout << "! ";
	if (sm[0].fr > sm[1].fr) cout << sm[0].sc;
	else cout << sm[1].sc;
	cout << endl;
	return 0;
}