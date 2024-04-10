#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

int n;
int Lp[1000002];
long long dist[1000002];
std::vector<long long> li[1000002];
std::vector<long long> cs[1000002];

void query(const int &A, const int &H, const int &offset, const int &range, long long &ans) {
	if (range <= 0 || A > n) return;
	int lo = 0;
	int hi = li[A].size() - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) >> 1;
		if (li[A][mid] < range + dist[A])
			lo = mid;
		else
			hi = mid - 1;
	}
	ans += (lo + 1) * (H - offset + dist[A]) - cs[A][lo];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int m;
	std::cin >> n >> m;
	
	for (int i = 1; i < n; ++i) {
		int L;
		std::cin >> L;
		int from = (i + 1) / 2;
		int to = i + 1;
		Lp[to] = L;
	}

	dist[1] = 0;
	for (int i = 2; i <= n; ++i)
		dist[i] = dist[i >> 1] + Lp[i];

	for (int i = n; i >= 1; --i) {
		li[i].push_back(dist[i]);
		if ((i << 1) <= n)
			li[i].insert(li[i].end(), li[i << 1].begin(), li[i << 1].end());
		if ((i << 1 | 1) <= n)
			li[i].insert(li[i].end(), li[i << 1 | 1].begin(), li[i << 1 | 1].end());
		std::sort(li[i].begin(), li[i].end());
		cs[i].resize(li[i].size());
		cs[i][0] = li[i][0];
		for (int j = 1; j < li[i].size(); ++j)
			cs[i][j] = cs[i][j - 1] + li[i][j];
	}

	for (; m > 0; --m) {
		int A, H;
		std::cin >> A >> H;

		int offset = 0;
		int range = H;
		long long ans = 0;
		query(A, H, offset, range, ans);
		while (A > 1) {
			// switch subtree
			int delta = Lp[A];
			A ^= 1;
			delta += Lp[A];
			offset += delta;
			range -= delta;
			
			query(A, H, offset, range, ans);

			// go up
			offset -= Lp[A];
			range += Lp[A];
			A >>= 1;
			if (range <= 0)
				break;
			ans += H - offset;
		}
		std::cout << ans << '\n';
	}
	return 0;
}