#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 42, logn = 20;
int nxt[maxn][logn];
int mx[maxn];
int MX[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
	MX[v] = max(MX[v], c);
	if(r - l == 1) {
		return;
	} else {
		int m = (l + r) / 2;
		if(p < m) {
			upd(p, c, 2 * v, l, m);
		} else {
			upd(p, c, 2 * v + 1, m, r);
		}
	}
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
	if(a <= l && r <= b) {
		return MX[v];
	} else if(r <= a || b <= l) {
		return 0;
	} else {
		int m = (l + r) / 2;
		return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int p[n], a[m], ip[n];
	for(int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		ip[p[i]] = i;
	}
	map<int, int> last;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		a[i]--;
		int next = p[(ip[a[i]] + n - 1) % n];
		nxt[i][0] = last[next];
		for(int j = 1; j < logn; j++) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		}
		last[a[i]] = i;
		mx[i] = i;
		for(int j = 0; j < logn; j++) {
			if(((n - 1) >> j) & 1) {
				mx[i] = nxt[mx[i]][j];
			}
		}
		upd(i, mx[i]);
	}
	
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << (get(l, r + 1) >= l);
	}
	return 0;
}