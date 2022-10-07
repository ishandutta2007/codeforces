#include <bits/stdc++.h>

int n;

int Query(int x) {
	std::cout << "? " << x + 1 << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void setAns(int x) {
	std::cout << "! " << (x == -1 ? -1 : x + 1) << std::endl;
}

int solve(int l, int r, int vl) {
	if (l + 1 == r) {
		assert(vl == 0);
		return l;
	}
	int mid = (l + r + 1) >> 1;
	int vm = Query(mid) - Query(mid + n);
	if (vl == 0 || (vm != 0 && (vl > 0) != (vm > 0))) {
		return solve(l, mid, vl);
	} else {
		return solve(mid, r, vm);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> n;
	n /= 2;
	if (n & 1) {
		setAns(-1);
		return 0;
	}

	setAns(solve(0, n, Query(0) - Query(n)));
}