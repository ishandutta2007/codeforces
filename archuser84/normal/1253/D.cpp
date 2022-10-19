#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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

int par[N];
int eend[N];
int find(int k)
{
	if (par[k] == -1)
		return k;
	par[k] = find(par[k]);
	return par[k];
}
void dsu(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u > v)
		swap(u, v);
	if (u == v)
		return;
	par[v] = u;
	eend[u] = max(eend[u], eend[v]);
}

struct seg
{
	int l, r;
	seg(int a, int b)
	{
		l = a;
		r = b;
	}
};

int main()
{
	FAST;
	int n, m;
	cin >> n >> m;
	memset(par, -1, 4 * n);
	Loop(i, 0, n)
		eend[i] = i;
	Loop(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		dsu(u, v);
	}
	vector<seg> s;
	Loop(i, 0, n)
	{
		if (par[i] != -1)
			continue;
		s.push_back(seg(i, eend[i]));
	}
	sort(s.begin(), s.end(), [](seg a, seg b)
		{
			return a.l < b.l;
		});
	int maax = -1;
	int ans = 0;
	Loop(i, 0, s.size())
	{
		ans += maax > s[i].l;
		maax = max(maax, s[i].r);
	}
	cout << ans << '\n';
}