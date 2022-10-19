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
pii E[N];
int n;
vector<int> A[1 << 20];
vector<pair<int,bool> > tag[1 << 20];

bool vis[1 << 20];
void dfs(int u)
{
	vis[u] = true;
	for (int v : A[u])
		if(!vis[v])
			dfs(v);
}

bool is(int k)
{
	k = 1 << k;
	Loop(i, 0, k)
		A[i].clear();
	int l = k - 1;
	Loop(i, 0, n)
	{
		A[E[i].first & l].push_back(E[i].second & l);
		A[E[i].second & l].push_back(E[i].first & l);
	}
	Loop(i, 0, k)
		if (A[i].size() & 1)
			return false;
	memset(vis, 0, k);
	int cnt = 0;
	Loop(i, 0, k)
		if (A[i].size() > 0 && !vis[i])
		{
			dfs(i);
			cnt++;
		}
	return cnt == 1;
}

void create(int k)
{
	k = 1 << k;
	Loop(i, 0, k)
		A[i].clear();
	int l = k - 1;
	Loop(i, 0, n)
	{
		A[E[i].first & l].push_back(E[i].second & l);
		A[E[i].second & l].push_back(E[i].first & l);
		tag[E[i].first & l].push_back({ i,0 });
		tag[E[i].second & l].push_back({ i,1 });
	}
}

bool vise[N];
int pass[1 << 20] = {};
int p[1 << 20] = {};
void euler(int s)
{
	int u = s;
	queue<int> Q;
	queue<pair<int,bool> > Q2;
	while (pass[s] < A[s].size())
	{
		while (vise[tag[u][p[u]].first])
			p[u]++;
		vise[tag[u][p[u]].first] = true;
		Q.push(u);
		Q2.push(tag[u][p[u]]);
		pass[u]++;
		u = A[u][p[u]];
		pass[u]++;
	}
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		if (pass[u] < A[u].size())
			euler(u);
		auto e = Q2.front();
		Q2.pop();
		if (!e.second)
			cout << 2 * e.first + 1 << ' ' << 2 * e.first + 2 << ' ';
		else
			cout << 2 * e.first + 2 << ' ' << 2 * e.first + 1 << ' ';
	}
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> E[i].first >> E[i].second;
	}
	int ans = 20;
	Loop(i, 1, 21)
	{
		if (!is(i))
		{
			ans = i - 1;
			break;
		}
	}
	cout << ans << '\n';
	create(ans);
	Loop(i,0,1 << ans)
		if (A[i].size())
		{
			euler(i);
			break;
		}
}