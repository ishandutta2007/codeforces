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

const int N = 200010;
vector<int> A[N];
vector<int> E[N];
int w[N];
bool visv[N] = {};
bool vise[N] = {};
int d[N];
int n, m;
stack<int> ans;

void dfs(int u)
{
	visv[u] = true;
	for (int e : E[u])
	{
		if (!vise[e])
		{
			vise[e] = true;
			ans.push(e);
		}
	}
	for (int v : A[u])
	{
		d[v]--;
		if (!visv[v] && w[v] >= d[v])
			dfs(v);
	}
}

int main()
{
	FAST;
	cin >> n >> m;
	Loop(i, 0, n)
		cin >> w[i];
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
		E[u].push_back(i + 1);
		E[v].push_back(i + 1);
	}
	Loop(i, 0, n)
		d[i] = A[i].size();
	Loop(i, 0, n)
		if (w[i] >= d[i] && !visv[i])
			dfs(i);
	if (ans.size() < m)
		Kill("DEAD");
	cout << "ALIVE\n";
	while (ans.size())
	{
		int x = ans.top();
		ans.pop();
		cout << x << ' ';
	}
}