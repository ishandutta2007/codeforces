/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;

struct point {
	int ed[26];
	int p;
	int c;
	int lnk;
	bool fl;

	point() {
		memset(ed, -1, sizeof ed);
		p = -1;
		c = -1;
		lnk = -1;
		fl = false;
	}

	point(int p, int c): p(p), c(c) {
		lnk = -1;
		fl = false;
		memset(ed, -1, sizeof ed);
	}
};

point mas[maxn];
int posit = 0;

int my_new(int p, int c) {
	mas[posit] = point(p, c);
	return posit++;
}

char s[maxn];
int len;
int num[maxn];
int tin[maxn];
int tout[maxn];

int add(int it, int pos) {
	if (pos == len) {
		mas[it].fl = true;
		return it;
	}

	int c = s[pos] - 'a';

	if (mas[it].ed[c] == -1) {
		mas[it].ed[c] = my_new(it, c);
	}

	return add(mas[it].ed[c], pos + 1);
}

int tt = -1;

vector <int> edg[maxn];

void dfs(int v) {
	tt++;
	tin[v] = tt;

	for (int i = 0; i < (int)edg[v].size(); i++) {
		dfs(edg[v][i]);
	}

	tout[v] = tt;
}

int go(int it, int c);

int get_lnk(int it) {
	if (mas[it].lnk != -1) {
		return mas[it].lnk;
	}

	if (it == 0 || mas[it].p == 0) {
		mas[it].lnk = 0;
		return 0;
	}

	return mas[it].lnk = go(get_lnk(mas[it].p), mas[it].c);
}

int go(int it, int c) {
	if (mas[it].ed[c] != -1) {
		return mas[it].ed[c];
	}

	if (it == 0) {
		return 0;
	}

	return go(get_lnk(it), c);
}

int t[maxn];

void change(int pos, int x) {
	for (; pos < maxn; pos |= pos + 1) {
		t[pos] += x;
	}
}

int go(int pos) {
	int ans = 0;

	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		ans += t[pos];
	}

	return ans;
}

bool in[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	int it = my_new(-1, -1);

	for (int i = 0; i < k; i++) {
		in[i] = true;
		scanf("%s", s);
		len = strlen(s);

		num[i] = add(it, 0);
	}

	for (int i = 1; i < posit; i++) {
		edg[get_lnk(i)].push_back(i);
	}

	dfs(it);

	for (int i = 0; i < k; i++) {
		int v = num[i];

		change(tin[v], 1);
		change(tout[v] + 1, -1);
	}

	for (int i = 0; i < n; i++) {
		char c;

		scanf(" %c", &c);

		if (c == '+') {
			int x;

			scanf("%d", &x);
			x--;

			if (!in[x]) {
				int v = num[x];

				change(tin[v], 1);
				change(tout[v] + 1, -1);
				in[x] = true;
			}
		}
		else if (c == '-') {
			int x;

			scanf("%d", &x);
			x--;

			if (in[x]) {
				in[x] = false;

				int v = num[x];

				change(tin[v], -1);
				change(tout[v] + 1, 1);
			}
		}
		else {
			scanf("%s", s);
			len = strlen(s);

			int now = it;

			ll ans = 0;

			for (int j = 0; j < len; j++) {
				now = go(now, s[j] - 'a');

				ans += go(tin[now]);
			}

			printf("%lld\n", ans);
		}
	}
}