#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)2e5 + 10;
int v[maxn];
bool used[maxn];

int go(int p) {
	used[p] = true;
	int ans = 1;
	if (!used[v[p]]) {
		ans += go(v[p]);
	}
	return ans;
}

int tot[maxn];

mt19937 rr;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i]--;
		//v[i] = i;
	}

	//shuffle(v, v + n, rr);

	vector <pii> g;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			g.push_back({ i, go(i) });
		}
	}

	sort(all(g), [&](pii a, pii b) {
		return a.second > b.second;
	});

	vector <pii> ans;

	if ((int)g.size() > 1) {
		for (int i = 0; i < (int)g.size(); i++) {
			if (g[i].second == 1) {
				break;
			}

			int a = g[i].first;
			int b = -1;
			
			if (i + 1 == (int)g.size()) {
				b = g[0].first;
			}
			else {
				b = g[i + 1].first;
				i++;
			}

			int x = v[a];

			swap(v[a], v[b]);
			ans.push_back({ a, b });
			tot[v[a]] ^= 1;
			tot[v[b]] ^= 1;

			while (v[v[a]] != x) {
				ans.push_back({ a, v[a] });
				tot[v[a]] ^= 1;
				tot[v[v[a]]] ^= 1;
				swap(v[a], v[v[a]]);
			}

			a = v[a];
			while (a != v[a]) {
				ans.push_back({ a, v[a] });
				tot[v[a]] ^= 1;
				tot[v[v[a]]] ^= 1;
				swap(v[a], v[v[a]]);
			}
		}
	}
	else {
		int a = g[0].first;
		ans.push_back({ a, v[a] });
		int x = v[a];
		tot[v[a]] ^= 1;
		tot[v[v[a]]] ^= 1;
		swap(v[a], v[v[a]]);
		ans.push_back({ x, v[a] });
		tot[v[x]] ^= 1;
		tot[v[v[a]]] ^= 1;
		swap(v[x], v[v[a]]);
		int s = 0;

		/*for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}

		for (int i = 0; i < n; i++) {
			cout << tot[i] << ' ';
		}

		exit(0);*/

		for (int i = 0; i < n; i++) {
			if (tot[v[i]] && !tot[v[v[i]]]) {
				s = i;
				break;
			}
		}

		while (!tot[v[v[s]]]) {
			ans.push_back({ s, v[s] });
			tot[v[s]] ^= 1;
			tot[v[v[s]]] ^= 1;
			swap(v[s], v[v[s]]);
		}

		s = v[s];

		while (s != v[s]) {
			ans.push_back({ s, v[s] });
			tot[v[s]] ^= 1;
			tot[v[v[s]]] ^= 1;
			swap(v[s], v[v[s]]);
		}
	}

	for (int i = 0; i < n; i++) {
		assert(tot[i] == 0);
	}

	for (int i = 0; i < n; i++) {
		assert(v[i] == i);
	}

	cout << (int)ans.size() << '\n';
	for (auto[x, y] : ans) {
		printf("%d %d\n", x + 1, y + 1);
	}
}