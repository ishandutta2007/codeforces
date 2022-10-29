#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>


using namespace std;

const int MaxN = 500000;

vector<int> a(MaxN);
vector<int> t(4 * MaxN);

void build(int i, int l, int r);
void update(int i, int l, int r, int pos, int val);
int ans(int i, int l, int r, int lo, int ro, int x);

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	build(1, 0, n - 1);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp == 2) {
			int pos, val;
			cin >> pos >> val;
			--pos;
			update(1, 0, n - 1, pos, val);
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			int f = ans(1, 0, n - 1, l - 1, r - 1, x);
			if (f >= 2)
				puts("NO");
			else
				puts("YES");
		}
	}
	return 0;
}


void build(int i, int l, int r) {
	if (l == r)
		t[i] = a[l];
	else {
		int m = (l + r) / 2;
		build(i << 1, l, m);
		build((i << 1) + 1, m + 1, r);
		t[i] = gcd(t[i << 1], t[(i << 1) + 1]);
	}
}

void update(int i, int l, int r, int pos, int val) {
	if (l == r)
		t[i] = val;
	else {
		int m = (l + r) / 2;
		if (pos <= m)
			update(i << 1, l, m, pos, val);
		else
			update((i << 1) + 1, m + 1, r, pos, val);
		t[i] = gcd(t[i << 1], t[(i << 1) + 1]);
	}
}

int ans(int i, int l, int r, int lo, int ro, int x) {
	if (lo > ro)
		return 0;
	if (l == r) {
		if (t[i] % x == 0)
			return 0;
		return 1;
	}
	if (l == lo && r == ro) {
		int sum = 0;
		int m = (l + r) / 2;
		bool t1 = t[i << 1] % x == 0;
		bool t2 = t[(i << 1) + 1] % x == 0;
		if (!t1 & !t2)
			return 2;
		if (!t1)
			sum += ans(i << 1, l, m, lo, m, x);
		if (sum >= 2)
			return 2;
		if (!t2)
			sum += ans((i << 1) + 1, m + 1, r, m + 1, ro, x);
		if (sum >= 2)
			return 2;
		return sum;
	}
	bool t1 = t[i << 1] % x == 0;
	bool t2 = t[(i << 1) + 1] % x == 0;
	int m = (l + r) / 2;
	int sum = 0;
	if (!t1)
		sum += ans(i << 1, l, m, lo, min(ro, m), x);
	if (sum >= 2)
		return 2;
	if (!t2)
		sum += ans((i << 1) + 1, m + 1, r, max(lo, m + 1), ro, x);
	return sum;
}