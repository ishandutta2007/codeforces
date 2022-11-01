#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<int, int> pi;

const int N = 5005;

int n, m, n1, n2, n3, dep[N], col[N], ans[N], s0, s1, f[N][N], pre[N][N];
vector<int> e[N];
vector<pi> vec;
bool vis[N], flag;

void dfs(int x, int id)
{
	col[x] = id;
	if (!dep[x]) s0++;
	else s1++;
	vis[x] = 1;
	for (auto to : e[x])
		if (!vis[to]) dep[to] = dep[x] ^ 1, dfs(to, id);
		else if (dep[to] == dep[x]) flag = 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &n1, &n2, &n3);
	for (int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
		{
			s0 = s1 = 0;
			dfs(i, vec.size());
			vec.pb(make_pair(s0, s1));
		}
	if (flag)
	{
		puts("NO");
		return 0;
	}
	f[0][0] = 1;
	for (int i = 0; i < vec.size(); i++)
		for (int j = 0; j <= n; j++) if (f[i][j])
		{
			f[i + 1][j + vec[i].first] = 1;
			pre[i + 1][j + vec[i].first] = 0;
			f[i + 1][j + vec[i].second] = 1;
			pre[i + 1][j + vec[i].second] = 1;
		}
	if (!f[vec.size()][n2]) puts("NO");
	else
	{
		puts("YES");
		for (int i = vec.size(), now = n2; i >= 1; now -= !pre[i][now] ? vec[i - 1].first : vec[i - 1].second, i--)
			for (int j = 1; j <= n; j++)
				if (col[j] == i - 1 && dep[j] == pre[i][now]) ans[j] = 2;
				else if (col[j] == i - 1)
				{
					if (n1) ans[j] = 1, n1--;
					else ans[j] = 3;
				}
		for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	}
	return 0;
}