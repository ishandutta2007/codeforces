#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

map <pair <string, int>, int> m;
const int maxn = 1010;

vector <pair <string, int> > g[maxn];
vector <int> ed[maxn];

int dst[maxn];

map <string, pii> in;

string nm[maxn];
int ver[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		int v;

		cin >> s >> v;
		nm[i] = s;
		ver[i] = v;

		m[mp(s, v)] = i;

		int cnt;

		cin >> cnt;

		g[i].resize(cnt);

		for (int j = 0; j < cnt; j++) {
			cin >> g[i][j].first >> g[i][j].second;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)g[i].size(); j++) {
			ed[i].push_back(m[g[i][j]]);
		}
	}

	queue <int> q;

	q.push(0);
	in[nm[0]] = mp(0, ver[0]);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (in[nm[u]] != mp(dst[u], ver[u])) {
			continue;
		}

		for (int i = 0; i < (int)ed[u].size(); i++) {
			int to = ed[u][i];

			if (dst[to] == 0) {
				dst[to] = dst[u] + 1;
				q.push(to);

				if (!in.count(nm[to])) {
					in[nm[to]] = mp(dst[to], ver[to]);
				}
				else {
					pii f = in[nm[to]];

					if (dst[to] == f.first && ver[to] > f.second) {
						in[nm[to]] = mp(dst[to], ver[to]);
					}
				}
			}
		}
	}

	in.erase(nm[0]);

	cout << in.size() << endl;

	for (auto it = in.begin(); it != in.end(); it++) {
		cout << it->first << ' ' << it->second.second << endl;
	}

	//system("pause");
}