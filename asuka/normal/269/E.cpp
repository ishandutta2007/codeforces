#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
const int N = 200015;
int n, m, typ[114];
void jtak() {puts("No solution"); exit(0);}
int gc() {
	char ch = getchar();
	while (ch < 'A' || ch > 'Z') ch = getchar();
	if (ch == 'T') return 0;
	if (ch == 'R') return 1;
	if (ch == 'B') return 2;
	assert(ch == 'L');
	return 3;
}
VI get(VI s, int sft) {
	int l = SZ(s);
	VI res(l);
	rep(i, 0, l - 1) res[i] = s[(i + sft) % l];
	return res;
}
pair<int, VI> find(VI s) {
	int l = SZ(s);
	int i = 0, j = 1, k = 0;
	while (k < l && i < l && j < l) {
		if (s[(i + k) % l] == s[(j + k) % l]) k++;
		else {
			s[(i + k) % l] > s[(j + k) % l] ? i += k + 1 : j += k + 1;
			if (i == j) i++;
			k = 0;
		}
	}
	int pos = min(i, j);
	return mp(pos, get(s, pos));
}
struct cycle {
	VI s, p;
	void fix() {
		VI s1 = s, s2 = s;
		reverse(all(s2));
		auto [p1, q1] = find(s1);
		auto [p2, q2] = find(s2);
		if (q1 < q2) {
			s = q1;
			p = get(p, p1);
		} else {
			s = q2;
			reverse(all(p));
			p = get(p, p2);
		}
	}
	bool operator < (const cycle &rhs) const {return SZ(s) == SZ(rhs.s) ? s < rhs.s : SZ(s) < SZ(rhs.s);}
	bool operator == (const cycle &rhs) const {return s == rhs.s;}
};
int to[N << 2];
bool vis[N << 2];
cycle cur;
void dfs(int u) {
	vis[u] = 1;
	cur.s.pb(u & 3); cur.p.pb(u >> 2);
	for (int v : {u ^ 2, to[u]})
		if (!vis[v]) {
			dfs(v);
		}
}
vector<cycle> build(vector<tuple<int, int, int, int>> edge) {
	vector<cycle> res;
	for (auto [a, x, b, y] : edge) {
		int u = (x << 2) | a, v = (y << 2) | b;
		to[u] = v; to[v] = u;
	}
	memset(vis, 0, sizeof vis);
	rep(i, 4, (n + m) * 4 + 3) if (to[i] && !vis[i]) {
		cur.s.clear(); cur.p.clear();
		dfs(i);
		res.pb(cur);
	}
	for (auto& x : res) x.fix();
	sort(all(res));
	return res;
}
int row[N], col[N];
bool match(cycle a, cycle b) {
	if (a.s != b.s) return 0;
	rep(i, 0, SZ(a.p) - 1) (a.s[i] & 1 ? row[a.p[i]] : col[a.p[i]]) = b.p[i];
	return 1;
}
int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	vector<tuple<int, int, int, int>> ori, ans;
	rep(i, 1, n + m) {
		int a, b, x, y;
		a = gc(); b = gc();
		scanf("%d%d", &x, &y);
		if (a > b) swap(a, b), swap(x, y);
		typ[a << 2 | b]++;
		ori.emplace_back(a, x, b, y);
	}
	if ((typ[0 << 2 | 2] && typ[1 << 2 | 3]) ||
	        (typ[0 << 2 | 3] ^ typ[1 << 2 | 2]) ||
	        (typ[0 << 2 | 1] ^ typ[2 << 2 | 3])) jtak();
	int jt = typ[0 << 2 | 3], tj = typ[0 << 2 | 1];
	rep(i, 1, jt) ans.emplace_back(0, i, 3, i), ans.emplace_back(1, n - i + 1, 2, m - i + 1);
	rep(i, 1, tj) ans.emplace_back(0, m - i + 1, 1, i), ans.emplace_back(2, i, 3, n - i + 1);
	if (typ[0 << 2 | 2]) rep(i, 1, typ[0 << 2 | 2]) ans.emplace_back(0, jt + i, 2, tj + i);
	if (typ[1 << 2 | 3]) rep(i, 1, typ[1 << 2 | 3]) ans.emplace_back(1, tj + i, 3, jt + i);
	vector<cycle> J = build(ori), T = build(ans);
	if (SZ(J) != SZ(T)) jtak();
	rep(i, 0, SZ(J) - 1) if (!match(T[i], J[i])) jtak();
	rep(i, 1, n) printf("%d%c", row[i], " \n"[i == n]);
	rep(i, 1, m) printf("%d%c", col[i], " \n"[i == m]);
	return 0;
}