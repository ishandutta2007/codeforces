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

const int N = 400000;
int a[N];
int n;

int p2;
bool my_sort(int a, int b)
{
	return (a & p2) < (b & p2);
}

int binmin1(int x)
{
	x = x & p2;
	int l = 0, r = n - 1;
	while (r > l)
	{
		int m = (l + r) >> 1;
		int y = (a[m] & p2) + x;
		if (y > p2 >> 1)
			r = m;
		else
			l = m + 1;
	}
	return l;
}
int binmax1(int x)
{
	x = x & p2;
	int l = 0, r = n - 1;
	while (r > l)
	{
		int m = (l + r + 1) >> 1;
		int y = (a[m] & p2) + x;
		if (y <= p2)
			l = m;
		else
			r = m - 1;
	}
	if ((a[l] & p2) + x < 1 + (p2 >> 1))
		return -1;
	return l;
}
int binmin2(int x)
{
	x = x & p2;
	int l = 0, r = n - 1;
	while (r > l)
	{
		int m = (l + r) >> 1;
		int y = (a[m] & p2) + x;
		if (y >= (p2 >> 1) + p2 + 2)
			r = m;
		else
			l = m + 1;
	}
	return l;
}
int binmax2(int x)
{
	x = x & p2;
	int l = 0, r = n - 1;
	while (r > l)
	{
		int m = (l + r + 1) >> 1;
		int y = (a[m] & p2) + x;
		if (y <= (p2 << 1) + 1)
			l = m;
		else
			r = m - 1;
	}
	if ((a[l] & p2) + x < (p2 >> 1) + p2 + 2)
		return -1;
	return l;
}

int bitSolve(int k)
{
	p2 = (1 << (k + 1)) - 1;
	sort(a, a + n, my_sort);
	int ans = 0;
	Loop(i, 0, n)
	{
		int l, r;
		if (!Bit(a[i], k))
		{
			l = max(i + 1, binmin1(a[i]));
			r = binmax1(a[i]);
		}
		else
		{
			l = max(i + 1, binmin2(a[i]));
			r = binmax2(a[i]);
		}
		ans = ans ^ (max(r - l + 1, 0) & 1);
	}
	return ans;
}

int Solve()
{
	int ans = 0;
	Loop(i, 0, 25)
		ans |= bitSolve(i) << i;
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	cout << Solve();
}