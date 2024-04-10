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
const int logN = 20;
int a[N];
int p[N];
pii maxfind[logN][N];
int n;

int lg(int x)
{
	int ans = 0;
	while (x > 0)
	{
		x >>= 1;
		ans++;
	}
	return ans;
}

void set_mf()
{
	Loop(i, 0, n)
		maxfind[0][i] = { a[i], i };
	Loop(j,1,logN)
		Loop(i, 0, n)
		{
			maxfind[j][i] = maxfind[j - 1][i];
			if (i + (1 << (j - 1)) < n)
				maxfind[j][i] = max(maxfind[j][i], maxfind[j - 1][i + (1 << (j - 1))]);
		}
}
pii get_mf(int l, int r)
{
	int lg = ::lg(r - l + 1) - 1;
	return max(maxfind[lg][l], maxfind[lg][r - (1 << lg) + 1]);
}


ll Solve(int l, int r)
{
	if (l > r)
		return 0;
	ll ans = 0;
	auto pp = get_mf(l, r);
	int max = pp.first;
	int maxp = pp.second;
	if (maxp - l < r - maxp)
	{
		Loop(i, l, maxp)
		{
			int pr = max - a[i];
			if (pr < 1 || n < pr)
				continue;
			pr = p[pr];
			if (maxp < pr && pr <= r)
				++ans;
		}
	}
	else
	{
		Loop(i, maxp + 1, r + 1)
		{
			int pr = max - a[i];
			if (pr < 1 || n < pr)
				continue;
			pr = p[pr];
			if (l <= pr && pr < maxp)
				++ans;
		}
	}
	ans += Solve(l, maxp - 1);
	ans += Solve(maxp + 1, r);
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	set_mf();
	cout << Solve(0, n - 1);
}