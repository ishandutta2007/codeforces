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
#define YN(flag) cout<<(flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 2e5;

int n;
ll a[N];

int bin(int k)
{
	int l = 0;
	int r = k;
	while (r > l)
	{
		int m = (l + r) / 2;
		if (a[k] > -a[m])
			r = m;
		else
			l = m + 1;
	}
	return l;
}

int main()
{
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, n)
	{
		ll x; cin >> x;
		a[i] -= x;
	}
	sort(a, a + n);
	ll ans = 0;
	LoopR(i, 0, n)
	{
		if (a[i] < 0)
			break;
		int j = bin(i);
		ans += i - j;
	}
	cout << ans;
}