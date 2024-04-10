#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n)*(n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<int, int> mp;
typedef long long LL ;
const int maxn = 1e5 + 5;
const int mod = 998244353;
const int base = 131;

char str[31][maxn];
int zip[31][maxn];
int id[31][maxn];
int n, pw[maxn], inc[maxn], len[maxn], tot, maxl;
vector<int> adj[maxn];
int deg[maxn], s[maxn];
queue<int> Q;
#define add(u, v) adj[u].pb(v), ++deg[v];

int fpm(int p, int k)
{
	int res = 1;
	for (; k ; k >>= 1, p = (LL) p * p % mod)
		if (k & 1) res = (LL) res * p % mod;
	return res;
}
int Hash(int i, int l, int r)
{
	int _zip = (LL) (zip[i][r] - zip[i][l - 1]) * inc[l] % mod;
	return _zip < 0 ? _zip + mod : _zip;
}
bool check(int l, int r)
{
	if (l > r) return true;
	for (int i = s[r] ; i >= s[l - 1] ; i--)
		adj[i].clear(), deg[i] = 0;
	int ex = s[l - 1];
	for (int i = l ; i <= r ; i++)
	for (int j = l ; j <= r ; j++)
	for (int t = 1 ; t < len[i] ; t++)
	{
		if (t == len[j])
		{
			if (Hash(i, len[i] - t + 1, len[i]) == Hash(j, 1, t))
				add(id[i][t], ex);
		}
		else if (t < len[j])
		{
			if (Hash(i, len[i] - t + 1, len[i]) == Hash(j, 1, t))
				add(id[i][t], id[j][len[j] - t] );
		}
		else
		{
			if (Hash(i, len[i] - t + 1, len[i] - t + len[j]) == Hash(j, 1, len[j]))
				add(id[i][t], id[i][t - len[j]] );
		}
	}
	for (int i = l ; i <= r ; i++)
	for (int j = l ; j <= r ; j++)
	if (len[i] > len[j] && Hash(i, 1, len[j]) == Hash(j, 1, len[j]))
		add(ex, id[i][len[i] - len[j]]);
	
	int cnt = s[r] - s[l - 1] + 1;
	for (int i = s[r] ; i >= s[l - 1] ; i--)
		if ( !deg[i]) Q.push(i);
	while ( !Q.empty())
	{
		int u = Q.front(); Q.pop(); --cnt;
		for (auto v: adj[u])
			if ( !--deg[v]) Q.push(v);
	}
	return cnt == 0;
}
int main()
{
	#ifdef FILE_TESTn
		freopen("shift.in", "r", stdin);
	#endif
	
	scanf("%d", &n);
	rep(i, n) {
		scanf("%s", str[i] + 1);
		len[i] = strlen(str[i] + 1);
		per(j, len[i] - 1) id[i][j] = ++tot;
		maxl = max(maxl, len[i]);
		s[i] = tot;
	}
	pw[0] = 1; inc[0] = 1;
	int _inc = fpm(base, mod - 2);
	repi(maxl) pw[i] = (LL) pw[i - 1] * base % mod;
	repi(maxl) inc[i] = (LL) inc[i - 1] * _inc % mod;
	
	repi(n) {
		rep(j, len[i]) zip[i][j] = (zip[i][j - 1] + (LL) pw[j] * str[i][j]) % mod;
	}
	int ans = 0;
	for (int j = 0, i = 1; i <= n; i++)
	{
		while (j < n && check(i, j + 1)) ++j;
		ans +=  j - i + 1;
	}
	printf("%d", ans);
	return 0;
}