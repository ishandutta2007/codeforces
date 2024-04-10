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
const int N = 1e5 + 30;
const lli mod = 1e9 + 7;
lli a, b, c;
int main()
{
	fastio;
	cin >> a >> b >> c;
	cout << (a + b) / c << " ";
	if (a / c + b / c == (a + b) / c) cout << 0;
	else cout << min((a / c + 1) * c - a, (b / c + 1) * c - b);

	return 0;
}