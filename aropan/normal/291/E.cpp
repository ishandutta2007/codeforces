#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }

const int MAXN = 500007;

string s[MAXN];
vector <int> e[MAXN];
string c;
int k[MAXN];
int n, m;
int ans = 0;

void dfs(int x, int p)
{
	for (int i = 0; i < (int)s[x].size(); i++)
	{
		while (p && c[p + 1] != s[x][i]) p = k[p];
		p += c[p + 1] == s[x][i];
		if (p == m)
		{
			p = k[p];
			ans += 1;
		}
	}
	
	for (int i = 0; i < (int)e[x].size(); i++)
		dfs(e[x][i], p);
}



int main()
{
	ios_base::sync_with_stdio(0);
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int p;
		cin >> p >> s[i];
		e[p].push_back(i);
	}
	cin >> c;
	m = c.size();
	c = " " + c;
	for (int i = 2; i <= m; i++)
	{
		int x = k[i - 1];
		while (x && c[x + 1] != c[i]) x = k[x];
		k[i] = x + (c[x + 1] == c[i]);
	}
	
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}