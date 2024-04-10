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



const int N = 3e5 + 30;
const lli mod = 1e9 + 7;
int n, m;
lli dp[100][N];
pair <lli, lli> a[100];
int main()
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].fr >> a[i].sc;
	}
	sort(a, a + n);
	for (int i = 1; i <= m; i++)
	{
		dp[0][i] = max(0LL, max(a[0].fr - 1, i - a[0].fr) - a[0].sc);
		//	cout << i << " " << dp[0][i] << endl;
	}
	for (int i = 1; i < n; i++)
	{
		for (int x = 1; x <= m; x++)
		{	
			lli sm = max(a[i].sc, x - a[i].fr);
			lli av = max(0LL, sm - a[i].sc);
			dp[i][x] = min(dp[i - 1][x], dp[i - 1][max(0LL, a[i].fr - sm - 1)] + av);
			dp[i][x] = min(dp[i][x], max(0LL, max(a[i].fr - 1, x - a[i].fr) - a[i].sc));
		}
	}
	cout << dp[n - 1][m]; 
	return 0;
}