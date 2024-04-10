#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;
const int INF = 987654321;

int n;
ll a[N];
int b[N];
int c[N];

vector <int> graph[N];
int child[N][2];

int DFS_cnt = 0;
int DFS_num[N];
void DFS(int v, int p)
{
	DFS_num[v] = ++DFS_cnt;
	child[v][0] = DFS_cnt;

	for (int nv : graph[v])
	{
		if (nv == p) continue;
		DFS(nv, v);
	}

	child[v][1] = DFS_cnt;
}

int cnt0[N];
int cnt1[N];
int valid[N];

void fw_update(int* segTree, int i, int x)
{
	while (i <= n)
	{
		segTree[i] += x;
		i += i & -i;
	}
}

int fw_getVal(int* segTree, int i)
{
	int res = 0;
	while (i)
	{
		res += segTree[i];
		i -= i & -i;
	}

	return res;
}

int fw_getVal(int* segTree, int i, int j)
{
	return fw_getVal(segTree, j) - fw_getVal(segTree, i - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	int sumb = 0, sumc = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		sumb += b[i], sumc += c[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if (sumb != sumc)
	{
		cout << -1;
		return 0;
	}

	DFS(1, 0);

	priority_queue <pll> pq;
	for (int i = 1; i <= n; i++)
	{
		pq.push({ -a[i], i });

		if (b[i] != c[i])
		{
			if (b[i] == 0)
				fw_update(cnt0, DFS_num[i], 1);
			else
				fw_update(cnt1, DFS_num[i], 1);
		}
	}

	ll ans = 0;
	while (!pq.empty())
	{
		ll cost = -pq.top().first;
		int v = pq.top().second;
		pq.pop();

		if (fw_getVal(valid, DFS_num[v])) continue;

		int res0 = fw_getVal(cnt0, child[v][0], child[v][1]);
		int res1 = fw_getVal(cnt1, child[v][0], child[v][1]);

		int res = min(res0, res1);

		ans += cost * res * 2;
		fw_update(cnt0, DFS_num[v], -res);
		fw_update(cnt1, DFS_num[v], -res);

		fw_update(valid, child[v][0], 1);
		fw_update(valid, child[v][1] + 1, -1);
	}

	cout << ans;
}