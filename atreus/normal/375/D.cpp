#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
const int Maxn = 1e5 + 1;
const int mod = 1e9 + 7;
const int block = 333;
int n, m, a[maxn], c[maxn], st[maxn], fi[maxn], zaman = 1, cnt[maxn], num[maxn], ans[maxn];
pair <pii, pii> q[maxn];
vector <int> v[maxn];

void Add (int L, int R) {
	while (L < R) {
		int x = a[L];
		num[x] ++;
		cnt[num[x]] ++;
		L ++;
	}
}

void Delete (int L, int R) {
	while (L < R) {
		int x = a[L];
		cnt[num[x]] --;
		num[x] --;
		L ++;
	}
}

void dfs (int u, int par = -1) {
	st[u] = zaman ++;
	a[st[u]] = c[u];
	for (auto w : v[u])
		if (w != par)
			dfs (w, u);
	fi[u] = zaman;
}

bool cmp (pair <pii, pii> Fi, pair <pii, pii> Se) {
	int x = Fi.F.F / block, y = Se.F.F / block;
	if (x != y)
		return x < y;
	return Fi.F.S < Se.F.S;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	
	dfs (1);

	for (int i = 1; i <= m; i++) {
		int u, k;
		cin >> u >> k;
		q[i].F = {st[u], fi[u]};
		q[i].S = {k, i};
	}

	sort (q + 1, q + m + 1, cmp);

	int L = 0, R = 1;
	for (int i = 1; i <= m; i++) {
		int l = q[i].F.F, r = q[i].F.S;
		if (L < l) {
			Delete (L, l);
			L = l;
		}
		if (R > r) {
			Delete (r, R);
			R = r;
		}

		if (L > l) {
			Add (l, L);
			L = l;
		}
		if (R < r) {
			Add (R, r);
			R = r;
		}

		ans[q[i].S.S] = cnt[q[i].S.F];
	}
	
	for (int i = 1; i <= m; i++)
		cout << ans[i] << '\n';
}