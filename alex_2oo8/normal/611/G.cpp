#include<bits/stdc++.h>

using namespace std;

const int MX = 1000000, md = 1000000007;

int x[MX], y[MX];

long long cross_product(int a, int b) {
	return x[a] * 1ll * y[b] - x[b] * 1ll * y[a];
}

long long area(int a, int b, int c) {
	return abs(cross_product(a, b) + cross_product(b, c) + cross_product(c, a));
}

int solve(int n) {
	long long S = 0;
	for (int i = 0; i < n; i++) S += cross_product(i, i + 1);
	
	int ans = 0;
	long long s = 0, cnt = -1, xs = 0, ys = 0, cpk = 0, cps = 0;
	for (int i = 0, j = 0; i < n; i++) {
		while (s + area(i, j, j + 1) <= S / 2) {
			s += area(i, j, j + 1);
			j++;
			
			cps += cross_product(j - 1, j);
			cps %= md;
			if (cps < 0) cps += md;
			
			cpk += cps;
			if (cpk >= md) cpk -= md;
			
			xs += x[j];
			if (xs >= md) xs -= md;
			if (xs < 0) xs += md;
			
			ys += y[j];
			if (ys >= md) ys -= md;
			if (ys < 0) ys += md;
			
			cnt++;
		}
		
		if (cnt > 0) ans = (ans + (S % md) * cnt - 2 * (cpk - x[i] * ys + y[i] * xs)) % md;
		
		s -= area(i, i + 1, j);
		
		cpk = (cpk - cross_product(i, i + 1) % md * (cnt + 1)) % md;
		if (cpk < 0) cpk += md;
		
		cps -= cross_product(i, i + 1);
		cps %= md;
		if (cps < 0) cps += md;
		
		xs -= x[i + 1];
		if (xs >= md) xs -= md;
		if (xs < 0) xs += md;
		
		ys -= y[i + 1];
		if (ys >= md) ys -= md;
		if (ys < 0) ys += md;
		
		cnt--;
	}
	
	if (ans < 0) ans += md;
	
	return ans;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", x + i, y + i);
		
		x[n + i] = x[i];
		y[n + i] = y[i];
	}
	
	for (int i = 0, j = 2 * n - 1; i < j; i++, j--) {
		swap(x[i], x[j]);
		swap(y[i], y[j]);
	}
	
	printf("%d\n", solve(n));
	
	return 0;
}