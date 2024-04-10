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
int n, m;
int a[N], b[N];
int col1[N], col2[N], m1, m2;
int main()
{
	fastio;
	cin >> n >> m;
	cin >> a[0] >> b[0];
	for (int i = 1; i < m; i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] != a[0] && b[i] != a[0])
		{
			m1++;
			col1[a[i]]++;
			col1[b[i]]++;
		}
		if (a[i] != b[0] && b[i] != b[0])
		{
			m2++;
			col2[a[i]]++;
			col2[b[i]]++;
		}
	}
	for (int i = 0; i <= n; i++)
	{
		if (col1[i] == m1 || col2[i] == m2)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}