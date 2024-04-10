#include <bits/stdc++.h>

class vector {
	std::vector<int> a;
	int mx, cmx;

public:
	vector(std::vector<int> _a) : a(_a) {
		mx = cmx = *std::min_element(a.begin(), a.end()) - 1;
		for (int v : a) {
			if (v > mx) {
				cmx = mx, mx = v;
			} else if (v > cmx) {
				cmx = v;
			}
		}
	}

	int query(int x) {
		if (mx == a[x]) {
			return cmx;
		} else {
			return mx;
		}
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> sx(n), sy(n), tx(n), ty(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> sx[i] >> sy[i] >> tx[i] >> ty[i];
		tx[i] = -tx[i], ty[i] = -ty[i];
	}
	
	vector Sx(sx), Sy(sy), Tx(tx), Ty(ty);
	for (int i = 0; i < n; ++i) {
		if (Sx.query(i) <= -Tx.query(i) && Sy.query(i) <= -Ty.query(i)) {
			std::cout << Sx.query(i) << " " << Sy.query(i) << "\n";
			return 0;
		}
	}
}