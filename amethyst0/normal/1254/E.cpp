//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)5e5 + 10;
vector <int> ed[maxn];
int pr[maxn];

int h[maxn];

void dfs(int v, int p = -1, int hh = 0) {
	h[v] = hh;
	pr[v] = p;

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		dfs(u, v, hh + 1);
	}
}

int fir[maxn], lst[maxn];
map <int, int> nxt[maxn], pre[maxn];

const int mod = (int)1e9 + 7;

vector <int> way(int a, int b) {
	vector <int> x, y;

	while (h[a] > h[b]) {
		x.push_back(a);
		a = pr[a];
	}

	while (h[b] > h[a]) {
		y.push_back(b);
		b = pr[b];
	}

	while (a != b) {
		x.push_back(a);
		y.push_back(b);
		a = pr[a];
		b = pr[b];
	}

	x.push_back(a);

	reverse(y.begin(), y.end());

	for (int f : y) {
		x.push_back(f);
	}

	return x;
}

bool add(int a, int x, int y) {
	if (nxt[a].count(x) || lst[a] == x) {
		return false;
	}

	if (pre[a].count(y) || fir[a] == y) {
		return false;
	}

	nxt[a][x] = y;
	pre[a][y] = x;
	return true;
}

int f[maxn];

int main() {
	f[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = (ll)f[i - 1] * i % mod;
	}

	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	memset(fir, -1, sizeof fir);
	memset(lst, -1, sizeof lst);

	dfs(1);

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);

		if (x == 0) {
			continue;
		}

		if (x == i) {
			cout << 0 << endl;
			return 0;
		}

		swap(x, i);

		vector <int> w = way(i, x);

		if (pre[i].count(w[1])) {
			cout << 0 << endl;
			return 0;
		}

		if (nxt[x].count(w[(int)w.size() - 2])) {
			cout << 0 << endl;
			return 0;
		}

		fir[i] = w[1];
		lst[x] = w[(int)w.size() - 2];

		for (int j = 1; j < (int)w.size() - 1; j++) {
			if (!add(w[j], w[j - 1], w[j + 1])) {
				cout << 0 << endl;
				return 0;
			}
		}

		swap(x, i);
	}

	int ans = 1;

	for (int i = 1; i <= n; i++) {
		int tot = (int)ed[i].size();

		for (int u : ed[i]) {
			if (pre[i].count(u)) {
				continue;
			}

			int g = u;
			tot--;

			while (nxt[i].count(g)) {
				tot--;
				g = nxt[i][g];
			}
		}

		if (tot != 0) {
			cout << 0 << endl;
			return 0;
		}

		int cnt = (int)ed[i].size() - (int)nxt[i].size();

		if (cnt == 1) {
			continue;
		}

		if (fir[i] != -1 && lst[i] != -1) {
			int g = fir[i];

			while (nxt[i].count(g)) {
				g = nxt[i][g];
			}



			if (g == lst[i]) {
				cout << 0 << endl;
				return 0;
			}
		}

		if (fir[i] != -1) {
			cnt--;
		}

		if (lst[i] != -1) {
			cnt--;
		}

		ans = (ll)ans * f[cnt] % mod;
	}

	cout << ans << endl;

	//system("pause");
}