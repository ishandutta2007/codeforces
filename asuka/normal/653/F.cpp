#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
int n, val[N], lst[N], Min[N][21], ori[N];
ll ans;
char s[N];
int endpos[N << 1];
const int sft = 500000;
VI v[N << 1];
namespace SAM {
int len[N << 1], link[N << 1], ch[N << 1][26], last, sz;
void init() {
	link[0] = -1;
}
void insert(int c, int pos) {
	int cur = ++sz;
	endpos[cur] = pos;
	len[cur] = len[last] + 1;
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
}
using namespace SAM;
int query(int pos, int val) {
	return upper_bound(all(v[val]), pos) - v[val].begin() - 1;
}
int main() {
	// freopen("F.in","r",stdin);
	// freopen("F.out","w",stdout);
	scanf("%d", &n);
	scanf("%s", s + 1);
	rep(i, 1, n) {
		if (s[i] == '(') val[i] = val[i - 1] + 1;
		else val[i] = val[i - 1] - 1;
	}
	memset(Min, 0x3f, sizeof Min);
	rep(i, 1, n) Min[i][0] = val[i];
	v[0 + sft].pb(0);
	rep(i, 1, n) v[val[i] + sft].pb(i);
	rep(i, -n, n) sort(all(v[i + sft]));
	rep(j, 1, 19) rep(i, 1, n) if (i + (1 << j) - 1 <= n) {
		Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
	}
	rep(i, 1, n) {
		int pos = i;
		per(j, 0, 19) {
			if (pos - (1 << j) + 1 <= 0) continue;
			if (Min[pos - (1 << j) + 1][j] >= val[i]) pos -= (1 << j);
		}
		lst[i] = pos + 1;
	}
	init();
	rep(i, 1, n) insert(s[i] == '(' ? 0 : 1, i);
	rep(i, 1, sz) ori[i] = i;
	sort(ori + 1, ori + sz + 1, [] (int u, int v) {return len[u] > len[v];});
	rep(i, 1, sz)
		endpos[link[ori[i]]] = endpos[ori[i]];
	rep(i, 1, sz) {
		if (s[endpos[i]] == '(') continue;
		int L = max(lst[endpos[i]], endpos[i] - len[i] + 1), R = min(endpos[i] - len[link[i]], endpos[i]);
		int V = val[endpos[i]] + sft;
		int res = lower_bound(all(v[V]), R) - lower_bound(all(v[V]), L - 1);
		if (L - 1 <= R) ans += res;
	}
	printf("%lld\n", ans);
	return 0;
}