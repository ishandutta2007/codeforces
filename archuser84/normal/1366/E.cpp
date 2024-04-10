#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 200010;
int a[N], b[N] = {};
int n, m;
bool tag[N];
int c[N] = {};
int bb[N];

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, m)
		cin >> b[i];
	int miin = Mod1;
	LoopR(i, 0, n)
	{
		if (a[i] < miin)
		{
			tag[i] = true;
			miin = a[i];
		}
	}
	int p = 0;
	int cnt = 0;
	Loop(i, 0, n)
	{
		cnt++;
		if (tag[i])
		{
			c[i] = cnt;
			cnt = 0;
		}
		if (tag[i] && a[i] == b[p])
		{
			bb[p++] = i;
		}
	}
	if (p < m)
		Kill(0);
	Loop(i, 0, bb[0])
	{
		if (a[i] < b[0])
			Kill(0);
	}
	ll ans = 1;
	Loop(i, 1, m)
	{
		ans *= c[bb[i]];
		ans %= Mod2;
	}
	cout << ans;
}