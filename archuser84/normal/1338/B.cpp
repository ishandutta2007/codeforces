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

const int N = 100010;
vector<int> A[N];
bool ex[2];
int par[N];
bool haveleaf[N] = {};
int maax;

void dfs(int u, int p, bool c)
{
	par[u] = p;
	if (A[u].size() == 1)
	{
		ex[c] = true;
		maax -= haveleaf[p];
		haveleaf[p] = true;
	}
	else
	{
		for (int v : A[u])
			if (v != p)
				dfs(v, u, !c);
	}
}

int main()
{
	FAST;
	int n;
	cin >> n;
	maax = n - 1;
	Loop(i, 0, n - 1)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i, 0, n)
	{
		if (A[i].size() > 1)
		{
			dfs(i, -1, 0);
			break;
		}
	}
	if ((!ex[0]) || (!ex[1]))
		cout << "1 ";
	else
		cout << "3 ";
	cout << maax;
}