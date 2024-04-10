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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

vector <pair <ld, ld> > now;

const int maxn = 50000;

vector <int> ed[maxn];

pair <ld, ld> c[maxn];
int ps = 0;

void add(int x, int y) {
	ed[x].push_back(y);
	ed[y].push_back(x);
}

vector <int> ans;

set <pii> s;

void dfs(int v) {
	while (!ed[v].empty()) {
		int u = ed[v].back();
		ed[v].pop_back();
		if (s.count(mp(v, u))) {
			continue;
		}

		s.insert(mp(u, v));
		dfs(u);
	}

	ans.push_back(v);
}

vector <int> res;
vector <ld> g[2];

ld dist(pair <ld, ld> a, pair <ld, ld> b) {
	return hypot(a.first - b.first, a.second - b.second);
}

int main() {

	now.push_back(mp((ld)3.830127018922193, (ld)3.366025403784439));
	now.push_back(mp((ld)-3.601321235851749, (ld)10.057331467373021));
	now.push_back(mp((ld)0.466045194906253, (ld)19.192786043799030));
	now.push_back(mp((ld)10.411264148588986, (ld)18.147501411122495));
	now.push_back(mp((ld)12.490381056766580, (ld)8.366025403784439));
	c[0] = now[0];
	c[1] = now[1];
	c[2] = now[2];
	c[3] = now[3];
	c[4] = now[4];
	ps = 5;

	g[0].push_back(now[2].second - now[0].second);
	g[0].push_back(now[2].second - now[1].second);
	g[0].push_back(0);
	g[0].push_back(now[2].second - now[3].second);
	g[0].push_back(now[2].second - now[4].second);

	vector <int> num;

	for (int i = 0; i < 5; i++) {
		num.push_back(i);
	}

	res = num;

	add(0, 2);
	add(2, 4);
	add(4, 1);
	add(1, 3);
	add(3, 0);

	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		vector <pair <ld, ld> > bf;
		vector <int> numb;

		int h = (i - 1) & 1;

		for (int j = 0; j < 5; j++) {
			bf.push_back(mp(now[j].first, now[2].second + g[h][j]));

			if (j != 2) {
				c[ps] = bf.back();
				numb.push_back(ps++);
			}
			else {
				numb.push_back(num[2]);
			}
		}

		reverse(bf.begin(), bf.begin() + 3);
		reverse(bf.begin() + 3, bf.end());
		reverse(numb.begin(), numb.begin() + 3);
		reverse(numb.begin() + 3, numb.end());

		for (int j = 0; j < 5; j++) {
			add(numb[j], numb[(j + 2) % 5]);
		}

		for (int j = 0; j < 5; j++) {
			res.push_back(numb[j]);
		}

		now = bf;
		num = numb;

		if (i == 1) {
			g[1].push_back(now[2].second - now[0].second);
			g[1].push_back(now[2].second - now[1].second);
			g[1].push_back(0);
			g[1].push_back(now[2].second - now[3].second);
			g[1].push_back(now[2].second - now[4].second);
		}
	}

	cout << ps << endl;

	for (int i = 0; i < ps; i++) {
		printf("%.30lf %.30lf\n", (double)c[i].first, (double)c[i].second);
	}

	for (int i = 0; i < (int)res.size(); i += 5) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", res[i + j] + 1);
		}

		printf("\n");
	}

	dfs(0);

	if (ans.size() != 5 * n + 1) {
		throw 1;
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] + 1 << ' ';
	}

	return 0;
}