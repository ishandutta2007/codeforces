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

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;

int deg[maxn];

vector <int> ed[maxn];
int cnt[maxn];
bool used[maxn];
int last[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 1; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}

	set <pair <int, int> > s;

	for (int i = 1; i <= n; i++) {
		s.insert(mp(deg[i], i));
	}

	memset(last, -1, sizeof last);

	for (int it = 0; it < k; it++) {
		if ((int)s.size() < 4) {
			cout << "No" << endl;
			return 0;
		}

		vector <int> g;

		while (!s.empty() && s.begin()->first == 1) {
			int v = s.begin()->second;
			used[v] = true;
			s.erase(s.begin());

			if (cnt[v] < 3 && it != 0) {
				cout << "No" << endl;
				return 0;
			}

			for (int i = 0; i < (int)ed[v].size(); i++) {
				int u = ed[v][i];

				if (!used[u]) {
					if (last[u] != -1 && last[u] != it) {
						cout << "No" << endl;
						return 0;
					}

					last[u] = it;
					cnt[u]++;
					g.push_back(u);
				}
			}
		}

		for (int i = 0; i < (int)g.size(); i++) {
			int v = g[i];

			s.erase(mp(deg[v], v));
			deg[v]--;
			s.insert(mp(deg[v], v));
		}
	}

	if ((int)s.size() != 1) {
		cout << "No" << endl;
		return 0;
	}

	int v = s.begin()->second;

	if (cnt[v] < 3) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	//system("pause");
}