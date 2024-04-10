//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld long double

using namespace std;

const int maxn = (int)5e5 + 10;
vector <pii> ed[maxn];
int w[maxn];

int getw(int x) {
	int ans = 0;

	while (x != 0) {
		ans++;
		x /= 10;
	}

	return ans;
}

int dst[maxn];

bool cmp(int a, int b) {
	return dst[a] < dst[b];
}

const int p = (int)1e9 + 7, q = (int)1e9 + 9;

pii operator +(pii a, pii b) {
	a.first += b.first;
	if (a.first >= p) {
		a.first -= p;
	}

	a.second += b.second;
	if (a.second >= q) {
		a.second -= q;
	}

	return a;
}

pii operator *(pii a, pii b) {
	a.first = (ll)a.first * b.first % p;
	a.second = (ll)a.second * b.second % q;

	return a;
}

pii st[maxn];

struct vt {
	pii hsh;
	int l, r;

	vt() : hsh(mp(0, 0)), l(-1), r(-1) {

	}
};

const int maxm = (int)3e7;

vt mas[maxm];
int posit = 0;

int my_new() {
	if (posit == maxm) {
		exit(0);
	}
	return posit++;
}

int cpy(int t) {
	int nt = my_new();
	mas[nt].hsh = mas[t].hsh;
	mas[nt].l = mas[t].l;
	mas[nt].r = mas[t].r;
	return nt;
}

pii recalc(pii a, pii b, int d) {
	return a * st[d] + b;
}

void build(int t) {
	if (mas[t].l == -1) {
		mas[t].l = my_new();
		mas[t].r = my_new();
	}
}

int change(int t, int l, int r, int pos, int x) {
	t = cpy(t);
	if (l == r) {
		mas[t].hsh = mp(x, x);
	}
	else {
		build(t);
		int m = (l + r) >> 1;

		if (pos <= m) {
			mas[t].l = change(mas[t].l, l, m, pos, x);
		}
		else {
			mas[t].r = change(mas[t].r, m + 1, r, pos, x);
		}

		mas[t].hsh = recalc(mas[mas[t].l].hsh, mas[mas[t].r].hsh, r - m);
	}

	return t;
}

int rr;

void rebuild(int &t, int d, int x) {
	vector <int> z;

	while (x != 0) {
		z.push_back(x % 10);
		x /= 10;
	}

	while (!z.empty()) {
		t = change(t, 0, rr, d, z.back());
		d++;
		z.pop_back();
	}
}

bool go(int t1, int t2, int l, int r) {
	if (mas[t1].hsh == mas[t2].hsh) {
		return false;
	}

	if (l == r) {
		return mas[t1].hsh.first < mas[t2].hsh.first;
	}

	int m = (l + r) >> 1;

	build(t1);
	build(t2);

	if (mas[mas[t1].l].hsh != mas[mas[t2].l].hsh) {
		return go(mas[t1].l, mas[t2].l, l, m);
	}
	else {
		return go(mas[t1].r, mas[t2].r, m + 1, r);
	}
}

int pr[maxn];
int cs[maxn];
int tr[maxn];

int ans[maxn];

int main() {
	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = mp(1234567, 1234567) * st[i - 1];
	}

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		w[i] = getw(i);
	}

	for (int i = 1; i <= m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(mp(y, i));
		ed[y].push_back(mp(x, i));
	}

	set <pii> s;
	dst[1] = 0;

	for (int i = 2; i <= n; i++) {
		dst[i] = (int)1e9;
	}

	s.insert(mp(dst[1], 1));

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i].first;
			int c = w[ed[v][i].second];

			if (dst[u] > dst[v] + c) {
				s.erase(mp(dst[u], u));
				dst[u] = dst[v] + c;
				s.insert(mp(dst[u], u));
			}
		}
	}

	vector <int> ord;

	for (int i = 2; i <= n; i++) {
		ord.push_back(i);
	}

	sort(ord.begin(), ord.end(), cmp);

	rr = 5 * n;

	tr[1] = my_new();

	for (int i = 0; i < (int)ord.size(); i++) {
		int v = ord[i];
		pr[v] = -1;

		for (int j = 0; j < (int)ed[v].size(); j++) {
			int u = ed[v][j].first;
			int c = w[ed[v][j].second];

			if (dst[u] + c == dst[v]) {
				if (pr[v] == -1) {
					pr[v] = u;
					cs[v] = ed[v][j].second;
					tr[v] = tr[u];
					rebuild(tr[v], dst[u], ed[v][j].second);
				}
				else {
					int nt = tr[u];
					rebuild(nt, dst[u], ed[v][j].second);
					if (go(nt, tr[v], 0, rr)) {
						pr[v] = u;
						cs[v] = ed[v][j].second;
						tr[v] = nt;
					}
				}
			}
		}

		if (dst[v] > rr || pr[v] == -1) {
			throw 1;
		}
	}

	ans[1] = 0;

	for (int i = 0; i < (int)ord.size(); i++) {
		int v = ord[i];
		int u = pr[v];
		int num = cs[v];

		ans[v] = ans[u];

		vector <int> z;

		while (num != 0) {
			z.push_back(num % 10);
			num /= 10;
		}

		while (!z.empty()) {
			ans[v] = ((ll)ans[v] * 10 + z.back()) % p;
			z.pop_back();
		}
	}

	for (int i = 2; i <= n; i++) {
		printf("%d\n", ans[i]);
	}

	//system("pause");
}