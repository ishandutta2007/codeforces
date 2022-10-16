#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

template <class T> struct SegmentTree {
	SegmentTree<T> *left, *right;
	T mn, mx, gap;
	int size, depth;

	SegmentTree(int l, int r, int cur_depth = 0) {
		depth = cur_depth;
		size = r - l + 1;
		if (l == r) {
			mn = mx = -1;
			gap = INF;
		} else {
			int m = (l + r) >> 1;
			left = new SegmentTree<T>(l, m, depth + 1);
			right = new SegmentTree<T>(m + 1, r, depth + 1);
			pull();
		}
	}

	void pull() {
		if (left->mn == -1) {
			if (right->mn == -1) {
				mn = -1;
			} else {
				mn = right->mn + size / 2	;
			}
		} else {
			mn = left->mn;
		}
		if (right->mx == -1) {
			mx = left->mx;
		} else {
			mx = right->mx + size / 2;
		}
		gap = min(left->gap, right->gap);
		int l = left->mx;
		int r = right->mn;
		if (l != -1 && r != -1) {
			r += size / 2;
			gap = min(gap, r - l);
		}
	}

	void set(int idx, int l, int r) {
		if (idx < l || r < idx) {
			return;
		} else if (l == r) {
			mn = mx = 0;
		} else {
			int m = (l + r) >> 1;
			left->set(idx, l, m);
			right->set(idx, m + 1, r);
			pull();
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegmentTree<int> *seg = new SegmentTree<int>(0, (1 << k) - 1);
	for (int i = 0; i < n; ++i) {
		seg->set(a[i], 0, (1 << k) - 1);
	}
	auto gray_code = [&](int n) {
		return n ^ (n >> 1);
	};
	auto to_binary = [&](int x) {
		string s = "";
		for (int i = 0; i < k; ++i) {
			if (x & (1 << i)) {
				s += '1';
			} else {
				s += '0';
			}
		}
		reverse(s.begin(), s.end());
		return s;
	};
	auto to_int = [&](string s) {
		int x = 0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < k; ++i) {
			if (s[i] == '1') {
				x += (1 << i);
			}	
		}
		return x;
	};
	auto get_value = [&](int x) {
		auto res = to_binary(gray_code(x));
		reverse(res.begin(), res.end());
		return to_int(res);
	};
	vector<int> ans(1 << k);
	vector<int> ord(1 << k);
	for (int i = 0; i < (1 << k); ++i) {
		ord[i] = get_value(i);
	}
	ans[ord[0]] = seg->gap;
	for (int i = 1; i < (1 << k); ++i) {
		int d = k - 1 - (31 - __builtin_clz(ord[i - 1] ^ ord[i]));
		vector<SegmentTree<int>*> nodes;
		function<void(SegmentTree<int>*)> dfs = [&](SegmentTree<int> *cur) {
			if (cur->depth == d) {
				swap(cur->left, cur->right);
			} else {
				dfs(cur->left);
				dfs(cur->right);
			}
			cur->pull();
		};
		dfs(seg);
		ans[ord[i]] = seg->gap;
	}
	for (int i = 0; i < (1 << k); ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}