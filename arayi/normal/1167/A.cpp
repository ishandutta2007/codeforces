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
#define mp make_pair
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
const int N = 1e5 + 20;
string s;
int t, n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int x = 0; x < t; x++)
	{
		cin >> n >> s;
		int i = 0;
		for (i = 10; i < s.length(); i++)
		{
			if (s[n - i - 1] == '8')
			{
				cout << "YES\n";
				break;
			}
		}
		if(i >= n)
			cout << "NO\n";
	}
	return 0;
}