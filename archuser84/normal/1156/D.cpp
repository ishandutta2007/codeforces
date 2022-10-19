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
vector<int> A[2][N];
int n;
int cnum[2][N];
int ccnt[2][N];
int vis[2][N] = {};

int dfsz(int u, int c)
{
	int sum = 1;
	cnum[0][u] = c;
	vis[0][u] = true;
	for (int v : A[0][u])
		if (!vis[0][v])
			sum += dfsz(v, c);
	return sum;
}

pair<int, ll> dfso(int u, int c)
{
	int sum = 1;
	ll sumz = ccnt[0][cnum[0][u]];
	cnum[1][u] = c;
	vis[1][u] = true;
	for (int v : A[1][u])
		if (!vis[1][v])
		{
			auto pir = dfso(v, c);
			sum += pir.first;
			sumz += pir.second;
		}
	return { sum, sumz };
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n - 1)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--; v--;
		A[c][u].push_back(v);
		A[c][v].push_back(u);
	}
	ll ans = 0;
	int cnter = 0;
	Loop(i, 0, n)
	{
		if (!vis[0][i])
		{
			ll x = dfsz(i, cnter);
			ccnt[0][cnter++] = x;
			ans += x * x - x;
		}
	}
	cnter = 0;
	Loop(i, 0, n)
	{
		if (!vis[1][i])
		{
			auto x = dfso(i, cnter++);
			ans += x.second * (x.first - 1);
		}
	}
	cout << ans << '\n';
}