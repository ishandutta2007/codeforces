#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
pll cor[2001];
ll c[2001];
ll k[2001];

int p[2001];
int sz[2001];

int getPar(int a)
{
	if (p[a] == a) return a;
	return p[a] = getPar(p[a]);
}

void uf_merge(int a, int b)
{
	int pa = getPar(a), pb = getPar(b);
	if (pa == pb) return;

	if (sz[pa] > sz[pb]) p[pb] = pa;
	else
	{
		p[pa] = pb;
		if (sz[pa] == sz[pb]) sz[pb]++;
	}
}

vector <pair<ll, pii> > dist;

void DFS(int i)
{

}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cor[i].first >> cor[i].second;
	}

	ll minC = 1000000001; int idx = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (c[i] < minC) minC = c[i], idx = i;
	}
	for (int i = 1; i <= n; i++) cin >> k[i];

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
	{
		ll dx = cor[i].first - cor[j].first;
		if (dx < 0) dx = -dx;
		ll dy = cor[i].second - cor[j].second;
		if (dy < 0) dy = -dy;

		ll cost = (dx + dy) * (k[i] + k[j]);
		dist.push_back({ cost,{ i,j } });
	}

	for (int i = 1; i <= n; i++)
		dist.push_back({ c[i],{0,i} });

	sort(dist.begin(), dist.end());

	for (int i = 0; i <= n; i++) p[i] = i, sz[i] = 1;

	ll res = 0;
	vector <int> powered;
	vector <pii> connected;
	int cnt = 0;

	for (auto it : dist)
	{
		ll cost = it.first;
		int x = it.second.first, y = it.second.second;
		int px = getPar(x), py = getPar(y);
		if (px == py) continue;

		if (x == 0) powered.push_back(y);
		else connected.push_back({ x,y });

		res += cost;
		uf_merge(px, py);
		cnt++;

		if (cnt == n) break;
	}

	if (powered.size() == 0)
	{
		powered.push_back(idx);
		res += minC;
	}

	cout << res << '\n';
	cout << powered.size() << '\n';
	for (auto it : powered) cout << it << ' ';
	cout << '\n';
	cout << connected.size() << '\n';
	for (auto it : connected) cout << it.first << ' ' << it.second << '\n';
}