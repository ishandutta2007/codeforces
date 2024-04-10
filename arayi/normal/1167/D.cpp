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
const int N = 5e5 + 20;


int n;
string s;
string pat;
stack <int> a;
int sm;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	pat = s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			a.push(1);
		else
			a.pop();
		if (a.size() > sm) sm = a.size();
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			if (a.size() < (sm + 1) / 2)
				a.push(0), pat[i] = '0';
			else
				a.push(1), pat[i] = '1';
		}
		else
		{
			pat[i] = a.top() + '0';
			a.pop();
		}
	}
	cout << pat;
	return 0;
}