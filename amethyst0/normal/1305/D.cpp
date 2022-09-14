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

const int maxn = 1010;
vector <int> ed[maxn];

int ask(int x, int y) {
	cout << "? " << x << ' ' << y << '\n';
	int w;
	cin >> w;
	return w;
}

void del(int x, int y) {
	for (int i = 0; i < (int)ed[x].size(); i++) {
		if (ed[x][i] == y) {
			swap(ed[x][i], ed[x].back());
			ed[x].pop_back();
			break;
		}
	}
}

void solve(int v) {
	if (ed[v].empty()) {
		cout << "! " << v << endl;
		exit(0);
	}

	if ((int)ed[v].size() == 1) {
		v = ed[v][0];
	}

	if ((int)ed[v].size() > 1) {
		int x = ed[v][0];
		int y = ed[v][1];

		int w = ask(x, y);

		if (w == v) {
			del(v, x);
			del(v, y);
			solve(v);
		}
		else if (w == x) {
			del(x, v);
			solve(x);
		}
		else {
			del(y, v);
			solve(y);
		}
	}
	else {
		int x = ed[v][0];

		int w = ask(v, x);
		cout << "! " << w << '\n';
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		cin >> x >> y;

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	solve(1);
}