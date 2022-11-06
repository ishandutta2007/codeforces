#include <bits/stdc++.h>
#define pb push_back
using std::bitset; using std::vector; using std::sort; using std::swap;
const int N = 1005, M = 185;
int T, n, m, a[N], b[N], t[N];
bitset<N * N> f[N]; bitset<M * N> g[M];
vector<int> la, ra, lb, rb;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
		if (n != m) { puts("No"); continue; }
		else if (n <= 180) {
			int sum = 0;
			for (int i = 1; i <= n; i++) sum += a[i], t[i] = 0;
			if (sum & 1) { puts("No"); continue; }
			g[0].reset(); g[0][0] = 1;
			for (int i = 1; i <= n; i++)
				g[i] = g[i - 1] << a[i] | g[i - 1];
			if (g[n][sum / 2]) {
				for (int i = n, now = sum / 2; i; i--)
					if (a[i] <= now && g[i - 1][now - a[i]])
						t[i] = 1, now -= a[i];
			} else { puts("No"); continue; }
			la.clear(), ra.clear();
			for (int i = 1; i <= n; i++)
				t[i] ? la.pb(a[i]) : ra.pb(a[i]);
			sum = 0;
			for (int i = 1; i <= n; i++) sum += b[i], t[i] = 0;
			if (sum & 1) { puts("No"); continue; }
			g[0].reset(); g[0][0] = 1;
			for (int i = 1; i <= n; i++)
				g[i] = g[i - 1] << b[i] | g[i - 1];
			if (g[n][sum / 2]) {
				for (int i = n, now = sum / 2; i; i--)
					if (b[i] <= now && g[i - 1][now - b[i]])
						t[i] = 1, now -= b[i];
			} else { puts("No"); continue; }
			lb.clear(), rb.clear();
			for (int i = 1; i <= n; i++)
				t[i] ? lb.pb(b[i]) : rb.pb(b[i]);
		} else {
			int sum = 0;
			for (int i = 1; i <= n; i++) sum += a[i], t[i] = 0;
			if (sum & 1) { puts("No"); continue; }
			f[0].reset(); f[0][0] = 1;
			for (int i = 1; i <= n; i++)
				f[i] = f[i - 1] << a[i] | f[i - 1];
			if (f[n][sum / 2]) {
				for (int i = n, now = sum / 2; i; i--)
					if (a[i] <= now && f[i - 1][now - a[i]])
						t[i] = 1, now -= a[i];
			} else { puts("No"); continue; }
			la.clear(), ra.clear();
			for (int i = 1; i <= n; i++)
				t[i] ? la.pb(a[i]) : ra.pb(a[i]);
			sum = 0;
			for (int i = 1; i <= n; i++) sum += b[i], t[i] = 0;
			if (sum & 1) { puts("No"); continue; }
			f[0].reset(); f[0][0] = 1;
			for (int i = 1; i <= n; i++)
				f[i] = f[i - 1] << b[i] | f[i - 1];
			if (f[n][sum / 2]) {
				for (int i = n, now = sum / 2; i; i--)
					if (b[i] <= now && f[i - 1][now - b[i]])
						t[i] = 1, now -= b[i];
			} else { puts("No"); continue; }
			lb.clear(), rb.clear();
			for (int i = 1; i <= n; i++)
				t[i] ? lb.pb(b[i]) : rb.pb(b[i]);
		}
		puts("Yes");
		sort(la.begin(), la.end()); sort(lb.begin(), lb.end());
		sort(ra.begin(), ra.end()); sort(rb.begin(), rb.end());
		int x = 0, y = 0;
		if (la.size() > ra.size()) swap(la, ra);
		if (lb.size() < rb.size()) swap(lb, rb);
		for (int i = 0; i < n; i++) {
			int dx, dy;
			if (i < la.size()) dx = la[la.size() - i - 1]; else dx = -ra[ra.size() - (i - la.size()) - 1];
			if (i < lb.size()) dy = lb[i]; else dy = -rb[i - lb.size()];
			x += dx; printf("%d %d\n", x, y);
			y += dy; printf("%d %d\n", x, y);
		}
	}
	return 0;
}