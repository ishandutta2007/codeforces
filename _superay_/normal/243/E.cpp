#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE + 1], *is = ibuf, *it = ibuf;
	inline char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		return *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = read_char();
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = read_char();
		}
		x *= f;
	}
	inline void read_str(char *s) {
		char c = read_char();
		while (c <= ' ') {
			c = read_char();
		}
		while (c > ' ') {
			*s++ = c;
			c = read_char();
		}
		*s = 0;
	}
}
using io::read_char;
using io::read_int;
using io::read_str;
//Fast IO end
const int N = 505;
inline void NO() {
	puts("NO");
	exit(0);
}
int n, m, ppc[N], It[N][N], Ct[N][N], fa[N], cnt, vis[N], ca[N], cb[N], ansl[N], ansr[N], used[N];
bitset<N> a[N], b[N], cc[N], fb[N], ps[N], ansb[N];
unordered_map<bitset<N>, vector<int> > mp;
vector<int> G[N], ch[N], buck[N], tmp[N];
char str[N];
int Find(int x) {
	return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
inline void Set(int u, int ty, int v) {
	ca[u] = ty;
	cb[u] = v;
	for (int j = 0; j < m; j++) if (!b[j][u] && b[j][v]) {
		cc[u] |= b[j];
	}
}
int mn;
void fs(int u, int lf) {
	ansl[u] = lf;
	ansr[u] = lf + ppc[u] - 1;
	mn = min(mn, lf);
	for (int v : G[u]) {
		fs(v, ca[v] ? lf + It[u][v] - ppc[v] : lf + ppc[u] - It[u][v]);
	}
}
void go(int u) {
	int mx = 0;
	if (u != n) {
		mn = 0x3f3f3f3f;
		fs(u, 0);
		for (int i : buck[u]) {
			ansl[i] -= mn, ansr[i] -= mn;
			mx = max(mx, ansr[i]);
		}
		if (mx >= m) NO();
	} else {
		mx = m - 1;
	}
	for (int v : ch[u]) {
		go(v);
	}
	for (int i = 0; i <= mx; i++) used[i] = 0, ps[i].reset();
	for (int i : buck[u]) {
		ps[ansl[i]].flip(i);
		ps[ansr[i] + 1].flip(i);
	}
	for (int i = 1; i <= mx; i++) ps[i] ^= ps[i - 1];
	for (int v : ch[u]) {
		int fnd = -1;
		for (int i = 0; i <= mx; i++) if (!used[i] && fb[v] == ps[i]) {
			fnd = i;
			break;
		}
		if (fnd == -1) NO();
		int tmx = 0;
		for (int i : buck[v]) {
			ansl[i] += fnd;
			ansr[i] += fnd;
			tmx = max(tmx, ansr[i]);
		}
		if (tmx > mx) NO();
		for (int i = fnd; i <= tmx; i++) used[i] = 1;
	}
	for (int v : ch[u]) {
		buck[u].insert(buck[u].end(), buck[v].begin(), buck[v].end());
	}
}
void dfs(int u, int lst) {
	cnt++;
	vis[u] = 1;
	if (cnt == 1) {
	} else if (cnt == 2) {
		Set(lst, 0, u);
		Set(u, 1, lst);
	} else {
		if (cc[lst][u]) Set(u, ca[lst] ^ 1, lst);
		else Set(u, ca[lst], lst);
	}
	for (int v = 0; v < n; v++) if (It[u][v] && !vis[v]) {
		dfs(v, u);
		G[u].push_back(v);
	}
}
int main() {
	read_int(n);
    m = n;
	for (int i = 0; i < n; i++) {
		read_str(str);
		for (int j = 0; j < m; j++) if (str[j] == '1') a[i].set(j);
		int fnd = -1;
		for (int j = 0; j < i; j++) if (a[j] == a[i]) {
			fnd = j;
			break;
		}
		if (fnd != -1) {
			a[i].reset();
			i--, n--;
            tmp[i].push_back(fnd);
		}
	}
	for (int i = 0; i < n; i++) {
		ppc[i] = a[i].count();
		fa[i] = i;
		for (int j = 0; j < m; j++) if (a[i][j]) b[j].set(i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int tmp = (a[i] & a[j]).count();
			if (tmp > 0 && tmp < ppc[i] && tmp < ppc[j]) {
				It[i][j] = It[j][i] = tmp;
				fa[Find(i)] = Find(j);
			}
			if (tmp == ppc[i]) {
				Ct[j][i] = 1;
			}
			if (tmp == ppc[j]) {
				Ct[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) Find(i), buck[fa[i]].push_back(i);
	for (int i = 0; i < n; i++) if (fa[i] == i) {
		cnt = 0;
		dfs(i, 0);
		int fr = -1;
		for (int j = 0; j < n; j++) if (fa[j] != i && Ct[j][i]) {
			if (fr == -1 || ppc[fr] > ppc[j]) fr = j;
		}
		if (fr == -1) ch[n].push_back(i);
		else {
			fr = fa[fr];
			ch[fr].push_back(i);
			for (int j = 0; j < n; j++) if (fa[j] == fr && Ct[j][i]) {
				fb[i].set(j);
			}
		}
	}
	go(n);
	for (int j = 0; j < m; j++) mp[b[j]].push_back(j);
	for (int i = 0; i < n; i++) {
		for (int j = ansl[i]; j <= ansr[i]; j++) ansb[j].set(i);
	}
	for (int j = 0; j < m; j++) {
		auto it = mp.find(ansb[j]);
		if (it == mp.end()) NO();
		if (it -> second.empty()) NO();
		it -> second.pop_back();
	}
    puts("YES");
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = ansb[j][i];
            printf("%d", t);
        }
        printf("\n");
        for (int ti : tmp[i]) {
            for (int j = 0; j < m; j++) {
                int t = ansb[j][ti];
                printf("%d", t);
            }
            printf("\n");
        }
    }
	return 0;
}