#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

class set {
	std::priority_queue<int> Q;
	std::priority_queue<int, std::vector<int>, std::greater<int>> R;
	long long sum;

public:
	set() : sum(0) {}

	int size() {
		return Q.size() + R.size();
	}

	void insert(int x) {
		if (!Q.empty() && x < Q.top()) {
			R.push(Q.top());
			sum -= Q.top();
			Q.pop();
			Q.push(x);
			sum += x;
		} else {
			R.push(x);
		}
	}

	long long ksum(int k) {
		if ((int)Q.size() < k) {
			while (!R.empty() && (int)Q.size() < k) {
				Q.push(R.top());
				sum += R.top();
				R.pop();
			}
		} else if ((int)Q.size() > k) {
			while ((int)Q.size() > k) {
				R.push(Q.top());
				sum -= Q.top();
				Q.pop();
			}
		}
		return sum;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;
	std::array<std::vector<std::pair<int, int>>, 4> a;
	for (int i = 0; i < n; ++i) {
		int w, p, q;
		std::cin >> w >> p >> q;
		a[p << 1 | q].emplace_back(w, i);
	}
	for (int i = 0; i < 4; ++i) {
		std::sort(a[i].begin(), a[i].end());
	}

	set S;
	for (int i = 0; i < (int)a[0].size(); ++i) {
		S.insert(a[0][i].first);
	}
	int p = std::min(a[1].size(), a[2].size());
	for (int i = p; i < (int)a[1].size(); ++i) {
		S.insert(a[1][i].first);
	}
	for (int i = p; i < (int)a[2].size(); ++i) {
		S.insert(a[2][i].first);
	}
	long long ans = INF;
	int ti = 0, tp = 0;
	long long sum = 0;
	for (int i = 0; i < p; ++i) {
		sum += a[1][i].first;
		sum += a[2][i].first;
	}
	for (int i = 0; i <= (int)a[3].size(); ++i) {
		while (p && i + p > k) {
			--p;
			sum -= a[1][p].first;
			sum -= a[2][p].first;
			S.insert(a[1][p].first);
			S.insert(a[2][p].first);
		}
		if (i + p >= k && i + 2 * p <= m && m - i - 2 * p <= S.size()) {
			long long T = sum + S.ksum(m - i - 2 * p);
			if (T < ans) {
				ans = T;
				ti = i, tp = p;
			}
		}
		if (i < (int)a[3].size()) {
			sum += a[3][i].first;
		}
	}
	if (ans == INF) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
		std::vector<std::pair<int, int>> S;
		for (int i = 0; i < (int)a[0].size(); ++i) {
			S.push_back(a[0][i]);
		}
		for (int i = tp; i < (int)a[1].size(); ++i) {
			S.push_back(a[1][i]);
		}
		for (int i = tp; i < (int)a[2].size(); ++i) {
			S.push_back(a[2][i]);
		}
		std::sort(S.begin(), S.end());
		S.resize(m - ti - 2 * tp);
		for (int i = 0; i < ti; ++i) {
			S.push_back(a[3][i]);
		}
		for (int i = 0; i < tp; ++i) {
			S.push_back(a[1][i]);
			S.push_back(a[2][i]);
		}
		for (auto p : S) {
			std::cout << p.second + 1 << " ";
		}
		std::cout << "\n";
	}
}