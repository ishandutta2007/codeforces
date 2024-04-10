//#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;
set <int> ed[maxn];

set <int> s;

void dfs(int v) {
	queue <int> q;

	q.push(v);

	while (!q.empty()) {
		set <int> nx;
		v = q.front();
		q.pop();

		for (int u : s) {
			if (!ed[v].count(u)) {
				q.push(u);
			}
			else {
				nx.insert(u);
			}
		}

		s = nx;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].insert(y);
		ed[y].insert(x);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}

	while (!s.empty()) {
		int v = *s.begin();
		dfs(v);
		ans++;
	}

	cout << ans - 1 << endl;

	//system("pause");
	return 0;
}