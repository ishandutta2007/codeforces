#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int ans[1001];

int n;
int a[501][501];

int uf_par[1001];
int uf_val[1001];
int getPar(int a)
{
	if (uf_par[a] == a) return a;
	return uf_par[a] = getPar(uf_par[a]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i <= 1000; i++) uf_par[i] = i;

	vector <pair<int, pii> > vec;

	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
	{
		cin >> a[i][j];
		if (i == j) uf_val[i] = a[i][j];
		if (i < j) vec.push_back({ a[i][j],{i,j} });
	}

	sort(vec.begin(), vec.end());

	int cur = n + 1;

	for (auto it : vec)
	{
		int w = it.first;
		int u = it.second.first;
		int v = it.second.second;

		u = getPar(u);
		v = getPar(v);

		if (u == v) continue;

		if (uf_val[u] > uf_val[v]) swap(u, v);

		if (w == uf_val[v])
		{
			uf_par[u] = v;
			ans[u] = v;
		}
		else if (w > uf_val[v])
		{
			uf_par[u] = cur;
			uf_par[v] = cur;
			ans[u] = ans[v] = cur;
			uf_val[cur] = w;
			cur++;
		}
		else return 1;
	}

	int rt = -1;

	cout << cur - 1 << '\n';
	for (int i = 1; i < cur; i++)
	{
		cout << uf_val[i] << ' ';
		if (ans[i] == 0) rt = i;
	}
	cout << '\n';

	cout << rt << '\n';
	for (int i = 1; i < cur; i++)
	{
		if (i == rt) continue;
		cout << i << ' ' << ans[i] << '\n';
	}
}