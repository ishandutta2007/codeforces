#include <bits/stdc++.h>

class set {
	std::priority_queue<int> Q;
	std::priority_queue<int, std::vector<int>, std::greater<int>> R;
	long long sumQ, sumR;

	void shift() {
		while (Q.size() < R.size()) {
			sumQ += R.top();
			Q.push(R.top());
			sumR -= R.top();
			R.pop();
		}
	}

public:
	set() : sumQ(0), sumR(0) {}

	void insert(int x) {
		if (!Q.empty() && x < Q.top()) {
			sumR += Q.top();
			R.push(Q.top());
			sumQ -= Q.top();
			Q.pop();
			sumQ += x;
			Q.push(x);
		} else {
			sumR += x;
			R.push(x);
		}
		shift();
	}

	long long get_ans() {
		int k = Q.top() + 1;
		int cQ = Q.size(), cR = R.size();
		return 1ll * k * cQ - sumQ - 1ll * cQ * (cQ + 1) / 2 +
		       sumR - 1ll * k * cR - 1ll * cR * (cR - 1) / 2;
	}
};

class BIT {
	int n;
	std::vector<int> c;
	long long ans;

	int count(int x) {
		int s = 0;
		for (++x; x <= n; x += x & -x) {
			s += c[x];
		}
		return s;
	}

public:
	BIT(int _n) : n(_n), c(n + 1), ans(0) {}

	void insert(int x) {
		ans += count(x);
		for (++x; x; x ^= x & -x) {
			++c[x];
		}
	}

	long long get_ans() {
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> q(n);
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		--x;
		q[x] = i;
	}

	set S;
	BIT T(n);
	for (int i = 0; i < n; ++i) {
		S.insert(q[i]);
		T.insert(q[i]);
		std::cout << S.get_ans() + T.get_ans() << " ";
	}
	std::cout << "\n";
}