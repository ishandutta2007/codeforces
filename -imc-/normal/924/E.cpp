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

const int N = 11111;
char knap[N];
int crucial[N];
int timer = 0;

int main() {
	int n = nxt(), l = nxt(), r = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		b[i] = nxt();
	}

	vector<int> imp, shit;
	for (int i = 0; i < n; ++i) {
		(b[i] ? imp : shit).push_back(a[i]);
	}

	sort(all(imp));
	sort(all(shit));

	// optimize)))
	map<int, int> M;
	for (int x : shit) {
		M[x] += 1;
		while (M[x] > 2) {
			M[x] -= 2;
			x *= 2;
			M[x] += 1;
		}
	}
	shit.clear();
	for (auto p : M) {
		for (int i = 0; i < p.second; ++i) {
			shit.push_back(p.first);
		}
	}

	knap[0] = 1;
	int mx = 0;
	for (int x : shit) {
		for (int i = mx; i >= 0; --i) {
			if (knap[i]) {
				knap[i + x] = 1;
			}
		}
		mx += x;
	}

	// for (int x : shit) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (int i = 0; i <= mx; ++i) {
	// 	cerr << (int)knap[i];
	// }
	// cerr << "\n";

	int cur = l;
	while (cur <= r && !knap[cur]) {
		++cur;
	}
	int cur_nc = cur;

	vector<int> pr_sums(imp.size() + 1);
	for (int i = 0; i < (int)imp.size(); ++i) {
		pr_sums[i + 1] = pr_sums[i] + imp[i];
	}

	int ans = 0;
	for (int i = (int)imp.size() - 1; i >= 0; --i) {
		++timer;
		int x = imp[i];
		for (int j = mx; j >= 0; --j) {
			if (knap[j]) {
				if (!knap[j + x] && crucial[j] == timer - 1) {
					crucial[j + x] = timer;
				}
				knap[j + x] = 1;
				if (j + x >= l && j + x < cur) {
					cur = j + x;
				}
				if (j + x >= l && j + x < cur_nc && crucial[j + x] < timer) {
					cur_nc = j + x;
				}
			}
		}
		mx += x;

		// cerr << x << ":\n";
		// for (int j = 0; j <= mx; ++j) {
		// 	cerr << (int)knap[j];
		// }
		// cerr << "\n";
		// for (int j = 0; j <= mx; ++j) {
		// 	cerr << (int)(crucial[j] == timer);
		// }
		// cerr << "\n";
		// cerr << cur << " " << cur_nc << "\n";
		
		int len = r - cur;
		int cnt = min<int>(upper_bound(all(pr_sums), len) - pr_sums.begin(), i + 1) - 1;
		ans = max(ans, cnt);
		// cerr << cnt << ", ";

		len = r - cur_nc;
		cnt = min<int>(upper_bound(all(pr_sums), len) - pr_sums.begin(), i + 1) - 1;
		if (len >= 0) {
			ans = max(ans, cnt + 1);
		}
		// cerr << cnt << "\n";
	}

	printf("%d\n", ans);

	return 0;
}