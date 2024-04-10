#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e5 + 10, maxm = 500;

ll v[maxn];
vector <int> ed[maxm];
int n;
int dst[maxm];
int par[maxm];

int go(int v) {
	for (int i = 0; i < n; i++) {
		dst[i] = -1;
	}

	dst[v] = 0;
	queue <int> q;

	q.push(v);

	while (!q.empty()) {
		int u = q.front();
		
		q.pop();

		for (int i = 0; i < (int)ed[u].size(); i++) {
			int to = ed[u][i];

			if (dst[to] == -1) {
				dst[to] = dst[u] + 1;
				par[to] = u;
				q.push(to);
			}
		}
	}

	int ans = n + 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)ed[i].size(); j++) {
			int to = ed[i][j];

			if (dst[to] == -1 || dst[i] == -1) {
				continue;
			}

			if (par[to] == i) {
				continue;
			}

			if (par[i] == to) {
				continue;
			}

			ans = min(ans, dst[i] + dst[to] + 1);
		}
	}

	return ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);

		if (v[i] == 0) {
			n--;
			i--;
		}
	}

	for (int b = 0; b < 60; b++) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if ((v[i] >> b) & 1) {
				cnt++;
			}
		}

		if (cnt > 2) {
			cout << 3 << endl;
			return 0;
		}
	}

	if (n >= maxm) {
		throw 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}

			if ((v[i] & v[j]) != 0) {
				ed[i].push_back(j);
			}
		}
	}

	int ans = n + 1;

	for (int i = 0; i < n; i++) {
		ans = min(ans, go(i));
	}

	if (ans == n + 1) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}

	//system("pause");
	return 0;
}