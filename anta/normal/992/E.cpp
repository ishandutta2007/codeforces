#include "bits/stdc++.h"
using namespace std;

struct FenwickTree {
	typedef long long T;
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
	int n; int q;
	while (~scanf("%d%d", &n, &q)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		int bucketSize = (int)(sqrt(n * 1.) * 2.5);
		int numBuckets = (n - 1) / bucketSize + 1;
		struct Bucket {
			vector<pair<long long, int>> sorted;
			long long add;
		};
		FenwickTree ft;
		ft.init(n);
		for (int i = 0; i < n; ++ i)
			ft.add(i, as[i]);
		vector<Bucket> buckets(numBuckets);
		auto rebuild = [&](int bi) {
			auto &b = buckets[bi];
			int L = bi * bucketSize, R = min(n, L + bucketSize);
			long long leftSum = ft.sum(L);
			b.sorted.resize(R - L);
			for (int i = L; i < R; ++ i) {
				int a = as[i];
				b.sorted[i - L] = make_pair(a - leftSum, i);
				leftSum += a;
			}
			sort(b.sorted.begin(), b.sorted.end());
			b.add = 0;
		};
		for (int bi = 0; bi < numBuckets; ++ bi)
			rebuild(bi);
		vector<pair<long long, int>> tmp1, tmp2;
		for (int qi = 0; qi < q; ++ qi) {
			int p; int x;
			scanf("%d%d", &p, &x), -- p;
			int d = x - as[p];
			as[p] = x;
			ft.add(p, d);
			{
				int bi = p / bucketSize;
				{
					auto &b = buckets[bi];
					auto &v = b.sorted;
					tmp1.clear();
					tmp2.clear();
					pair<long long, int> tmp3{};
					for (auto t : v) {
						if (p == t.second) {
							tmp3 = make_pair(t.first + d, t.second);
						} else if (p < t.second) {
							tmp1.emplace_back(t.first - d, t.second);
						} else {
							tmp2.emplace_back(t.first, t.second);
						}
					}
					tmp2.insert(lower_bound(tmp2.begin(), tmp2.end(), tmp3), tmp3);
					merge(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end(), v.begin());
				}
				for (++ bi; bi < numBuckets; ++ bi)
					buckets[bi].add -= d;
			}
			{
				int ans = -1;
				for (int bi = 0; bi < numBuckets; ++ bi) {
					auto &b = buckets[bi];
					const auto &v = b.sorted;
					int ix = (int)(lower_bound(v.begin(), v.end(), make_pair(-b.add, -1)) - v.begin());
					if (ix != v.size() && v[ix].first == -b.add) {
						ans = v[ix].second;
						break;
					}
				}
				printf("%d\n", ans == -1 ? -1 : ans + 1);
			}
		}
	}
}