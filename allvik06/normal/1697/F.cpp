#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct two_sat {
	int n, k, m;
	vector <vector <int>> g, rg;
	vector <int> used, ord, cmp;

	inline void add(int x, int y) {
		g[x].push_back(y);
		g[y ^ 1].push_back(x ^ 1);
		rg[y].push_back(x);
		rg[x ^ 1].push_back(y ^ 1);
	}

	inline int num1(int x, int y) {
		return 4 * x * k + y * 2;
	}

	inline int num2(int x, int y) {
		return 4 * x * k + 2 * k + 2 * y;
	}

	inline void add_eq(int x, int y) {
		add(x, y);
		add(x ^ 1, y ^ 1);
	}

	two_sat(int n, int k) : n(n), k(k) {
		m = 4 * n * k;
        cmp.resize(m, -1);
		g.resize(m);
		rg.resize(m);
		used.resize(m);
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j < k; ++j) {
				add(num1(i, j - 1), num1(i, j));
			}
            add(num1(i, k - 1) ^ 1, num1(i, k - 1));
            add(num2(i, 0) ^ 1, num2(i, 0));
			for (int j = 0; j < k - 1; ++j) {
                add_eq(num1(i, j), num2(i, j + 1) ^ 1);
            }
            if (i) {
                for (int j = 0; j < k; ++j) {
                    add(num1(i, j), num1(i - 1, j));
                }
            }
		}
	}

	inline void add1(int x, int y) {
		if (y == 0) add(num1(x, 0), num1(x, 0) ^ 1);
        else add_eq(num1(x, y), num1(x, y - 1));
	}

	inline void add2(int x, int y, int s) {
        if (s < k) add(num1(x, 0), num1(y, s));
		for (int i = 0; i < k - 1; ++i) {
			int max_val = s - (i + 1);
            if (max_val < 0) add(num1(x, i) ^ 1, num1(x, i));
            else if (max_val >= k - 1) continue;
            else add(num1(x, i) ^ 1, num2(y, max_val + 1) ^ 1);
		}
	}

	inline void add3(int x, int y, int s) {
        if (s >= k - 1) add(num2(x, k - 1), num2(y, s - (k - 1)));
		for (int i = k - 1; i > 0; --i) {
            int min_val = s - (i - 1);
            if (min_val >= k) add(num2(x, i) ^ 1, num2(x, i));
            else if (min_val <= 0) continue;
            else add(num2(x, i) ^ 1, num1(y, min_val - 1) ^ 1);
        }
	}

	void top_sort(int v) {
		used[v] = 1;
		for (int i : g[v]) {
			if (!used[i]) {
				top_sort(i);
			}
		}
		ord.push_back(v);
	}

    void set_cmp(int v, int lvl) {
        cmp[v] = lvl;
        for (int i : rg[v]) {
            if (cmp[i] == -1) {
                set_cmp(i, lvl);
            }
        }
    }

	vector <int> solve() {
		for (int i = 0; i < m; ++i) {
			if (!used[i]) {
				top_sort(i);
			}
		}
		reverse(ord.begin(), ord.end());
		int now = 0;
		for (int i : ord) {
			if (cmp[i] == -1) {
                set_cmp(i, now++);
            }
		}
		vector <int> ans;
		for (int i = 0; i < m; i += 2) {
			if (cmp[i] == cmp[i ^ 1]) return {};
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				int nm = num1(i, j);
				if (cmp[nm] > cmp[nm ^ 1]) {
                    ans.push_back(j + 1);
                    break;
                }
			}
		}
		return ans;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	two_sat now(n, k);
	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, x;
			cin >> i >> x;
			now.add1(i - 1, x - 1);
		} else if (type == 2) {
			int x, y, s;
			cin >> x >> y >> s;
			now.add2(x - 1, y - 1, s - 2);
		} else {
			int x, y, s;
			cin >> x >> y >> s;
			now.add3(x - 1, y - 1, s - 2);
		}
	}
	auto ans = now.solve();
	if (ans.empty()) cout << "-1\n";
	else {
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
}

int main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}