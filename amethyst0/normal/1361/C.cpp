#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)5e5 + 10;

int a[maxn], b[maxn];

const int maxlog = 21;

int cnt[1 << maxlog];
bool used[1 << maxlog];
vector <int> e[1 << maxlog];

int n;

void bfs(int v) {
	used[v] = true;
	queue <int> q;

	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : e[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
			}
		}
	}
}

bool check(int x) {
	memset(cnt, 0, sizeof cnt);
	memset(used, 0, sizeof used);
	int c = (1 << x);

	for (int i = 0; i < c; i++) {
		e[i].clear();
	}

	for (int i = 0; i < n; i++) {
		cnt[a[i] % c]++;
		cnt[b[i] % c]++;
		e[a[i] % c].push_back(b[i] % c);
		e[b[i] % c].push_back(a[i] % c);
	}

	for (int i = 0; i < c; i++) {
		if (cnt[i] & 1) {
			return false;
		}
	}

	for (int i = 0; i < c; i++) {
		if (cnt[i]) {
			bfs(i);
			break;
		}
	}

	for (int i = 0; i < c; i++) {
		if (cnt[i] && !used[i]) {
			return false;
		}
	}

	return true;
}

vector <pii> ed[1 << maxlog];

bool us[maxn];

vector <int> ans;

void euler(int v, int id) {
	while (!ed[v].empty()) {
		if (us[ed[v].back().second]) {
			ed[v].pop_back();
			continue;
		}

		int u = ed[v].back().first;
		int nx = ed[v].back().second;
		ed[v].pop_back();
		us[nx] = true;
		euler(u, nx);
	}

	if (id != -1) {
		ans.push_back(id);
	}
}

int vert;

void build(int x) {
	int c = (1 << x);

	for (int i = 0; i < n; i++) {
		ed[a[i] % c].push_back(mp(b[i] % c, i));
		ed[b[i] % c].push_back(mp(a[i] % c, i));
	}

	for (int i = 0; i < c; i++) {
		if (!ed[i].empty()) {
			vert = i;
			euler(i, -1);
			break;
		}
	}

	assert((int)ans.size() == n);
}

mt19937 rr;

int main() {
	cin >> n;

	int ls = rr() % (1 << 10);
	int fr = ls;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);

		/*a[i] = ls;
		b[i] = rr() % (1 << 10);
		ls = b[i];

		if (rr() & 1) {
			swap(a[i], b[i]);
		}*/
	}

	/*if (b[n - 1] == ls) {
		b[n - 1] = fr;
	}
	else {
		a[n - 1] = fr;
	}*/

	int l = 0;
	int r = 20;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (check(m)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	cout << l << '\n';

	build(l);

	int c = 1 << l;

	for (int i = 0; i < n; i++) {
		a[i] %= c;
		b[i] %= c;
	}

	reverse(all(ans));

	int lst = vert;

	for (int x : ans) {
		if (a[x] == lst) {
			printf("%d %d ", 2 * x + 1, 2 * x + 2);
			lst = b[x];
		}
		else {
			assert(lst == b[x]);
			printf("%d %d ", 2 * x + 2, 2 * x + 1);
			lst = a[x];
		}
	}

	printf("\n");
}