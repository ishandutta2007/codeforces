#include "bits/stdc++.h"
using namespace std;

struct FenwickTree {
	typedef int T;
	vector<T> v;
	void init(int n) { v.assign(n, T()); }
	void add(int i, T x) {
		for (; i < (int)v.size(); i |= i + 1) v[i] += x;
	}
	T sum(int i) const {	//[0, i)
		T r = T();
		for (-- i; i >= 0; i = (i & (i + 1)) - 1) r += v[i];
		return r;
	}
	T sum(int left, int right) const {	//[left, right)
		return sum(right) - sum(left);
	}
};

int main() {
	int n; int l; int wmax;
	while (~scanf("%d%d%d", &n, &l, &wmax)) {
		vector<pair<int, int>> clouds(n);
		for (int i = 0; i < n; ++ i) {
			int x; int v;
			scanf("%d%d", &x, &v);
			clouds[i] = { x, v };
		}
		sort(clouds.begin(), clouds.end());
		vector<long long> values;
		for (auto c : clouds) if (c.second == 1) {
			int x = c.first;
			values.push_back((long long)(wmax - 1) * x);
			values.push_back((long long)(wmax + 1) * x);
		}
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		FenwickTree ftL, ftR;
		ftL.init((int)values.size());
		ftR.init((int)values.size());
		auto getLB = [&values](long long x) {
			return (int)(lower_bound(values.begin(), values.end(), x) - values.begin());
		};
		vector<int> xs;
		long long ans = 0;
		for (int j = 0, mi = 0; j < n; ++ j) {
			int xj, v;
			tie(xj, v) = clouds[j];
			if (v == 1) {
				xs.push_back(xj);
				ftR.add(getLB((long long)(wmax + 1) * xj), 1);
				continue;
			}
			for (; mi != xs.size() && xs[mi] + xj + l <= 0; ++ mi) {
				ftL.add(getLB((long long)(wmax - 1) * xs[mi]), 1);
				ftR.add(getLB((long long)(wmax + 1) * xs[mi]), -1);
			}
			ans += ftL.sum(getLB((long long)(wmax + 1) * (xj + l)));
			ans += ftR.sum(getLB((long long)(wmax - 1) * (xj + l)));
		}
		printf("%lld\n", ans);
	}
}