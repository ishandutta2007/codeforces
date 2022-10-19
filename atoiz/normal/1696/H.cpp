#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n);
	array<vector<int>, 2> b; b[0].clear(), b[1].clear();
	for (int i = 0; i < n; ++i) cin >> a[i], b[a[i] < 0].push_back(a[i]);
	sort(a.begin(), a.end(), [](int x, int y) { return make_pair(abs(x), x) > make_pair(abs(y), y); });
	for (int k = 0; k < 2; ++k) sort(b[k].begin(), b[k].end(), [](int x, int y) { return abs(x) > abs(y); });

	const int MOD = 1000000007;
	const auto add = [](int x, int y) { return ((x + y) % MOD + MOD) % MOD; };
	const auto mul = [](int x, int y) { return ((int) ((int64_t) x * y % MOD) + MOD) % MOD; };

	vector<int> pow2(n + 1);
	pow2[0] = 1;
	for (int i = 1; i <= n; ++i) pow2[i] = add(pow2[i - 1], pow2[i - 1]);

	auto upd_table = [&add, &mul](vector<int> &table, int n, int x) {
		for (int j = n; j >= 0; --j) table[j + 1] = add(table[j + 1], mul(table[j], x));
	};

	auto gen_table = [&upd_table](vector<int> vec) {
		vector<int> table(vec.size() + 1, 0); table[0] = 1;
		for (int i = 0; i < (int) vec.size(); ++i) upd_table(table, i, vec[i]);
		return table;
	};

	int ans = 0;

	{
		if (k % 2 == 1 && (int) b[1].size() >= k) {
			vector<int> vec(b[1].rbegin(), b[1].rend());
			vector<int> table(vec.size() + 1); table[0] = 1;
			for (int i = 0; i < (int) vec.size(); ++i) {
				int cur = vec[i];
				cur = mul(cur, table[k - 1]);
				cur = mul(cur, pow2[vec.size() - i - 1]);
				ans = add(ans, cur);
	
				upd_table(table, i, vec[i]);
			}
		}
	}

	{
		vector<int> lis_neg, lis_pos;
		for (int i = 0; i < n; ++i) {
			if (i + 1 >= k) {
				auto sum_neg = gen_table(lis_neg);
				auto sum_pos = gen_table(lis_pos);

				for (int chosen_neg = (a[i] >= 0); chosen_neg <= (int) lis_neg.size(); chosen_neg += 2) {
					int chosen_pos = k - 1 - chosen_neg;
					if (chosen_pos + (a[i] >= 0) < 1 || chosen_pos > (int) lis_pos.size()) continue;

					int cur = a[i];
					cur = mul(cur, sum_neg[chosen_neg]);
					cur = mul(cur, sum_pos[chosen_pos]);
					ans = add(ans, cur);
				}
			}

			if (a[i] < 0) lis_neg.push_back(a[i]);
			else lis_pos.push_back(a[i]);
		}
	}

	{
		vector<int> lis_neg, lis_pos;
		for (int i = 0; i < n; ++i) {
			if (i + 1 >= k) {
				auto sum_neg = gen_table(lis_neg);
				auto sum_pos = gen_table(lis_pos);

				for (int chosen_neg = (a[i] < 0); chosen_neg <= (int) lis_neg.size(); chosen_neg += 2) {
					int chosen_pos = k - 1 - chosen_neg;
					if (chosen_pos < 0 || chosen_pos > (int) lis_pos.size()) continue;

					int cur = a[i];
					cur = mul(cur, sum_neg[chosen_neg]);
					cur = mul(cur, sum_pos[chosen_pos]);
					cur = mul(cur, pow2[n - 1 - i]);
					ans = add(ans, cur);
				}
			}

			if (a[i] < 0) lis_neg.push_back(a[i]);
			else lis_pos.push_back(a[i]);
		}
	}

	for (int nt = 0; nt < 2; ++nt) {
		int st = !nt;
		vector<int> near_table(b[nt].size() + 1, 0); near_table[0] = 1;
		for (int near = -1; near < (int) b[nt].size(); ++near) {
			vector<int> skip_table(b[st].size() + 1, 0); skip_table[0] = 1;
			for (int skip = 0; skip <= (int) b[st].size(); ++skip) {
				int after_skip = b[nt].size();
				if (skip < (int) b[st].size()) for (; after_skip > 0 && make_pair(abs(b[nt][after_skip - 1]), b[nt][after_skip - 1]) < make_pair(abs(b[st][skip]), b[st][skip]); --after_skip);

				int base = 0;
				for (int choose_near = 0; choose_near <= k - 1 - (near >= 0); ++choose_near) {
					int choose_skip = k - 1 - (near >= 0) - choose_near;
					if (0 > choose_near || choose_near > (int) b[nt].size()) continue;
					if (0 > choose_skip || choose_skip > (int) b[st].size()) continue;
					if (nt && choose_near % 2 == (near >= 0)) continue;
					if (st && choose_skip % 2 == 1) continue;
					base = add(base, mul(near_table[choose_near], skip_table[choose_skip]));
				}
				if (near >= 0) base = mul(base, b[nt][near]);

				int after = skip + 1;
				for (int last = max(after_skip, near + 1); last < (int) b[nt].size(); ++last) {
					int64_t prod_to_beat = (near < 0) ? int64_t(2e18) : (int64_t) b[nt][near] * b[nt][last];
					if (skip < (int) b[st].size()) while (after < (int) b[st].size() && 
						(((int64_t) b[st][skip] * b[st][after] > prod_to_beat)
						|| (((int64_t) b[st][skip] * b[st][after] == prod_to_beat) && (make_pair(abs(b[nt][near]), b[nt][near]) < make_pair(abs(b[st][skip]), b[st][skip]))))
					) ++after;

					int cur = base;
					cur = mul(cur, b[nt][last]);
					cur = mul(cur, pow2[(int) b[nt].size() - last - 1 + b[st].size() - min(after, (int) b[st].size())]);
					ans = add(ans, cur);
				}

				if (skip < (int) b[st].size()) upd_table(skip_table, skip, b[st][skip]);
			}
			if (near >= 0) upd_table(near_table, near, b[nt][near]);
		}
	}

	cout << ans << endl;
}