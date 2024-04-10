#include <bits/stdc++.h>

std::mt19937 rnd(time(0));

const int N = 200005;

int n, m, a[N], c[N];
int v;
int ans;

int p[N << 1];

void updAns(int x) {
	if (v == x) {
		return;
	}
	for (int i = 0; i <= 2 * n; ++i) {
		p[i] = -1;
	}
	int now = n;
	p[now] = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == v) {
			++now;
		} else if (a[i] == x) {
			--now;
		}
		if (p[now] == -1) {
			p[now] = i;
		} else {
			ans = std::max(ans, i - p[now]);
		}
	}
}

int wnext(int i, int t) {
	if (t == 0) {
		return rnd() % i;
	} else if (t < 0) {
		return std::min<int>(rnd() % i, wnext(i, t + 1));
	} else {
		return std::max<int>(rnd() % i, wnext(i, t - 1));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
		m = std::max(m, a[i]);
	}

	std::vector<std::pair<int, int>> val;
	v = 0;
	for (int i = 1; i <= m; ++i) {
		if (!v || c[i] > c[v]) {
			v = i;
		}
		if (c[i]) {
			val.push_back({c[i], i});
		}
	}
	std::sort(val.begin(), val.end());
	std::reverse(val.begin(), val.end());

	for (int i = 0; i < 200 && i < (int)val.size(); ++i) {
		updAns(val[i].second);
	}
	if ((int)val.size() > 200) {
		for (int i = 0; i < 200; ++i) {
			int x = wnext(val.size() - 200, -2) + 200;
			updAns(val[x].second);
		}
	}
	std::cout << ans << "\n";
}