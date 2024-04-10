#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int pearl[1000001];

vector <int> idx[1 << 20];
int last[1 << 20];

int prv[1000001];
int nxt[1000001];
int cache[500001];

int ans;

bool DFS(int v, int rt)
{
	cache[v / 2] = 1;
	int v2 = (v / 2 * 2) + 1 - v % 2;

	bool isFirst = true;

	int cidx = pearl[v] % (1 << ans);

	bool isConnected = false;

	for (int &i = last[cidx]; i < idx[cidx].size(); i++)
	{
		int nv = idx[cidx][i];
		int nv2 = (nv / 2 * 2) + 1 - nv % 2;
		if (cache[nv / 2]) continue;

		if (isFirst)
		{
			isFirst = false;

			nxt[v] = nv;
			prv[nv] = v;

			if (!DFS(nv2, rt)) return false;

			isConnected = true;
		}
		else
		{
			int new_rt = nxt[v];

			nxt[v] = nv;
			prv[nv] = v;

			if (!DFS(nv2, new_rt)) return false;

			isConnected = true;
		}
	}

	if (!isConnected)
	{
		if (pearl[v] % (1 << ans) == pearl[rt] % (1 << ans))
		{
			nxt[v] = rt;
			prv[rt] = v;

			return true;
		}
	}

	return isConnected;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pearl[i * 2] >> pearl[i * 2 + 1];

	for (ans = 20; ans > 0; ans--)
	{
		for (int i = 0; i < (1 << ans); i++) idx[i].clear();
		memset(last, 0, sizeof last);

		memset(prv, -1, sizeof prv);
		memset(nxt, -1, sizeof nxt);
		memset(cache, 0, sizeof cache);

		for (int i = 0; i < n; i++)
		{
			int t1 = pearl[i * 2] % (1 << ans);
			int t2 = pearl[i * 2 + 1] % (1 << ans);

			idx[t1].push_back(2 * i);
			idx[t2].push_back(2 * i + 1);
		}

		if (!DFS(1, 0)) continue;

		bool flag = false;
		for (int i = 0; i < n; i++) if (!cache[i]) flag = true;

		if (flag) continue;

		cout << ans << '\n';
		
		int v = 0;
		for (int i = 0; i < n; i++)
		{
			int v2 = (v / 2 * 2) + 1 - v % 2;
			cout << v + 1 << ' ' << v2 + 1 << ' ';
			
			v = nxt[v2];
		}

		return 0;
	}

	cout << "0\n";
	for (int i = 1; i <= 2 * n; i++) cout << i << ' ';
}