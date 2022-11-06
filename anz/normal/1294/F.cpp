#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
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
vector <int> tree[200001];

int mlen;
int mv;

void DFS(int s, int p, int len)
{
	if (mlen < len)
	{
		mlen = len;
		mv = s;
	}

	for (auto &it : tree[s])
	{
		if (it == p) continue;
		DFS(it, s, len + 1);
	}
}

bool hasFound = false;
vector <int> stk;
void DFS2(int s, int p, int tf)
{
	stk.push_back(s);
	if (s == tf)
	{
		hasFound = true;
		return;
	}

	for (auto &it : tree[s])
	{
		if (it == p) continue;		
		DFS2(it, s, tf);
		if (hasFound) return;
	}
	stk.pop_back();
}

int dist[200001];
queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	int ansLen = 0;

	mlen = 0;
	DFS(1, -1, 0);

	int ans1 = mv;
	mlen = 0;
	DFS(ans1, -1, 0);
	int ans2 = mv;
	ansLen += mlen;

	DFS2(ans1, -1, ans2);

	memset(dist, -1, sizeof dist);
	for (auto&it : stk)
	{
		dist[it] = 0;
		q.push(it);
	}

	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (auto&it : tree[v])
		{
			if (dist[it] != -1) continue;
			dist[it] = dist[v] + 1;
			q.push(it);
		}
	}

	int ans3 = -1, d3 = -1;
	for (int i = 1; i <= n; i++)
	{
		if (i == ans1 || i == ans2) continue;
		if (dist[i] > d3)
		{
			d3 = dist[i];
			ans3 = i;
		}
	}

	ansLen += d3;
	cout << ansLen << '\n';
	cout << ans1 << ' ' << ans2 << ' ' << ans3;
}