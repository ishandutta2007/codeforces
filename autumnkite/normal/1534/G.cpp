#include <bits/stdc++.h>

class state {
	long long v0;
	long long d0;
	long long t;
	std::priority_queue<long long, std::vector<long long>, std::less<long long>> pl;
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pr;

	void adjust() {
		while ((int)pl.size() > d0) {
			pr.push(pl.top() - t);
			pl.pop();
		}
		while ((int)pr.size() > d0) {
			pl.push(pr.top() + t);
			pr.pop();
		}
	}

public:
	state() : v0(0), d0(0), t(0) {}

	void insert(long long x) {
		v0 += x;
		++d0;
		if (pr.empty() || x >= pr.top() + t) {
			pr.push(x - t);
			pr.push(x - t);
		} else {
			pl.push(x);
			pl.push(x);
		}
		adjust();
	}

	void advance(long long delta) {
		t += delta;
	}

	long long minimum() {
		auto tmp = pl;
		std::vector<int> p;
		while (!tmp.empty()) {
			p.push_back(tmp.top());
			tmp.pop();
		}
		long long now = d0;
		long long lst = 0;
		long long sum = v0;
		while (!p.empty()) {
			sum -= now * (p.back() - lst);
			lst = p.back();
			--now;
			p.pop_back();
		}
		return sum;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].first >> a[i].second;
		a[i].first += a[i].second;
	}
	std::sort(a.begin(), a.end());

	int lst = 0;
	state f;
	for (int i = 0; i < n; ++i) {
		f.advance(a[i].first - lst);
		f.insert(a[i].second);
		lst = a[i].first;
	}
	std::cout << f.minimum() << "\n";
}