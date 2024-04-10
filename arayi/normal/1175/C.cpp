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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#define fr first
#define sc second
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define lli long long int
lli gcd(lli a, lli b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
lli cg(lli n) {
	return n ^ (n >> 1);
}
lli SUM(lli a)
{
	return (a * (a + 1) / 2);
}
bool CAN(int x, int y, int n, int m, int a)
{
	if (x >= a && y >= a && x < n && y < m)
	{
		return true;
	}
	return false;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
using namespace std;
const int N = 1e6 + 30;
const lli mod = 1e9 + 7;
int t, n, k;
int l, r, a[N], pat, ind;
int main()
{
	fastio;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		pat = 1e9;
		r = 0, l = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			r = i;
			if (r - l == k)
			{
				if ((a[r] - a[l] + 1) / 2 < pat)
				{
					pat = (a[r] - a[l] + 1) / 2;
					ind = (a[r] + a[l] + 1) / 2;
				}
				l++;
			}
		}
		cout << ind << endl;
	}
	return 0;
}