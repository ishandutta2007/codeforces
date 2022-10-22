#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 60;
vector<long long> a[L];

void panic() {
	puts("No");
	exit(0);
}

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		long long x;
		scanf("%lld", &x);
		a[63 - __builtin_clzll(x)].push_back(x);
	}

	vector<long long> ans;
	for (int i = L - 1; i >= 0; --i) {
		bool can = true;
		vector<long long> new_ans;
		for (auto x : ans) {
			if (!a[i].empty() && can) {
				new_ans.push_back(a[i].back());
				a[i].pop_back();
				can = false;
			}
			new_ans.push_back(x);
			if (x & (1ll << i)) {
				can ^= 1;
			}
		}
		if (!a[i].empty() && can) {
			new_ans.push_back(a[i].back());
			a[i].pop_back();
			can = false;
		}

		if (!a[i].empty()) {
			panic();
		} else {
			new_ans.swap(ans);
		}
	}

	printf("Yes\n");
	for (auto x : ans) {
		printf("%lld ", x);
	}
	printf("\n");

	// long long s = 0;
	// for (auto x : ans) {
	// 	assert((s ^ x) > s);
	// 	s ^= x;
	// }

	return 0;
}