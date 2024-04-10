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

const int N = 100010;
vector<int> A[N];
double f[N]; int h[N];
int n;

void dfs(int u, int p, int d, int& k)
{
	h[k++] = d;
	for (int v : A[u])
		if (v != p)
			dfs(v, u, d + 1, k);
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 1, n)
	{
		int u, v;
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	int k = 0;
	dfs(1, -1, 1, k);
	f[0] = 1;
	Loop(i, 1, n)
		f[i] = f[i - 1] * (h[i] - 1) / h[i] + (f[i - 1] + 1) / h[i];
	cout << fixed << setprecision(9) << f[n - 1];
}