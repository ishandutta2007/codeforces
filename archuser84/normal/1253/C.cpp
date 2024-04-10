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
	int n, m;
	cin >> n >> m;
	int a[200000];
	ll b[200000] = { 0 };
	for (LoopN)
		cin >> a[i];
	sort(a, a + n);
	ll ans = 0;
	for (int k = 1; k <= n; ++k)
	{
		b[(k - 1) % m] += a[k - 1];
		ans += b[(k - 1) % m];
		cout << ans << ' ';
	}
}