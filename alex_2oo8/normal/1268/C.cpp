#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

namespace fwt {
	int t[MX + 1];
	
	void add(int x, int d) {
		x++;
		while (x <= MX) {
			t[x] += d;
			x += x & -x;
		}
	}
	
	int get(int x) {
		x++;
		int res = 0;
		while (x) {
			res += t[x];
			x -= x & -x;
		}
		return res;
	}
	
	int getKth(int k) {
		int x = 0;
		for (int p = 1 << 20; p > 0; p /= 2)
			if (x + p <= MX && t[x + p] < k) {
				k -= t[x + p];
				x += p;
			}
		
		return x;
	}
}

int countZeroes(int l, int r) {
	return r - l + 1 - (fwt::get(r) - fwt::get(l - 1));
}

int p[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	for (int i = 0, x; i < n; i++) {
		ignore = scanf("%d", &x);
		p[x - 1] = i;
	}
	
	printf("0");
	
	fwt::add(p[0], 1);
	int L = p[0], R = p[0], C = p[0];
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int x = p[i];
		
		L = min(L, x);
		R = max(R, x);
		
		ans += fwt::get(R) - fwt::get(x); // inversions
		
		if (x < C) {
			ans -= fwt::get(x) - fwt::get(L - 1);
			ans += countZeroes(x + 1, C);
		}
		else {
			ans -= fwt::get(R) - fwt::get(x);
			ans += countZeroes(C, x - 1);
		}
		
		fwt::add(x, 1);
		
		int c = fwt::getKth(i / 2 + 1);
		if (c < C) {
			int cnt = countZeroes(c, C);
			int Lones = fwt::get(c);
			int Rones = i + 1 - Lones;
			
			ans += cnt * 1LL * (Rones - Lones);
		}
		else if (c > C) {
			int cnt = countZeroes(C, c);
			int Lones = fwt::get(C);
			int Rones = i + 1 - Lones;
			
			ans += cnt * 1LL * (Lones - Rones);
		}
		
		C = c;
		
		printf(" %lld", ans);
	}
	
	printf("\n");
	
	return 0;
}