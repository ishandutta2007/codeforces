#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>
#include <set>
#include <string>
#include <bitset>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long
#define ld long double

const int maxn = 122;

int ed[maxn][maxn];
vector <int> g[maxn];
int rev[maxn];
map <vector <int>, int> num;
int cnt = 0;

int f(vector <int> a, vector <int> b) {
	vector <int> ans(a.size());

	for (int i = 0; i < (int)a.size(); i++) {
		ans[b[i]] = a[i];
	}

	return num[ans];
}

int rever(vector <int> a) {
	vector <int> ans(a.size());

	for (int i = 0; i < (int)a.size(); i++) {
		ans[a[i]] = i;
	}

	return num[ans];
}

const int maxm = (int)2e5 + 10;

int v[maxm];

int numb = 0;

bitset <maxn> b[maxn];
bitset <maxn> used;

void dfs(int v) {
	while (true) {
		bitset <maxn> cur = b[v] & used;
		if (cur.any()) {
			int x = cur._Find_first();

			used[x] = 0;
			dfs(x);
			numb++;
		}
		else {
			break;
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	vector <int> x;

	for (int i = 0; i < k; i++) {
		x.push_back(i);
	}

	while (true) {
		num[x] = cnt;
		g[cnt++] = x;

		if (!next_permutation(x.begin(), x.end())) {
			break;
		}
	}

	for (int i = 0; i < cnt; i++) {
		rev[i] = rever(g[i]);
	}

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			ed[i][j] = f(g[i], g[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		vector <int> x(k);

		for (int j = 0; j < k; j++) {
			scanf("%d", &x[j]);
			x[j]--;
		}

		v[i] = num[x];
		v[i] = rev[v[i]];
	}

	map <int, int> w;
	set <pii> s;

	ll ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		int x = v[i];

		if (w.count(x)) {
			s.erase(mp(w[x], x));
		}

		w[x] = i;
		s.insert(mp(i, x));

		int last = i;

		for (int j = 0; j < cnt; j++) {
			used[j] = 1;
			b[j].reset();
		}

		numb = 1;
		used[0] = 0;

		for (auto it : s) {
			int y = it.second;
			int p = it.first;

			if (used[rev[y]] == 0) {
				continue;
			}

			ans += (ll)(p - last) * numb;

			for (int j = 0; j < cnt; j++) {
				b[j][ed[j][y]] = 1;
			}

			for (int i = 0; i < cnt; i++) {
				if (used[i] == 0) {
					dfs(i);
				}
			}

			last = p;
		}

		ans += (ll)(n - last) * numb;
	}

	cout << ans << endl;
}