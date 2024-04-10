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

const int N = 500010;
vector<int> A[N];
pii dt[N];
int n, m;
int tag[N] = {};
int ans[N];

bool check()
{
	Loop(u, 0, n)
	{
		for (auto v : A[u])
		{
			if (dt[u].second == dt[v].second)
				return false;
		}
	}
	return true;
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i, 0, n)
	{
		dt[i].first = i;
		cin >> dt[i].second;
	}
	if (!check())
	{
		cout << "-1\n";
		return 0;
	}
	sort(dt, dt + n, [](pii a, pii b)
		{
			return a.second < b.second;
		});
	Loop(i, 0, n)
	{
		if(tag[dt[i].first] != dt[i].second - 1)
		{
			cout << "-1\n";
			return 0;
		}
		ans[i] = dt[i].first + 1;
		for (auto v : A[dt[i].first])
			if (tag[v] == dt[i].second - 1)tag[v]++;
	}
	Loop(i, 0, n)
		cout << ans[i] << ' ';
}