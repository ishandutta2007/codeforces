#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;
ll a[N];
int n;

ll Solve()
{
	ll ans = 0;
	ll miin = 0;
	ll cur = 0;
	for (int i = 1; i < n; i += 2)
	{
		cur += a[i] - a[i - 1];
		miin = min(miin, cur);
		ans = max(ans, cur - miin);
	}
	ll ans2 = 0;
	miin = 0;
	cur = 0;
	for (int i = 2; i < n; i += 2)
	{
		cur += a[i - 1] - a[i];
		miin = min(miin, cur);
		ans2 = max(ans2, cur - miin);
	}
	ll sum = 0;
	for (int i = 0; i < n; i += 2)
		sum += a[i];
	return sum + max(ans, ans2);
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Loop(i, 0, n)
			cin >> a[i];
		cout << Solve() << '\n';
	}
}