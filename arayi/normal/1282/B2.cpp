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
const ld mod = 1e6;
int t, n, p, k;
int a[N], dp[N];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		int pat = 0;
		cin >> n;
		cin >> p >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		dp[0] = a[0];
		for (int i = 1; i < k - 1; i++)
		{
			dp[i] = a[i] + dp[i - 1];
		}
		dp[k - 1] = a[k - 1];
		for (int i = k; i < n; i++)
		{
			dp[i] = a[i] + dp[i - k];
		}
		for (int i = 0; i < n; i++)
		{
			if (dp[i] <= p) pat = i + 1;
		}
		cout << pat << endl;
	}
	return 0;
}