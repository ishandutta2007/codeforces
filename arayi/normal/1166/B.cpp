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
int k;
string s;
char a[] = { 'a', 'e', 'i', 'o', 'u' };
int main()
{
	fastio;
	cin >> k;
	for (int i = 5; i*i <= k; i++)
	{
		if (k % i == 0)
		{
			if (k / i < 5)
			{
				cout << -1;
				return 0;
			}
			for (int i1 = 0; i1 < k / i; i1++)
			{
				for (int j = 0; j < i; j++)
				{
					s += a[(i1 + j) % 5];
				}
			}
			cout << s;
			return 0;
		}
	}
	cout << -1;
	return 0;
}