#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1000000007;
int N;
template <typename T>
class segtree {
   private:
	int n, sz, h;
	vector<T> node, lazy;
	void eval(int k) {
		if (lazy[k]) {
			node[k] += lazy[k];
			if (k < n) {
				lazy[k * 2] += lazy[k] / 2, lazy[k * 2 + 1] += lazy[k] / 2;
			}
			lazy[k] = 0;
		}
	}

   public:
	segtree(const vector<T> &v) : sz((int)v.size()), h(0) {
		n = 1;
		while (n < sz) n *= 2, h++;
		node.resize(2 * n, 0), lazy.resize(2 * n, 0);
		for (int i = 0; i < sz; i++) node[i + n] = v[i];
		for (int i = n - 1; i >= 1; i--) node[i] = node[2 * i] + node[2 * i + 1];
	}
	void range(int a, int b, T x) {
		a += n, b += n - 1;
		for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
		int ta = a, tb = b++, length = 1;
		while (a < b) {
			if (a & 1) lazy[a++] += length * x;
			if (b & 1) lazy[--b] += length * x;
			a >>= 1, b >>= 1, length <<= 1;
		}
		while (ta >>= 1, tb >>= 1, ta) {
			if (!lazy[ta]) {
				eval(2 * ta), eval(2 * ta + 1), node[ta] = node[2 * ta] + node[2 * ta + 1];
			}
			if (!lazy[tb]) {
				eval(2 * tb), eval(2 * tb + 1), node[tb] = node[2 * tb] + node[2 * tb + 1];
			}
		}
	}
	T query(int a, int b) {
		a += n, b += n - 1;
		for (int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
		b++;
		T res1 = 0, res2 = 0;
		while (a < b) {
			if (a & 1) eval(a), res1 += node[a++];
			if (b & 1) eval(--b), res2 += node[b];
			a >>= 1, b >>= 1;
		}
		return res1 + res2;
	}
	void print() {
		for (int i = 0; i < sz; i++) cout << query(i, i + 1) << " ";
		cout << endl;
	}
};
bool check(vector<pair<int, int> > &A, vector<pair<int, int> > &B) {
	vector<pair<int, int> > X(2 * N);
	for (int i = 0; i < N; i++) {
		X[2 * i].first = A[i].first;
		X[2 * i].second = i;
		X[2 * i + 1].first = A[i].second;
		X[2 * i + 1].second = i + N;
	}
	sort(X.begin(), X.end());
	vector<int> tmp(4 * N + 3, 0);
	segtree<int> sg(tmp);
	for (int i = 0; i < X.size(); i++) {
		if (X[i].second < N) {
			int idx = X[i].second;
			//cerr << "A " << idx << endl;
			if (sg.query(B[idx].first, B[idx].second + 1) != 0) {
				return true;
			}
		} else {
			int idx = X[i].second - N;
			//cerr << "B " << idx << endl;

			sg.range(B[idx].first, B[idx].second + 1, 1);
		}
	}
	return false;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<pair<int, int> > A(N);
	vector<pair<int, int> > B(N);
	set<int> st;
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second;
		st.insert(A[i].first);
		st.insert(A[i].second);
		st.insert(B[i].first);
		st.insert(B[i].second);
	}
	map<int, int> mp;
	int t = 0;
	for (auto s : st) {
		mp[s] = t;
		t++;
	}
	for (int i = 0; i < N; i++) {
		A[i].first = mp[A[i].first];
		A[i].second = mp[A[i].second];
		B[i].first = mp[B[i].first];
		B[i].second = mp[B[i].second];
	}
	bool res = false;
	res |= check(A, B);
	res |= check(B, A);
	if (res) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}