#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int n, k;

#ifdef LOCAL

random_device rddev;
mt19937 rd;

int randint(int l, int r) {
	int a = r - l + 1;
	int x = rd() % a;
	x += a;
	x %= a;
	return x + l;
}

vector<int> secret;

void gen() {
	n = randint(1, 15);
	k = randint(1, n);
	secret.resize(n);
	for (int i = 0; i < n; i++) {
		secret[i] = randint(1, 1000);
	}
}
#endif

set<int> bad;
set<int> notBad;

int ask(vector<int> arr) {
	sort(arr.begin(), arr.end());
	arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
	assert((int) arr.size() == k);
	for (int el : arr) {
		if (bad.count(el)) {
			bad.erase(el);
			notBad.insert(el);
		} else {
			bad.insert(el);
			notBad.erase(el);
		}
	}
#ifndef LOCAL
	cout << "?";
	for (int j : arr) {
		cout << " " << j;
	}
	cout << endl;
	int x;
	cin >> x;
	return x;
#else
	int ans = 0;
	for (int el : arr) {
		ans ^= secret[el - 1];
	}
	return ans;
#endif
}

void solve() {
#ifndef LOCAL
	cin >> n >> k;
#endif
	for (int i = 0; i < n; i++) {
		bad.insert(i + 1);
	}
	if (n % 2 == 1 && k % 2 == 0) {
		cout << -1 << endl;
		return;
	}

	int ans = 1;
	int xx = 0;

	for (;; ans++) {
		int cntAll = ans * k;
		int cnt1 = cntAll / n;
		if (cnt1 % 2 == 0)
			cnt1--;
		if (cnt1 < 0) {
			continue;
		}
		vector<int> cnt(n, cnt1);
		if ((cntAll - cnt1 * n) % 2)
			continue;
		int rest = (cntAll - cnt1 * n) / 2;
		if (rest <= n) {
			for (int i = 0; i < rest; i++) {
				cnt[i] += 2;
			}
		}
		if (cnt[0] <= ans) {
			vector<vector<int>> qq(ans, vector<int> (k));
			int curi = 0;
			int curj = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < cnt[i]; j++) {
					qq[curi][curj] = i + 1;
					curi++;
					if (curi == ans) {
						curi = 0;
						curj++;
					}
				}
			}
			for (auto el : qq) {
				xx ^= ask(el);
			}
			assert(bad.empty());
			break;
		}
	}

	ans = xx;
	
#ifndef LOCAL
	cout << "! " << ans << endl;
#else
	int ans2 = 0;
	for (int el : secret)
		ans2 ^= el;
	if (ans2 != ans) {
		cout << n << " " << k << endl;
		for (int el : secret) {
			cout << el << " ";
		}
		cout << endl;
		cout << endl;
		cout << ans << endl;
	}
	assert(ans2 == ans);
#endif
}

signed main() {
#ifdef LOCAL
	auto seed = rddev();
	//seed = 3685956995;
	//seed = 294649012;
	//seed = 1659214540;
	seed = 2755296461;
	rd = mt19937(seed);
	cerr << "Seed: " << seed << endl;
	gen();
#endif
	int t = 1;
	while (t--) {
		solve();
	}
}