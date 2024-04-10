#include <iostream>
#define int long long
using namespace std;

const int N = 100 * 1000 + 5, SQ = 417;
int n, q;

long long a[N + N];
long long b[N + N];
bool mark[N];
long long s[N];
long long c[N];
long long d[N];
void solve(int p, int x) {
	if (mark[p]) {
		d[p] += abs(c[p] - x);
		s[p] += 1ll * abs(c[p] - x) * SQ;
		c[p] = x;
	}
	else {
		c[p] = x;
		for (int i = p * SQ; i < (p + 1) * SQ && i < n; i++) {
			s[p] += abs(a[i] - x);
			b[i] += abs(a[i] - x);
			a[i] = x;
		}
	}
	mark[p] = true;
}
void relax(int p) {
	if (mark[p]) {
		for (int i = p * SQ; i < (p + 1) * SQ && i < n; i++) {
			b[i] += d[p];
			a[i] = c[p];
		}
		d[p] = 0;
		mark[p] = false;
	}
}
signed main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	for (int i = 0; i < q; i++) {
		int qt, l, r;
		cin >> qt >> l >> r;
		l--;
		r--;
		if (qt == 1) {
			int x;
			cin >> x;
			relax(l / SQ);
			relax(r / SQ);
			int i = l;
			while (i <= r) {
				if (i + SQ <= r && i % SQ == 0) {
					solve(i / SQ, x);
					i += SQ;
				}
				else {
					b[i] += abs(a[i] - x);
					s[i / SQ] += abs(a[i] - x);
					a[i] = x;
					i++;
				}
			}
		}
		else {
			relax(l / SQ);
			relax(r / SQ);
			long long ans = 0;
			while (l <= r) {
				if (l + SQ <= r && l % SQ == 0) {
					ans += s[l / SQ];
					l += SQ;
				}
				else {
					ans += b[l];
					l++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}