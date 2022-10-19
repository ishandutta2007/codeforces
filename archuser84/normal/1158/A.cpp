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
#define int long long
using namespace std;

const int N = 200010;
int a[N];
int b[N];
int n, m;
ll suma = 0, sumb = 0;

int32_t main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, n)
	{
		cin >> a[i];
		suma += a[i];
	}
	Loop(i, 0, m)
	{
		cin >> b[i];
		sumb += b[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	sort(b, b + m);
	if (a[0] > b[0])
		Kill(-1);
	ll ans = 0;
	Loop(i, 1, n)
		ans += (ll)a[i] * m;
	if (a[0] == b[0])
		ans += sumb;
	else
		ans += sumb + a[0] - a[1];
	cout << ans;
}