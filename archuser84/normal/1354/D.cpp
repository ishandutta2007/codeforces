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

const int N = 1000010;
int fen[N] = {};
int n;
int fget(int k)
{
	int ans = 0;
	int i = k;
	while (i > 0)
	{
		ans += fen[i];
		i -= i & (-i);
	}
	return ans;
}
void fadd(int k)
{
	int i = k;
	while (i <= n)
	{
		fen[i]++;
		i += i & (-i);
	}
}
void fsub(int k)
{
	int i = k;
	while (i <= n)
	{
		fen[i]--;
		i += i & (-i);
	}
}
int bin(int k)
{
	int l = 0, r = n - 1;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		int x = fget(m);
		if (x < k)
			l = m;
		else
			r = m - 1;
	}
	return l + 1;
}

int cnt[N] = {};
int main()
{
	FAST;
	int q;
	cin >> n >> q;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		fadd(x);
		cnt[x]++;
	}
	while (q--)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			fadd(x);
			cnt[x]++;
		}
		else
		{
			x = -x;
			int p = bin(x);
			cnt[p]--;
			fsub(p);
		}
	}
	Loop(i, 1, n + 1)
	{
		if (cnt[i] > 0)
			Kill(i);
	}
	cout << "0\n";
}