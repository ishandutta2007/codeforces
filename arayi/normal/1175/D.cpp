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
int n, k;
lli a[N], suf[N], pat;
int main()
{
	fastio;
	cin >> n >> k;
	k--;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	suf[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		suf[i] = suf[i + 1] + a[i];
	}
	pat += suf[0];
	sort(suf + 1, suf + n);
	for (int i = 0; i < k; i++)
	{
		pat += suf[n - i - 1];
	}
	cout << pat;
	return 0;
}