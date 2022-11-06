#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
ll a[200001];
ll b[200001];

int par[200001];
int child[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int b; cin >> b;
		par[i] = b;
		child[b]++;
	}

	queue <int> q;
	for (int i = 1; i <= n; i++) if (child[i] == 0) q.push(i);

	ll ans = 0;
	vector <int> p;
	vector <int> inv;

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		ans += a[v];

		if (a[v] >= 0)
		{
			p.push_back(v);
			if (par[v] != -1) a[par[v]] += a[v];
		}
		else
		{
			inv.push_back(v);
		}

		if (par[v] != -1 && --child[par[v]] == 0) q.push(par[v]);
	}

	reverse(inv.begin(), inv.end());

	cout << ans << '\n';
	for (int v : p) cout << v << ' ';
	for (int v : inv) cout << v << ' ';
}