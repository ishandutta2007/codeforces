/*input
5
3 1 4 1 5


*/

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int K = 5000;
int n;
array<array<int, K + 1>, K + 1> facts;
array<vector<int>, K + 1> paths;
array<int, K + 1> prime, cnt;

int main()
{
	// sieve
	for (int i = 2; i <= K; ++i) if (prime[i] == 0) {
		prime[i] = i;
		for (int j = i * i; j <= K; j += i) {
			prime[j] = i;
		}
	}

	for (int i = 1; i <= K; ++i) {
		facts[i] = facts[i - 1];
		for (int j = i; j > 1; j /= prime[j]) {
			++facts[i][prime[j]];
		}
	}

	for (int i = 0; i <= K; ++i) {
		paths[i].reserve(accumulate(facts[i].begin(), facts[i].end(), 0));
		for (int j = K; j > 1; --j) {
			for (int _ = 0; _ < facts[i][j]; ++_) {
				paths[i].push_back(j);
			}
		}
	}

	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		++cnt[k];
	}

	int64_t cur_dist = 0;
	for (int i = 0; i <= K; ++i) {
		cur_dist += (int64_t) paths[i].size() * cnt[i];
	}
	int l = 0, r = K + 1;
	for (int id = 0; ; ++id) {
		bool adv = 0;
		for (int l0 = l; l0 < r;) {
			if ((int) paths[l0].size() <= id) {
				++l0;
				continue;
			}

			int r0 = l0, n_child = 0;
			for (; r0 < r && (int) paths[r0].size() > id && paths[l0][id] == paths[r0][id]; ++r0) {
				n_child += cnt[r0];
			}

			if (n_child > n - n_child) {
				adv = 1;
				cur_dist += (n - n_child) - n_child;
				l = l0, r = r0;
				break;
			}

			l0 = r0;
		}
		if (!adv) break;
	}

	cout << cur_dist << endl;
}