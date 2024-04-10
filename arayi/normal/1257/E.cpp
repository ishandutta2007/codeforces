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
const lli mod = 1e9 + 7;
int k1, k2, k3, n;
int a[3][N];
int b[3][N];
bool col[3][N];
int mn[N];
int dp[N], ind[N];
int main()
{
	fastio;
	cin >> k1 >> k2 >> k3;
	for (int i = 0; i < k1; i++) cin >> a[0][i], col[0][a[0][i]] = true, ind[a[0][i]] = 0;
	for (int i = 0; i < k2; i++) cin >> a[1][i], col[1][a[1][i]] = true, ind[a[1][i]] = 1;
	for (int i = 0; i < k3; i++) cin >> a[2][i], col[2][a[2][i]] = true, ind[a[2][i]] = 2;
	sort(a[0], a[0] + k1);
	sort(a[1], a[1] + k2);
	sort(a[2], a[2] + k3);
	n = k1 + k2 + k3;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			b[k][i] = b[k][i - 1];
			if (col[k][i]) b[k][i]++;
			//cout << b[k][i] << " ";
		}
		//cout << endl;
	}
	for (int i = n; i >= 0; i--)
	{
		mn[i] = b[2][i] + ((n - i) - k3 + b[2][i]);
	}
	int pat = mn[0];
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			dp[i] = min(1 + dp[i - 1], b[1][i]);
		}
		else
		{
			dp[i] = dp[i - 1];
		}
		pat = min(mn[i] + dp[i], pat);
	}
	cout << pat;
	return 0;
}