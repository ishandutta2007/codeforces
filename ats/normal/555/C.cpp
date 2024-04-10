#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
template<typename T> class segtree {
private:
	int n, sz;
	vector<T> node, min_val, second_val, lazy;
	vector<int> count;
	vector<bool> lazyFlag;
	void update(int id) {
		node[id] = node[2 * id + 1] + node[2 * id + 2];
		if (min_val[2 * id + 1] < min_val[2 * id + 2]) {
			min_val[id] = min_val[2 * id + 1];
			second_val[id] = min(second_val[2 * id + 1], min_val[2 * id + 2]);
			count[id] = count[2 * id + 1];
		}
		else if (min_val[2 * id + 1] > min_val[2 * id + 2]) {
			min_val[id] = min_val[2 * id + 2];
			second_val[id] = min(min_val[2 * id + 1], second_val[2 * id + 2]);
			count[id] = count[2 * id + 2];
		}
		else {
			min_val[id] = min_val[2 * id + 1];
			second_val[id] = min(second_val[2 * id + 1], second_val[2 * id + 2]);
			count[id] = count[2 * id + 1] + count[2 * id + 2];
		}
	}
public:
	segtree(vector<T>& v) : sz((int)v.size()) {
		n = 1;
		while (n < sz) {
			n *= 2;
		}
		node.resize(2 * n, 0);
		lazy.resize(2 * n, 0);
		lazyFlag.resize(2 * n, false);
		min_val.resize(2 * n, numeric_limits<T>::max());
		second_val.resize(2 * n, numeric_limits<T>::max());
		count.resize(2 * n, 1);
		for (int i = 0; i < sz; i++) {
			node[i + n - 1] = min_val[i + n - 1] = v[i];
		}
		for (int i = n - 2; i >= 0; i--) {
			update(i);
		}
	}
	void eval(int k, int l, int r) {
		if (lazyFlag[k]) {
			if (lazy[k] > min_val[k]) {
				node[k] += (lazy[k] - min_val[k]) * count[k];
				min_val[k] = lazy[k];
				if (r - l > 1) {
					lazy[k * 2 + 1] = lazy[k * 2 + 2] = lazy[k];
					lazyFlag[k * 2 + 1] = lazyFlag[k * 2 + 2] = true;
				}
			}
			lazyFlag[k] = false;
		}
	}
	void range(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		eval(k, l, r);
		if (b <= l || r <= a || min_val[k] >= x) {
			return;
		}
		if (a <= l && r <= b && second_val[k] > x) {
			lazy[k] = x;
			lazyFlag[k] = true;
			eval(k, l, r);
		}
		else {
			range(a, b, x, 2 * k + 1, l, (l + r) / 2);
			range(a, b, x, 2 * k + 2, (l + r) / 2, r);
			update(k);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0) r = n;
		eval(k, l, r);
		if (b <= l || r <= a) {
			return 0;
		}
		if (a <= l && r <= b) {
			return node[k];
		}
		T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
	void print()
	{
		for (int i = 0; i < sz; i++) {
			cout << query(i, i + 1) << " ";
		}
		cout << endl;
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> V(Q + 3, 0);
	segtree<int> X(V);
	segtree<int> Y(V);
	vector<int> res;
	vector<pair<pair<int, int>, char > >A(Q);
	for (int i = 0; i < Q; i++) {
		cin >> A[i].first.first >> A[i].first.second >> A[i].second;
	}
	int x, y;
	char d;
	set<int> s;
	s.insert(0);
	map<int, int> mpX;
	for (int i = 0; i < Q; i++) {
		s.insert(A[i].first.first);
	}
	int z = 0;
	vector<int> revX;
	for (auto i : s) {
		mpX[i] = z;
		revX.push_back(i);
		z++;
	}
	for (int i = 0; i < Q; i++) {
		A[i].first.first = mpX[A[i].first.first];
	}
	s.clear();
	s.insert(0);
	map<int, int> mpY;
	for (int i = 0; i < Q; i++) {
		s.insert(A[i].first.second);
	}
	z = 0;
	vector<int> revY;

	for (auto i : s) {
		mpY[i] = z;
		revY.push_back(i);
		z++;
	}
	for (int i = 0; i < Q; i++) {
		A[i].first.second = mpY[A[i].first.second];
	}

	for (int i = 0; i < Q; i++) {
		x = A[i].first.first;
		y = A[i].first.second;
		d = A[i].second;
		if (d == 'U') {
			int z = X.query(x, x + 1);
			res.push_back(revY[y] - revY[z]);
			Y.range(z, y + 1, x);
			X.range(x, x + 1, y);
		}
		else {
			int z = Y.query(y, y + 1);
			res.push_back(revX[x] - revX[z]);
			X.range(z, x + 1, y);
			Y.range(y, y + 1, x);
		}
	}
	for (int i = 0; i < Q; i++) {
		cout << res[i] << endl;
	}
}