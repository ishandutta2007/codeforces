#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100010;
ll a[N];
ll need[N];
int n;

int lg(ll x)
{
	int ans = 0;
	while (x > 0)
	{
		x >>= 1;
		ans++;
	}
	return ans;
}

int Solve()
{
	need[0] = 0;
	ll maax = 0;
	Loop(i, 1, n)
	{
		need[i] = max(need[i - 1] + a[i - 1] - a[i], 0LL);
		maax = max(maax, need[i]);
	}
	return lg(maax);
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