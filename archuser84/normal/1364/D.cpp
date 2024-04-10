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
vector<int> ind;
int n, m;

bool vis[N] = {};
int par[N] = {};
int d[N];
void Print2(int u, int v)
{
	int anc = -1;
	int a = u, b = v;
	if (d[a] > d[b])
		swap(a, b);
	while (d[b] > d[a])
		b = par[b];
	while (a != b)
	{
		a = par[a];
		b = par[b];
	}
	anc = a;
	cout << "2\n" << d[u] + d[v] + 1 - 2*d[anc] << '\n';
	while (u != anc)
	{
		cout << u + 1 << ' ';
		u = par[u];
	}
	stack<int> S;
	while (v != par[anc])
	{
		S.push(v);
		v = par[v];
	}
	while (!S.empty())
	{
		cout << S.top() + 1 << ' ';
		S.pop();
	}
}
void Print1()
{
	cout << "1\n";
	for (int x : ind)
		cout << x + 1 << ' ';
}
bool bfs(int s)
{
	queue<int> Q;
	vector<int> a[2];
	vis[s] = true;
	par[s] = -1;
	d[s] = 0;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		a[d[u] & 1].push_back(u);
		for (int v : A[u])
		{
			if (v == par[u])
				continue;
			if (vis[v])
			{
				Print2(u, v);
				return 1;
			}
			Q.push(v);
			d[v] = d[u] + 1;
			vis[v] = 1;
			par[v] = u;
		}
	}
	int k = a[0].size() < a[1].size();
	while (!a[k].empty())
	{
		ind.push_back(a[k].back());
		a[k].pop_back();
		if (ind.size() == (n + 1) / 2)
		{
			Print1();
			return 1;
		}
	}
	return 0;
}

int main()
{
	FAST;
	cin >> n >> m >> n;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		if (u > n || v > n)
			continue;
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	Loop(i, 0, n)
	{
		if (vis[i])
			continue;
		if (bfs(i))
			return 0;
	}
}