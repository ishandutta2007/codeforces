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

int MOD = 1000000007;
template<typename T> class segtree {
private:
	int n, sz;
	vector<pair<T, int> > node;
public:
	segtree(vector<T>& v) {
		sz = (int)v.size();
		n = 1;
		while (n < sz) {
			n *= 2;
		}
		node.resize(2 * n, make_pair(numeric_limits<T>::max(), -1));
		for (int i = 0; i < sz; i++) {
			node[i + n] = make_pair(v[i], i);
		}
		for (int i = n - 1; i >= 1; i--) {
			node[i] = min(node[2 * i], node[2 * i + 1]);
		}
	}
	void update(int k, T a)
	{
		node[k += n] = make_pair(a, k);
		while (k >>= 1) {
			node[k] = min(node[2 * k], node[2 * k + 1]);
		}
	}
	inline void cmn(pair<T, int> &a, const pair<T, int> &b) {
		a = min(a, b);
	}
	pair<T, int> query(int a, int b, int k = 0, int l = 0, int r = -1)
	{
		pair<T, int> res1 = make_pair(numeric_limits<T>::max(), -1);
		pair<T, int> res2 = make_pair(numeric_limits<T>::max(), -1);
		a += n, b += n;
		while (a != b) {
			if (a % 2) cmn(res1, node[a++]);
			if (b % 2) cmn(res2, node[--b]);
			a >>= 1, b >>= 1;
		}
		return min(res1, res2);
	}
	void print()
	{
		for (int i = 0; i < sz; i++) {
			pair<T, int> p;
			p = query(i, i + 1);
			cout << "st[" << i << "]: " << p.fi << " " << p.se << endl;
		}
	}
};
#define int long long
inline int dst(const vector<int> &A, const vector<int> &B) {
	int ret = 0;
	for (int i = 0; i < A.size(); i++) {
		ret += abs(A[i] - B[i]);
	}
	return ret;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<vector<int> > A(N, vector<int>(K));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cin >> A[i][j];
		}
	}
	vector<vector<int> > v(1 << K, vector<int>(N, 0));
	int t;

	vector<int> empty(N, 0);
	vector<segtree<int> > sg(1 << K, segtree<int>(empty));

	for (int i = 0; i < (1 << K); i++) {
		for (int j = 0; j < N; j++) {
			t = 0;
			for (int k = 0; k < K; k++) {
				if (i & (1 << k)) {
					t += A[j][k];
				}
				else {
					t -= A[j][k];
				}
			}
			sg[i].update(j, t);
		}
	}
	int Q;
	cin >> Q;
	vector<int> res;
	vector<int> vec;
	for (int q = 0; q < Q; q++) {
		cin >> t;
		if (t == 1) {
			int j;
			cin >> j; j--;
			for (int k = 0; k < K; k++) {
				cin >> A[j][k];
			}
			for (int i = 0; i < (1 << K); i++) {
				t = 0;
				for (int k = 0; k < K; k++) {
					if (i & (1 << k)) {
						t += A[j][k];
					}
					else {
						t -= A[j][k];
					}
				}
				sg[i].update(j, t);
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			l--;
			vec.clear();
			for (int i = 0; i < (1 << K); i++) {
				vec.push_back(sg[i].query(l, r).second);
			}
			std::sort(vec.begin(), vec.end());
			vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
			int mx = 0;
			for (int i = 0; i < vec.size(); i++) {
				for (int j = i + 1; j < vec.size(); j++) {
					mx = max(mx, dst(A[vec[i]], A[vec[j]]));
				}
			}
			res.push_back(mx);
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}