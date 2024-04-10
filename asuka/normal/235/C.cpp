#include<bits/stdc++.h>
#define ll long long
#define N 2000015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int vis[N << 1], dp[N << 1];
namespace SAM {
int len[N << 1], link[N << 1], ch[N << 1][26], last, sz;
void init() {
	link[0] = -1;
}
void insert(int c) {
	int cur = ++sz;
	len[cur] = len[last] + 1; dp[cur] = 1;
	int p = last;
	while (~p && !ch[p][c]) ch[p][c] = cur, p = link[p];
	if (p == -1) link[cur] = 0;
	else {
		int q = ch[p][c];
		if (len[q] == len[p] + 1) link[cur] = q;
		else {
			int clone = ++sz;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			rep(i, 0, 25) ch[clone][i] = ch[q][i];
			while (~p && ch[p][c] == q) ch[p][c] = clone, p = link[p];
		}
	}
	last = cur;
}
int solve(char *s, int L, int id) {
	int u = 0, res = 0, l = 0;
	for (int i = 1; s[i]; i++) {
		if (ch[u][s[i] - 'a']) {
			l++;
			u = ch[u][s[i] - 'a'];
		} else {
			while (!ch[u][s[i] - 'a'] && ~u) u = link[u];
			if (~u) {
				l = len[u] + 1;
				u = ch[u][s[i] - 'a'];
			} else {
				l = 0;
				u = 0;
			}
		}
		// printf("CUR %d %d\n", u, l);
		if (l >= L) {
			while (link[u] && len[link[u]] + 1 > L) u = link[u];
			if (vis[u] != id) {
				vis[u] = id;
				res += dp[u];
			}
		}
	}
	return res;
}
}
using namespace SAM;
int p[N];
char s[N], t[N];
bool cmp(int u, int v) {
	return len[u] > len[v];
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s", s + 1);
	init();
	for (int i = 1; s[i]; ++i) insert(s[i] - 'a');
	rep(i, 1, sz) p[i] = i;
	sort(p + 1, p + sz + 1, cmp);
	rep(i, 1, sz) dp[link[p[i]]] += dp[p[i]]; // , printf("%d\n", p[i]);
	// rep(i, 1, sz) printf("%d <- %d\n", st[i].link, i);
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%s", t + 1);
		int len = strlen(t + 1);
		rep(i, len + 1, len + len - 1) t[i] = t[i - len];
		t[len + len] = '\0';
		printf("%d\n", solve(t, len, q + 1));
	}
	return 0;
}
/*
baabaabaaa
1
aabaa -> abaaa -> baaaa -> aaaab -> aaaba

aabaaaabaa
*/