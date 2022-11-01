#include<bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m, late[N][2];
struct edge
{
	int u, v, l, r;
	edge(int u, int v, int l, int r):u(u), v(v), l(l), r(r) {}
	bool operator < (const edge & a) const {return l > a.l;}
};
priority_queue<edge> que;
vector<edge> vec[N][2];

void update(int x, int st, int ed)
{
	late[x][st & 1] = max(late[x][st & 1], ed);
	for (edge e : vec[x][st & 1])
	{
		edge t = e;
		t.l = st;
		que.push(t);
	}
	vec[x][st & 1].clear();
}

int main()
{
	scanf("%d%d", &n, &m);
	if (n == 1) {printf("%d\n", 0); return 0;}
	for (int i = 1; i <= m; i++)
	{
		int a, b, l, r; scanf("%d%d%d%d", &a, &b, &l, &r); r--;
		int w = (l ^ r) & 1;
		que.push(edge(a, b, l, r - w));
		que.push(edge(b, a, l, r - w));
		que.push(edge(a, b, l + 1, r - (w ^ 1)));
		que.push(edge(b, a, l + 1, r - (w ^ 1)));
	}
	for (int i = 1; i <= n; i++) late[i][0] = late[i][1] = -1;
	late[1][0] = 0;
	int ans = -1;
	while (!que.empty())
	{
		edge e = que.top(); que.pop();
		if (e.l > e.r) continue;
		if (late[e.u][e.l & 1] >= e.l)
		{
			if (e.v == n) {ans = e.l + 1; break;}
			update(e.v, e.l + 1, e.r + 1);
		}
		else vec[e.u][e.l & 1].push_back(e);
	}
	printf("%d\n", ans);
	return 0;
}