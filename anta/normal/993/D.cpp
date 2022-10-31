#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }

// min { n/d | d <= maxDen, n/d <= maxRato, pred(n,d) }
template<typename TInt, typename Pred>
pair<TInt, TInt> rationalBinarySearch(TInt maxRatio, TInt maxDen, Pred pred) {
	assert(maxRatio >= 0 && maxDen > 0);
	assert(pred(0, 1));
	auto check = [pred, maxRatio](TInt n, TInt d) -> bool { return (n - 1) / d < maxRatio && pred(n, d); };
	TInt Ln = 0, Ld = 1, Rn = 1, Rd = 0;
	while (Ld <= maxDen - Rd) {
		for (int d = 0; d < 2; ++ d) {
			auto checkX = [=](TInt x) { return check(Ln + x * Rn, Ld + x * Rd) == (d == 0); };
			TInt xU = Rd == 0 ? maxRatio : (maxDen - Ld) / Rd, x = 0; int k = 0;
			for (; k < sizeof(TInt) * 8 && xU >> k != 0 && checkX(TInt(1) << k); ++ k);
			for (-- k; k >= 0; -- k) if ((xU - x) >> k != 0 && checkX(x + (TInt(1) << k))) x += TInt(1) << k;
			Ln += x * Rn, Ld += x * Rd;
			swap(Ln, Rn); swap(Ld, Rd);
		}
	}
	return make_pair(Ln, Ld);
}

int main() {
	int n;
	mt19937 re;
	while (~scanf("%d", &n)) {
		vector<int> as(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &as[i]);
		vector<int> bs(n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &bs[i]);
		const int B = *max_element(bs.begin(), bs.end());
		auto values = as;
		sort(values.begin(), values.end());
		values.erase(unique(values.begin(), values.end()), values.end());
		vector<vector<int>> lists(values.size());
		for (int i = 0; i < n; ++ i) {
			int ai = (int)(lower_bound(values.begin(), values.end(), as[i]) - values.begin());
			lists[ai].push_back(bs[i]);
		}
		for (auto &v : lists)
			sort(v.rbegin(), v.rend());
		auto check = [n, &values, &lists](long long num, long long den) {
			const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
			vector<long long> cur, ndp(n + 1, INFL);
			ndp[0] = 0;
			for (int ai = (int)values.size() - 1; ai >= 0; -- ai) {
				int a = values[ai];
				cur.swap(ndp);
				ndp.assign(n + 1, INFL);
				for (int j = 0; j <= n; ++ j) {
					auto x = cur[j];
					if (x == INFL) continue;
					long long sum = 0;
					int l = (int)lists[ai].size();
					for (int k = 0; k <= l; ++ k) {
						if (l - k <= j)
							amin(ndp[j - (l - k) + k], x + sum);
						if (k != l)
							sum += (long long)a * den - lists[ai][k] * num;
					}
				}
			}
			return *min_element(ndp.begin(), ndp.end()) <= 0;
		};
		int maxRatio = *max_element(as.begin(), as.end());
		auto ans = rationalBinarySearch<long long>(maxRatio, B * n, [maxRatio, check](auto num, auto den) { return check(maxRatio * den - num, den); });
		ans.first = maxRatio * ans.second - ans.first;
		printf("%lld\n", (ans.first * 1000 + ans.second - 1) / ans.second);
	}

}