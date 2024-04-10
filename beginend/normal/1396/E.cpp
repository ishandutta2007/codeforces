#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> pi;

const int N = 100005;

int n, w[N], size[N], id[N];
LL k;
vector<int> vec[N], e[N];
priority_queue<pi> que;

void pre(int x, int fa)
{
	size[x] = 1;
	for (int to : e[x])
		if (to != fa) pre(to, x), size[x] += size[to];
	w[x] = min(size[x], n - size[x]);
}

void binary()
{
	int l = 0, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		LL s = 0;
		for (int i = 1; i <= n; i++)
			s += w[i] >= mid ? mid + ((w[i] - mid) & 1) : w[i];
		if (s >= k) r = mid - 1;
		else l = mid + 1;
	}
	r++; LL s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (w[i] >= r) w[i] = r + ((w[i] - r) & 1);
		s += w[i];
	}
	for (int i = 1; i <= n; i++) if (s > k && w[i] == r + 1) w[i] -= 2, s -= 2;
}

void solve(int x, int fa)
{
	id[x] = x;
	vec[x].push_back(x);
	int s = 1;
	for (int to : e[x]) if (to != fa)
	{
		solve(to, x);
		s += vec[id[to]].size();
	}
	while (!que.empty()) que.pop();
	que.push(make_pair(1, x));
	for (int to : e[x])
		if (to != fa && vec[id[to]].size()) que.push(make_pair(vec[id[to]].size(), id[to]));
	while (s > w[x])
	{
		pi u = que.top(); que.pop();
		pi v = que.top(); que.pop();
		printf("%d %d\n", vec[u.second].back(), vec[v.second].back());
		vec[u.second].pop_back(); vec[v.second].pop_back();
		u.first--; v.first--;
		if (u.first) que.push(u);
		if (v.first) que.push(v);
		s -= 2;
	}
	for (int to : e[x]) if (to != fa && vec[id[to]].size())
	{
		if (vec[id[to]].size() > vec[id[x]].size()) swap(id[x], id[to]);
		for (int p : vec[id[to]]) vec[id[x]].push_back(p);
		vec[id[to]].clear();
	}
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		e[x].push_back(y); e[y].push_back(x);
	}
	pre(1, 0);
	LL L = 0, R = 0;
	for (int i = 1; i <= n; i++) L += w[i] & 1, R += w[i];
	if (k % 2 != R % 2 || k < L || k > R) {puts("NO"); return 0;}
	binary();
	puts("YES");
	solve(1, 0);
	return 0;
}