#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int p[300001];

int rc[300001];
int rp[300001];

set <int> graph[300001];
vector <vector <int> > grp;
int grp_num[300001];
int grp_idx[300001];

int in[300001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		if (rc[x] || rp[y])
		{
			cout << 0;
			return 0;
		}

		rc[x] = y;
		rp[y] = x;
	}

	for (int i = 1; i <= n; i++)
	{
		if (rp[i]) continue;

		vector <int> cg;

		int idx = 0;
		int ci = i;
		while (rc[ci])
		{
			cg.push_back(ci);
			grp_num[ci] = grp.size();
			grp_idx[ci] = idx++;
			ci = rc[ci];
		}

		cg.push_back(ci);
		grp_num[ci] = grp.size();
		grp_idx[ci] = idx;

		grp.push_back(cg);
	}

	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 0) continue;
		int pg = grp_num[p[i]];
		int cg = grp_num[i];

		if (pg != cg)
		{
			if (graph[pg].find(cg) != graph[pg].end()) continue;

			graph[pg].insert(cg);
			in[cg]++;
		}
		else
		{
			if (grp_idx[p[i]] > grp_idx[i])
			{
				cout << 0;
				return 0;
			}
		}
	}

	vector <int> ans;
	queue <int> q;
	for (int i = 0; i < grp.size(); i++)
	{
		if (in[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int cg = q.front(); q.pop();
		for (auto v : grp[cg]) ans.push_back(v);
		for (auto ng : graph[cg])
		{
			if (--in[ng] == 0) q.push(ng);
		}
	}

	if (ans.size() != n)
	{
		cout << 0;
		return 0;
	}

	for (auto v : ans) cout << v << ' ';
}