#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int qq = 0; qq < t; ++qq) {
		int x, p, k;
		scanf("%d%d%d", &x, &p, &k);
		vector<int> f;
		for (int i = 2; i * i <= p; ++i)
			if (p % i == 0) {
				f.push_back(i);
				while (p % i == 0)
					p /= i;
			}
		if (p > 1)
			f.push_back(p);
		int sum = 0;
		for (int mask = 1; mask < (1 << f.size()); ++mask) {
			int mult = 1, bits = 0;
			for (int i = 0; i < (int)f.size(); ++i)
				if (mask & (1 << i)) {
					mult *= f[i];
					++bits;
				}
			int cur = x / mult;
			if (bits & 1)
				sum += cur;
			else
				sum -= cur;
		}
		int cnt = x - sum;
		int l = x, r = 1000000000;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int sum = 0;
			for (int mask = 1; mask < (1 << f.size()); ++mask) {
				int mult = 1, bits = 0;
				for (int i = 0; i < (int)f.size(); ++i)
					if (mask & (1 << i)) {
						mult *= f[i];
						++bits;
					}
				int cur = m / mult;
				if (bits & 1)
					sum += cur;
				else
					sum -= cur;
			}
			int c = m - sum;
			if (c - cnt < k)
				l = m;
			else
				r = m;
		}
		printf("%d\n", r);
	}
	return 0;
}