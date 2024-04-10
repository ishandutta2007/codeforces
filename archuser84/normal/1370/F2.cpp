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

const int N = 2010;
vector<int> A[N];
vector<int> table[N];
int h[N];
int hmax[N];
int par[N];
int n;
int r;
int dis;

void dfs(int u, int p, int d)
{
	par[u] = p;
	h[u] = d;
	hmax[u] = h[u];
	table[d].push_back(u);
	for (int v : A[u])
		if (v != p)
		{
			dfs(v, u, d + 1);
			hmax[u] = max(hmax[u], hmax[v]);
		}
}

pii bin(int a, int b, int ans)
{
	int l = a, r = b;
	while (l < r)
	{
		int m = (l + r + 1) / 2;
		int cnt = 0;
		Loop(i, m, r + 1)
			cnt += table[i].size();
		int v, x = -1;
		if (cnt > 0)
		{
			printf("? %d ", cnt);
			Loop(i, m, r + 1)
				for (int u : table[i])
					printf("%d ", u + 1);
			printf("\n");
			fflush(stdout);
			scanf("%d%d", &v, &x); v--;
		}
		if (x == dis)
		{
			ans = v;
			l = m;
		}
		else
			r = m - 1;
	}
	return { ans, l };
}

void Solve()
{
	scanf("%d", &n);
	Loop(i, 0, n)
	{
		A[i].clear();
		table[i].clear();
	}
	Loop(i, 1, n)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	printf("? %d ", n);
	Loop(i, 0, n)
		printf("%d ", i + 1);
	printf("\n");
	fflush(stdout);
	scanf("%d%d", &r, &dis); r--;
	dfs(r, -1, 0);
	vector<int> arr;
	for (int u : A[r])
		arr.push_back(hmax[u]);
	arr.push_back(0);
	sort(all(arr));
	pii ans;
	if ((dis ^ (arr[A[r].size() - 1] + 1)) > (arr[A[r].size() - 1] + 1))
		ans = bin(dis - arr[A[r].size() - 1], dis, -1);
	else
		ans = bin(0, dis, -1);
	if (ans.first == -1)
	{
		printf("? %d ", (int)table[ans.second].size());
		for (int u : table[ans.second])
			printf("%d ", u + 1);
		printf("\n");
		fflush(stdout);
		int tmp;
		scanf("%d%d", &ans.first, &tmp); ans.first--;
	}
	int k = dis - ans.second;
	if (k == 0)
	{
		printf("! %d %d\n", ans.first + 1, r + 1);
		fflush(stdout);
		return;
	}
	int anc = ans.first;
	while (h[anc] != k) anc = par[anc];
	printf("? %d ", table[k].size() - 1);
	for (int u : table[k])
		if(u != anc)
			printf("%d ", u + 1);
	printf("\n");
	fflush(stdout);
	int tmp, other;
	scanf("%d%d", &other, &tmp); other--;
	printf("! %d %d\n", ans.first + 1, other + 1);
	fflush(stdout);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		Solve();
		char s[16];
		scanf("%s", &s);
		if (s[0] == 'I')
			break;
	}
}