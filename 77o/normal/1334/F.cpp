// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 5;
ll t[N * 4];

void update(int v, int tl, int tr, int l, int r, ll add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add);
    }
}

ll get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for (int& i : a) {
		cin >> i;
	}
	for (int& i : p) {
		cin >> i;
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int& i : b) {
		cin >> i;
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (p[i] < 0) {
			update(1, 0, m, pos + 1, j, p[i]);
		}
		if (pos <= j && pos < b.size() && a[i] == b[pos]) {
			ll prev = get(1, 0, m, pos);
			ll cur = get(1, 0, m, pos + 1);
			if (prev < cur || pos == j) {
				update(1, 0, m, pos + 1, pos + 1, prev - cur);
			}
			j = max(j, pos + 1);
		}
		update(1, 0, m, 0, min(j, pos), p[i]);
		// for (int k = 0; k <= j; k++) {
		// 	cout << get(1, 0, m, k) << ' ';
		// }
		// cout << endl;
	}

	if (j == m) {
		cout << "YES" << endl;
		cout << get(1, 0, m, m) << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}