#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500010;

int tin[MAXN];
int tout[MAXN];
vector <int> g[MAXN];
int p[30];
vector <pair <int, int> > x0r[MAXN];
int v, h;
string c;
int tt = 0;

void dfs(int v, int h, int pr) {
    tin[v] = ++tt;
    x0r[h].push_back({tt, x0r[h].back().second ^ (p[(c[v] - 'a')])});
    for (int i = 0; i < (int) g[v].size(); i++) 
	if (g[v][i] != pr) 
	    dfs(g[v][i], h + 1, v);
    tout[v] = ++tt;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 30; i++)
	p[i] = (1 << i);
    for (int i = 0; i < n; i++)
	x0r[i].resize(1);
    for (int i = 1; i < n; i++) {
	int t;
	cin >> t;
	t--;
	g[i].push_back(t);
	g[t].push_back(i);
    }
    cin >> c;
    dfs(0, 0, 0);
    for (int i = 0; i < m; i++) {
	cin >> v >> h;
	v--, h--;
	int l = 0;
	int r = x0r[h].size();
	while (l < r - 1) {
	    int m = (l + r) / 2;
	    if (m < x0r[h].size() && x0r[h][m].first >= tin[v])
		r = m;
	    else
		l = m;
	}
	int left_border = r - 1;
	l = 0;
	r = x0r[h].size();
	while (l < r - 1) {
	    int m = (l + r) / 2;
	    if (m < x0r[h].size() && x0r[h][m].first >= tout[v])
		r = m;
	    else
		l = m;
	}
	int right_border = r - 1;
	int t = x0r[h][left_border].second ^ x0r[h][right_border].second;
	if (__builtin_popcount(t) <= 1)
	    puts("Yes");
	else
	    puts("No");
    }
}