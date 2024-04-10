#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <random>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a) {
		cin >> x;
		--x;
	}
	map<int, int> cnt;
	int pairs = 0;
	int solo = 0;
	vector<bool> was(n);
	for (int i = 0; i < n; i++) {
		if (was[i]) {
			continue;
		}
		int len = 1;
		int j = i;
		was[i] = true;
		while (a[j] != i) {
			len++;
			j = a[j];
			was[j] = true;
		}
		cnt[len]++;
		pairs += len / 2;
		solo += len % 2;
	}
	vector<int> obs;
	for (auto kek : cnt) {
		int x = 0;
		while ((1 << (x + 1)) - 1 <= kek.second) {
			x++;
		}
		for (int i = 0; i < x; i++) {
			obs.push_back(kek.first * (1 << i));
		}
		if ((1 << x) - 1 < kek.second) {
			obs.push_back(kek.first * (kek.second - ((1 << x) - 1)));
		}
	}
	const int N = 1'000'000;
	bitset<N> foo;
	foo.set(0);
	for (auto ob : obs) {
		foo |= (foo << ob);
	}
	auto mx = [&]() {
		if (k <= pairs) {
			return 2 * k;
		}
		if (k <= pairs + solo) {
			return 2 * pairs + (k - pairs);
		}
		return n;
	};
	cout << k + 1 - foo[k] << ' ' << mx() << endl;
}