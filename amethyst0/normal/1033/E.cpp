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
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = 610;
vector <int> ed[maxn];

int go(vector <int> a) {
	if ((int)a.size() <= 1) {
		return 0;
	}

	cout << "? " << a.size() << endl;
	for (int i = 0; i < (int)a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;

	int ans;

	cin >> ans;

	return ans;
}

bool used[maxn];
int n;
int col[maxn];

void dfs(int v, int c) {
	used[v] = true;
	col[v] = c;

	while (true) {
		vector <int> a;

		for (int i = 1; i <= n; i++) {
			if (!used[i]) {
				a.push_back(i);
			}
		}

		a.push_back(v);

		int cur = go(a);
		a.pop_back();
		cur -= go(a);

		if (cur == 0) {
			break;
		}

		while (a.size() != 1) {
			vector <int> b;

			while (a.size() > b.size()) {
				b.push_back(a.back());
				a.pop_back();
			}

			b.push_back(v);

			int now = go(b);
			b.pop_back();
			now -= go(b);

			if (now == 0) {
				continue;
			}

			a = b;
		}
		
		ed[v].push_back(a[0]);
		ed[a[0]].push_back(v);
		dfs(a[0], c ^ 1);
	}
}

vector <int> w;

bool write(int v, int p, int u) {
	if (v == u) {
		w.push_back(v);
		return true;
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int to = ed[v][i];

		if (to != p && write(to, v, u)) {
			w.push_back(v);
			return true;
		}
	}

	return false;
}

void check(int c) {
	vector <int> a;

	for (int i = 1; i <= n; i++) {
		if (col[i] == c) {
			a.push_back(i);
		}
	}

	int cur = go(a);

	if (cur == 0) {
		return;
	}

	while (true) {
		int v = a.back();
		a.pop_back();
		int ncur = go(a);

		if (ncur == cur) {
			cur = ncur;
			continue;
		}

		vector <int> b;
		b.push_back(v);

		for (int i = 0; i < (int)a.size(); i++) {
			b.push_back(a[i]);
			int u = a[i];

			if (go(b) != 0) {
				if (!write(u, -1, v)) {
					throw 1;
				}

				cout << "N " << w.size() << endl;

				for (int j = 0; j < (int)w.size(); j++) {
					cout << w[j] << ' ';
				}

				cout << endl;
				exit(0);
			}
		}
	}
}

int main() {
	cin >> n;

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			throw 1;
		}
	}

	check(0);
	check(1);

	vector <int> ans;

	for (int i = 1; i <= n; i++) {
		if (col[i] == 0) {
			ans.push_back(i);
		}
	}

	cout << "Y " << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;

	//system("pause");
}