#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int lazy;
	node() {}
};
node pool[800005];
void change(int l, int r, int L, int R, int n, int ind) {
	pool[ind].lazy = max(pool[ind].lazy, n);
}
void change1(int l, int r, int i, int n, int ind) {
	if (l == i&& l == r-1)
		pool[ind].lazy = 0;
	else {
		pool[ind * 2].lazy = max(pool[ind * 2].lazy, pool[ind].lazy);
		pool[ind * 2 + 1].lazy = max(pool[ind * 2 + 1].lazy, pool[ind].lazy);
		pool[ind].lazy = 0;
		int m;
		m = (l + r) / 2;
		if (i < m)
			change1(l, m, i, n, ind * 2);
		if (i >= m)
			change1(m, r, i, n, ind * 2 + 1);
	}
}
int get(int l, int r, int i, int ind, vector<int>& a) {
	if (l == r - 1) {
		a[l] = max(a[l], pool[ind].lazy);
		pool[ind].lazy = 0;
		return a[l];
	}
	else {
		pool[ind * 2].lazy = max(pool[ind * 2].lazy, pool[ind].lazy);
		pool[ind * 2 + 1].lazy = max(pool[ind * 2 + 1].lazy, pool[ind].lazy);
		pool[ind].lazy = 0;
		int m;
		m = (l + r) / 2;
		if (i < m)
			return get(l, m, i, ind * 2, a);
		else
			return get(m, r, i, ind * 2 + 1, a);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	int q;
	cin >> q;
	for (i = 0; i < q; i++) {
		int k;
		cin >> k;
		if (k == 1) {
			int p, x;
			cin >> p >> x;
			change1(0, n, p - 1, x, 1);
			a[p - 1] = x;
		}
		else {
			int x;
			cin >> x;
			change(0, n, 0, n, x, 1);
		}
	}
	for (i = 0; i < n; i++) {
		cout << get(0, n, i, 1, a) << " ";
	}
	return 0;
}