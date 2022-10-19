#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
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
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
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
using namespace std;
const int N = 1e6 + 20;
int n;
int a[30];
string s;
int main()
{
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a[s[0] - 'a']++;
	}
	int mx = 0;
	for (int i = 0; i < 30; i++)
	{
		int sm = a[i] / 2;
		mx += ((sm - 1) * sm) / 2;
		sm = a[i] - sm;
		mx += ((sm - 1) * sm) / 2;
	}
	cout << mx;
	return 0;
}