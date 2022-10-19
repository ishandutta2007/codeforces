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
using namespace std;

const int N = 100010;
int ve, ho;
struct Hor
{
	int x1, x2, y;
}hor[N];
int ver[N];

vector<int> maxs;

int bin(int x)
{
	int l = 0, r = ve - 1;
	while (l < r)
	{
		int m = (l + r + 1) >> 1;
		if (ver[m] < x)
			l = m;
		else
			r = m - 1;
	}
	return l + 1;
}

int main()
{
	FAST;
	cin >> ve >> ho;
	Loop(i, 0, ve)
	{
		cin >> ver[i];
		ver[i]--;
	}
	Loop(i, 0, ho)
	{
		cin >> hor[i].x1 >> hor[i].x2 >> hor[i].y;
		hor[i].x1--; hor[i].x2--; hor[i].y--;
	}
	sort(ver, ver + ve);
	sort(hor, hor + ho, [](Hor a, Hor b)
		{
			return a.y < b.y || (a.y == b.y && a.x1 < b.x1);
		});
	ver[ve] = 999999999;
	bool flag = 1;
	int maax = 0;
	int las = 0;
	for (int i = 0; i < ho; i++)
	{
		if (hor[i].y != hor[las].y)
		{
			if (flag)
			{
				if (maax > ver[0])
					maxs.push_back(maax);
			}
			las = i;
			maax = 0;
			flag = 1;
		}
		if (flag && hor[i].x1 > maax)
		{
			if (maax > ver[0])
				maxs.push_back(maax);
			flag = 0;
		}
		maax = hor[i].x2 + 1;
	}
	if (flag && maax > ver[0])
		maxs.push_back(maax);
	int ans = maxs.size();
	int miin = ans;
	sort(all(maxs));
	las = 0;
	for (auto x : maxs)
	{
		if (x == 1000000000)
			break;
		ans--;
		int h = bin(x);
		ans += h - las;
		las = h;
		miin = min(ans, miin);
	}
	cout << miin;
}