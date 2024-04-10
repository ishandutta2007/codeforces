#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair
#define x first
#define y second

const int N = 200005;

int it[4 * N], t[N], k[5], bit[5][N], n;

void build(int k, int l, int r) {
	if (l == r) {
		it[k] = t[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * k, l, mid);
	build(2 * k + 1, mid + 1, r);
	it[k] = min(it[2 * k], it[2 * k + 1]);
}

int getMin(int k, int l, int r, int u, int v) {
	if (l > v || r < u) return 1e9;
	if (l >= u && r <= v) return it[k];
	int mid = (l + r) / 2;
	int mn1 = getMin(2 * k, l, mid, u, v);
	int mn2 = getMin(2 * k + 1, mid + 1, r, u, v);
	return min(mn1, mn2);
}

void update(int o, int k, int val) {
	for (int i = k; i <= n; i += (i & (-i))) {
		bit[o][i] += val;
	}
}

int get(int o, int k) {
	int res = 0;
	for (int i = k; i > 0; i -= (i & (-i))) {
		res += bit[o][i];
	}
	return res;
}

int calc(int o, int l, int r) {
	return get(o, r) - get(o, l - 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k[1] >> k[2] >> k[3];
	n = k[1] + k[2] + k[3];
	for (int i = 1; i <= 3; i++) {	
		for (int j = 1; j <= k[i]; j++) {
			int u; 
			cin >> u;
			update(i, u, 1);
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		t[i] = calc(2, i, n) + calc(1, 1, n) + calc(3, 1, i - 1);
		//cout << t[i] << ' ';
		//cout << calc(2, i, n) << ' ' << calc(1, 1, n) << ' ' <<  calc(3, 1, i - 1) << '\n';
	}
	build(1, 1, n + 1);
	int res = 1e9;
	for (int i = 1; i <= n + 1; i++) {
		int temp =  i - 1 - get(1, i - 1);
		int u = i - 1 - get(2, i - 1);
		int mn = getMin(1, 1, n + 1, i, n + 1);
		temp = temp + mn - u;
		res = min(res, temp);
	}
	cout << res;
	return 0;
}