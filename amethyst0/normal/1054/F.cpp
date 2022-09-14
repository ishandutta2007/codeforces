#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 1010;

vector <int> ed[maxn];
int lnk[maxn];
bool used[maxn];
bool us[maxn];

bool dfs(int v) {
	if (us[v]) {
		return false;
	}

	us[v] = true;
	
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (lnk[u] == -1 || dfs(lnk[u])) {
			lnk[u] = v;
			return true;
		}
	}

	return false;
}

bool usd[maxn];

void dfs1(int v) {
	if (us[v]) {
		return;
	}

	us[v] = true;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		usd[u] = true;

		if (lnk[u] != -1) {
			dfs1(lnk[u]);
		}
	}
}

int main() {
	vector <pii> c;

	int n;

	cin >> n;

	c.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i].first, &c[i].second);
	}

	sort(c.begin(), c.end());

	vector <pair <int, pii > > h, v;

	vector <pair <int, pii> > resh, resv;

	for (int i = 0; i < n; ) {
		int r = i;

		while (r < n && c[r].first == c[i].first) {
			r++;
		}

		for (int j = i; j < r - 1; j++) {
			h.push_back(mp(c[i].first, mp(c[j].second, c[j + 1].second)));
		}

		if (r - 1 == i) {
			resh.push_back(mp(c[i].first, mp(c[i].second, c[i].second)));
		}

		i = r;
	}

	for (int i = 0; i < n; i++) {
		swap(c[i].first, c[i].second);
	}

	sort(c.begin(), c.end());

	for (int i = 0; i < n; ) {
		int r = i;

		while (r < n && c[r].first == c[i].first) {
			r++;
		}

		for (int j = i; j < r - 1; j++) {
			v.push_back(mp(c[i].first, mp(c[j].second, c[j + 1].second)));
		}

		if (r - 1 == i) {
			resv.push_back(mp(c[i].first, mp(c[i].second, c[i].second)));
		}

		i = r;
	}

	for (int i = 0; i < n; i++) {
		swap(c[i].first, c[i].second);
	}

	for (int i = 0; i < (int)h.size(); i++) {
		for (int j = 0; j < (int)v.size(); j++) {
			if (v[j].second.first < h[i].first && h[i].first < v[j].second.second && h[i].second.first < v[j].first && v[j].first < h[i].second.second) {
				ed[i].push_back(j);
			}
		}
	}

	memset(lnk, -1, sizeof lnk);

	for (int i = 0; i < (int)h.size(); i++) {
		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];
			if (lnk[u] == -1) {
				lnk[u] = i;
				used[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < (int)h.size(); i++) {
		if (!used[i]) {
			memset(us, 0, sizeof us);
			if (dfs(i)) {
				used[i] = true;
			}
		}
	}

	memset(us, 0, sizeof us);

	for (int i = 0; i < (int)h.size(); i++) {
		if (!used[i]) {
			dfs1(i);
		}
	}

	/*cout << h.size() << ' ' << v.size() << endl;
	cout << resh.size() << ' ' << resv.size() << endl;
	cout << ed[0][0] << endl;
	system("pause");*/

	for (int i = 0; i < (int)h.size(); ) {
		int r = i;

		while (r < (int)h.size() && h[r].first == h[i].first) {
			r++;
		}

		int st = i;

		while (st != r) {
			int buf = st;

			while (st < r && us[st]) {
				st++;
			}

			if (st != i) {
				resh.push_back(mp(h[i].first, mp(h[buf].second.first, h[st - 1].second.second)));
			}
			else {
				resh.push_back(mp(h[i].first, mp(h[buf].second.first, h[buf].second.first)));
			}

			if (st == r - 1) {
				resh.push_back(mp(h[i].first, mp(h[st].second.second, h[st].second.second)));
			}

			if (st != r) {
				st++;
			}
		}

		i = r;
	}

	for (int i = 0; i < (int)v.size(); ) {
		int r = i;

		while (r < (int)v.size() && v[r].first == v[i].first) {
			r++;
		}

		int st = i;

		while (st != r) {
			int buf = st;

			while (st < r && !usd[st]) {
				st++;
			}

			if (st != i) {
				resv.push_back(mp(v[i].first, mp(v[buf].second.first, v[st - 1].second.second)));
			}
			else {
				resv.push_back(mp(v[i].first, mp(v[buf].second.first, v[buf].second.first)));
			}

			if (st == r - 1) {
				resv.push_back(mp(v[i].first, mp(v[st].second.second, v[st].second.second)));
			}
			
			if (st != r) {
				st++;
			}
		}

		i = r;
	}

	cout << resv.size() << endl;

	for (int i = 0; i < (int)resv.size(); i++) {
		printf("%d %d %d %d\n", resv[i].second.first, resv[i].first, resv[i].second.second, resv[i].first);
	}

	cout << resh.size() << endl;

	for (int i = 0; i < (int)resh.size(); i++) {
		printf("%d %d %d %d\n", resh[i].first, resh[i].second.first, resh[i].first, resh[i].second.second);
	}

	//system("pause");
}