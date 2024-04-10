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

const int N = 200010;
vector<int> A[N];
vector<int> T[N];
int n, m;
bool uni[N] = {};

// cycle detection //
bool vis1[N];
stack<int> dfsstack;
void dfs1(int u)
{
	vis1[u] = true;
	for (int v : A[u])
		if (!vis1[v])
			dfs1(v);
	dfsstack.push(u);
}
bool hasCycle()
{
	memset(vis1, 0, n);
	Loop(i, 0, n)
		if (!vis1[i])
			dfs1(i);
	memset(vis1, 0, n);
	while(!dfsstack.empty())
	{
		int u = dfsstack.top();
		dfsstack.pop();
		for (int v : T[u])
			if (!vis1[v])
				return true;
		vis1[u] = true;
	}
	return false;
}
/////////////////////

int mina[N];
int mint[N];
int DoA(int u)
{
	if (mina[u] != -1)
		return mina[u];
	mina[u] = u;
	for (int v : A[u])
		mina[u] = min(mina[u], DoA(v));;
	return mina[u];
}
int DoT(int u)
{
	if (mint[u] != -1)
		return mint[u];
	mint[u] = u;
	for (int v : T[u])
		mint[u] = min(mint[u], DoT(v));;
	return mint[u];
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
		T[v].push_back(u);
	}
	if (hasCycle())
	{
		cout << "-1\n";
		return 0;
	}
	memset(mina, -1, 4 * n);
	memset(mint, -1, 4 * n);
	int ans = 0;
	Loop(i, 0, n)
	{
		if(i == min(DoA(i), DoT(i)))
		{
			ans++;
			uni[i] = 1;
		}
	}
	cout << ans << '\n';
	Loop(i, 0, n)
		cout << (uni[i] ? 'A' : 'E');
}