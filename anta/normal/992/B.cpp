#include "bits/stdc++.h"
using namespace std;
template<typename T>T gcd(T x, T y) { if (y == 0)return x; else return gcd(y, x%y); }

int main() {
	int l; int r; int x; int y;
	while (~scanf("%d%d%d%d", &l, &r, &x, &y)) {
		vector<int> is;
		for (int i = 1; i * i <= y; ++ i) if (y % i == 0) {
			is.push_back(i);
			if (i * i != y) is.push_back(y / i);
		}
		int ans = 0;
		for (int i : is) if (l <= i && i <= r)
			for (int j : is) if (l <= j && j <= r)
				ans += gcd(i, j) == x && (long long)i * j / x == y;
		printf("%d\n", ans);
	}
}