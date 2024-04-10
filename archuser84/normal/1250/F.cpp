#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[100000];
	int sum = 0;
	for (LoopN)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	ll x = 0, y;
	for (int i = 0; i < n / 2; ++i)
		x += a[i];
	y = sum - x;
	cout << x * x + y * y << '\n';
}