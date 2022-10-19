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

lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}


char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };



const int N = 1e6 + 30;
const lli mod = 9982443530000;
int t, n, k, d;
int a[N];
int col[N];
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> d;
		int nw = 0, ans = d;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i < d)
			{
				if (!col[a[i]]) nw++;
				col[a[i]]++;
			}
		}
		ans = nw;
		int l = 0, r = d - 1;
		while (r < n - 1)
		{
			col[a[l]]--;
			if (!col[a[l]]) nw--;
			l++;
			r++;
			if (!col[a[r]]) nw++;
			col[a[r]]++;
			ans = min(ans, nw);
		}
		for (int i = 0; i < n; i++) col[a[i]] = 0;
		cout << ans << endl;
	}
	return 0;
}