#include <bits/stdc++.h>

class mono_queue {
	std::function<bool(int, int)> cmp;

	std::size_t h;
	std::vector<int> a;

public:
	mono_queue(std::function<bool(int, int)> _cmp) : cmp(_cmp), h(0) {}

	void push(int x) {
		while (h < a.size() && !cmp(a.back(), x)) {
			a.pop_back();
		}
		a.push_back(x);
	}

	void pop(int x) {
		while (h < a.size() && a[h] < x) {
			++h;
		}
	}

	int top() {
		return a[h];
	}

	bool empty() {
		return h == a.size();
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	auto cmp_min = [&](int x, int y) {
		return a[x] < a[y];
	};
	auto cmp_max = [&](int x, int y) {
		return a[x] > a[y];
	};
	std::vector<mono_queue> Qmin(2, mono_queue(cmp_min));
	std::vector<mono_queue> Qmax(2, mono_queue(cmp_max));
	std::vector<int> ans(n);
	int cnt = 0;
	int l = 0, r = 0;
	auto check = [&]() {
		return r - l <= 1 || 
		       cmp_min(Qmax[~r & 1].top(), std::min(Qmin[r & 1].top(), r, cmp_min)) ||
			   cmp_max(Qmin[~r & 1].top(), std::min(Qmax[r & 1].top(), r, cmp_max));
	};
	auto get_ans = [&]() {
		if (l >= r || !((r - l) & 1)) {
			return;
		}
		int mid = l + (r - l - 1) / 2;
		if (r - l == 1 || cmp_min(Qmax[~l & 1].top(), Qmin[l & 1].top())) {
			ans[mid] = a[Qmin[l & 1].top()];
		} else {
			ans[mid] = a[Qmax[l & 1].top()];
		}
		cnt = std::max(cnt, (r - l - 1) / 2);
	};
	auto push = [&]() {
		Qmin[r & 1].push(r);
		Qmax[r & 1].push(r);
		++r;
		get_ans();
	};
	auto pop = [&]() {
		++l;
		Qmin[~l & 1].pop(l);
		Qmax[~l & 1].pop(l);
		get_ans();
	};
	while (l < n) {
		while (r < n && check()) {
			push();
		}
		pop();
	}
	std::cout << cnt << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}