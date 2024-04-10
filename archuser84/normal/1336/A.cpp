#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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

const int N = 200000;
vector<int> A[N];
int n;
int d[N];
int c[N];

int dfs(int u,int p,int h)
{
	d[u] = h;
	int ans = 0;
	for (int v : A[u])
		if (v != p)
			ans += dfs(v, u, h + 1);
	c[u] = ans;
	return ans + 1;
}

bool my_sort(int a, int b)
{
	return d[a] - c[a] > d[b] - c[b];
}

int main()
{
	FAST;
	int k;
	cin >> n >> k;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	dfs(0, -1, 0);
	int a[N];
	Loop(i, 0, n)
		a[i] = i;
	sort(a, a + n, my_sort);
	ll sum = 0;
	Loop(i, 0, k)
	{
		sum += d[a[i]] - c[a[i]];
	}
	cout << sum << '\n';
}