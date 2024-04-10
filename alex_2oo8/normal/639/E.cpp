#include<bits/stdc++.h>

using namespace std;

const int MX = 300000;

struct problem_t {
	long long p, t, t1, t2;
} a[MX];

bool cmp1(const problem_t& L, const problem_t& R) {
	if (L.p * R.t != R.p * L.t) return L.p * R.t > R.p * L.t;
	
	return L.p < R.p;
}

bool cmp2(const problem_t& L, const problem_t& R) {
	return L.p < R.p;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i].p);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i].t);
	
	sort(a, a + n, cmp1);
	
	a[0].t1 = a[0].t2 = a[0].t;
	for (int i = 1; i < n; i++) a[i].t1 = a[i].t2 = a[i - 1].t1 + a[i].t;
	for (int i = 1; i < n; i++)
		if (a[i - 1].p * a[i].t == a[i].p * a[i - 1].t)
			a[i].t1 = a[i - 1].t1 - a[i - 1].t + a[i].t;
	
	for (int i = n - 2; i >= 0; i--)
		if (a[i + 1].p * a[i].t == a[i].p * a[i + 1].t)
			a[i].t2 = a[i + 1].t2;
	
	long long T = a[n - 1].t2;
	
	sort(a, a + n, cmp2);
	
	long double ans = 0.0, f = 1.0;
	for (int iter = 0; iter < 100; f /= 2, iter++) {
		long double c = ans + f, mx = 0;
		bool ok = true;
		int r = 0;
		for (int i = 0; i < n; i++) {
			while (a[r].p < a[i].p) {
				mx = max(a[r].p * (1 - c * a[r].t1 / T), mx);
				r++;
			}
			
			if (a[i].p * (1 - c * a[i].t2 / T) < mx) ok = false;
		}
		
		if (ok) ans = c;
	}
	
	printf("%.12f\n", (double)ans);
	
	return 0;
}