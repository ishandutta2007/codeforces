#include <bits/stdc++.h>

const int N = 3005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;

struct Person {
	int p, c;
	
	bool operator < (const Person &rhs) const {
		return c < rhs.c;
	}
} a[N];

std::vector<int> p[N];
bool vis[N];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].p >> a[i].c;
	}
	std::sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		p[a[i].p].push_back(i);
	}
	long long ans = INF;
	for (int x = 1; x <= n; ++x) {
		for (int i = 1; i <= n; ++i) {
			vis[i] = 0;
		}
		int now = p[1].size();
		long long s = 0;
		for (int i = 2; i <= m; ++i) {
			int h = 0;
			while ((int)p[i].size() - h >= x) {
				vis[p[i][h]] = 1;
				s += a[p[i][h]].c;
				++h;
				++now;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (now >= x) {
				break;
			}
			if (!vis[i] && a[i].p != 1) {
				s += a[i].c;
				++now;
			}
		}
		ans = std::min(ans, s);
	}
	std::cout << ans << "\n";
}