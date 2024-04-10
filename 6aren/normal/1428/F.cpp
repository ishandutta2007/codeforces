#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define x first
#define y second

const int N = 500005;


struct Node {
	int mn, sum;

	Node() {
		mn = 0;
		sum = 0;
	}

};

Node combine(Node a, Node b) {
	Node res;
	res.mn = min(a.mn, b.mn);
	res.sum = a.sum + b.sum;
	return res;
}

ii lazy[4 * N];
Node it[4 * N];
string s;
int n;

void down(int k, int l, int r) {
	int mid = (l + r) / 2;
	int val = lazy[k].x;
	int add = lazy[k].y;
	if (val == 0 && add == 0)
		return;
	lazy[k] = {0, 0};
	if (val != 0) {
		lazy[2 * k].x = val;
		lazy[2 * k + 1].x = val;
		it[2 * k].mn = val;
		it[2 * k].sum = val * (mid - l + 1);
		it[2 * k + 1].mn = val;
		it[2 * k + 1].sum = val * (r - mid);
	}
	if (add != 0) {
		lazy[2 * k].y += add;
		lazy[2 * k + 1].y += add;
		it[2 * k].mn += add;
		it[2 * k].sum += add * (mid - l + 1);
		it[2 * k + 1].mn += add;
		it[2 * k + 1].sum += add * (r - mid);
	}
}

void update(int k, int l, int r, int u, int v, int val, bool type) {
	if (l > v || r < u)
		return;
	if (l >= u && r <= v) {
		if (type == 0) {
			it[k].sum = (r - l + 1) * val;
			it[k].mn = val;
			lazy[k].x = val;
			lazy[k].y = 0;
		} else {
			it[k].sum += val * (r - l + 1);
			it[k].mn += val;
			lazy[k].y += val;
		}
		return;
	}

	down(k, l, r);

	int mid = (l + r) / 2;

	update(2 * k, l, mid, u, v, val, type);
	update(2 * k + 1, mid + 1, r, u, v, val, type);

	it[k] = combine(it[2 * k], it[2 * k + 1]);
}

int find_less(int k, int l, int r, int val) {

	if (l == r) {
		return l;
	}

	down(k, l, r);

	int mid = (l + r) / 2;
	if (it[2 * k].mn < val)
		return find_less(2 * k, l, mid, val);
	else return find_less(2 * k + 1, mid + 1, r, val);

}


signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> s;

	s = " " + s;

	int cur = 0;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		if (s[i] == '0')
			cur = 0;
		if (s[i] == '1')
			cur++;

		if (cur != 0) {
			int id = find_less(1, 1, n, cur);
			
			if (i - cur >= id)
				update(1, 1, n, id, i - cur, cur, 0);
			update(1, 1, n, i - cur + 1, i, 1, 1);
		}

		ans += it[1].sum;

		// cout << it[1].sum << endl;
	}

	cout << ans << '\n';

	return 0;
}