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

const int inf = 2000000000;
const int N = 5000;
int n, m;
int w, h;
struct env
{
	int w, h;
	int n;
}a[N];

int main()
{
	cin >> n; m = n;
	cin >> w >> h;
	Loop(i, 0, n)
	{
		cin >> a[i].w >> a[i].h;
		a[i].n = i;
		if (a[i].w <= w || a[i].h <= h)
		{
			a[i].w = inf;
			m--;
		}
	}
	if (m == 0)
	{
		cout << 0;
		return 0;
	}
	sort(a, a + n, [](env a, env b)
		{
			return a.w < b.w;
		});
	pair<int, int> dp[N]; dp[0] = { 1,-1 };
	int ans = 0;
	Loop(i, 1, m)
	{
		dp[i] = { 1,-1 };
		Loop(j, 0, i)
		{
			if (a[j].w == a[i].w)
				break;
			if (a[j].h < a[i].h && dp[j].first + 1 > dp[i].first)
				dp[i] = { dp[j].first + 1,j };
		}
		if (dp[ans].first < dp[i].first)
			ans = i;
	}
	int k = ans;
	cout << dp[ans].first << '\n';
	vector<int> h;
	while (k != -1)
	{
		h.push_back(a[k].n + 1);
		k = dp[k].second;
	}
	LoopR(i, 0, h.size())
		cout << h[i] << ' ';
}