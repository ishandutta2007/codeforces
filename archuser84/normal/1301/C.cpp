#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 1000000;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll Zs = n - m;
		ll T = m + 1;
		ll a = Zs / T;
		ll b = a + 1;
		ll As = T - Zs % T;
		ll Bs = Zs % T;
		ll ans = 0;
		ans += (a * (a - 1) / 2) * As;
		ans += (b * (b - 1) / 2) * Bs;
		cout << n * (n + 1) / 2 - ans - (n - m) << '\n';
	}
}