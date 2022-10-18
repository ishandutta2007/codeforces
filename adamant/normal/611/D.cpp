#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

string s;
int n;

#define fpos algkla

const int maxn = 5e3 * 2 + 42, logn = 18;
int link[maxn], fpos[maxn], len[maxn];
map<char, int> to[maxn];
int up[maxn][logn];
int state[maxn];
int last = 0, sz = 1;

int add_letter(char c)
{
	int p = last;
	last = sz++;
	len[last] = fpos[last] = len[p] + 1;
	for(; to[p][c] == 0; p = link[p])
		to[p][c] = last;
	if(to[p][c] == last)
		return last;
	int q = to[p][c];
	if(len[q] == len[p] + 1)
	{
		link[last] = q;
		return last;
	}
	int cl = sz++;
	to[cl] = to[q];
	link[cl] = link[q];
	fpos[cl] = fpos[q];
	len[cl] = len[p] + 1;
	link[last] = link[q] = cl;
	for(; to[p][c] == q; p = link[p])
		to[p][c] = cl;
	return last;
}

vector<int> g[maxn];
int in[maxn], out[maxn];
int t = 1;
void dfs(int v = 0)
{
	in[v] = ++t;
	for(auto u: g[v])
		dfs(u);
	out[v] = ++t;
}

void init()
{
	reverse(s.begin(), s.end());
	for(int i = 0; i < n; i++)
		state[i] = add_letter(s[i]);
	for(int i = 0; i < sz; i++)
		up[i][0] = link[i];
	for(int j = 1; j < logn; j++)
		for(int i = 0; i < sz; i++)
			up[i][j] = up[up[i][j - 1]][j - 1];
	for(int i = 1; i < sz; i++)
		g[link[i]].push_back(i);
	dfs();
}

bool is_anc(int a, int b)
{
	return in[a] <= in[b] && out[b] <= out[a];
}

int lca(int a, int b)
{
	for(int i = logn - 1; i >= 0; i--)
		if(!is_anc(up[a][i], b))
			a = up[a][i];
	if(!is_anc(a, b))
		a = up[a][0];
	return a;
}

bool check(int pos, int ln)
{
	pos = n - pos + ln - 1;
	int a = state[pos], b = state[pos + ln];
	int lc = lca(a, b);
	if(len[lc] >= ln)
		return 0;
	char A = s[fpos[a] - len[lc] - 1];
	char B = s[fpos[b] - len[lc] - 1];
	return A > B;
}

const int maxN = 5000 + 42;
	int dp[maxN + 1][maxN + 1];
	int sdp[maxN + 1][maxN + 1];

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	string S = s;
	init();
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			if(S[i - j] == '0')
				continue;
			dp[i][j] += sdp[i - j][j - 1];
			
			if(2 * j > i || (check(i, j) && S[i - 2 * j] != '0'))
				dp[i][j] += dp[i - j][j];
			dp[i][j] %= mod;
			sdp[i][j] = (dp[i][j] + sdp[i][j - 1]) % mod;
		}
		for(int j = 1; j <= n; j++)
			sdp[i][j] = (sdp[i][j - 1] + dp[i][j]) % mod;
	}
	cout << sdp[n][n] << "\n";
}