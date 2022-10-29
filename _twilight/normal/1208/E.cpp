#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e6 + 4;

int n, w;
ll ans[N];
ll dans[N];
int a[N], q[N];

void add(int l, int r, int v) {
	dans[l] += v;
	dans[r + 1] -= v;
}

int main() {
	scanf("%d%d", &n, &w);
	while (n--) {
		int l;
		scanf("%d", &l);
		for (int i = 1; i <= l; i++) {
			scanf("%d", a + i);
		}
		if (l == w) {
			for (int i = 1; i <= w; i++) {
				ans[i] += a[i];
			}
		} else if ((l << 1) <= w) {
			int mx = 0;
			for (int i = 1; i <= l; i++) {
				mx = max(mx, a[i]);
				ans[i] += mx;
			}
			mx = 0;
			for (int i = 0; i < l; i++) {
				mx = max(mx, a[l - i]);
				ans[w - i] += mx;
			}
			add(l + 1, w - l, mx);
		} else {
			int L = w - l;
			int mx = 0;
			for (int i = 1; i <= L; i++) {
				mx = max(mx, a[i]);
				ans[i] += mx;
			}
			int st = 1, ed = 0;
			for (int i = 1; i <= L; i++) {
				while (st <= ed && a[q[ed]] <= a[i])
					ed--;
				q[++ed] = i;
			}
			for (int i = L + 1; i <= l; i++) {
				while (st <= ed && q[st] < i - L)
					st++;
				while (st <= ed && a[q[ed]] <= a[i])
					ed--;
				q[++ed] = i;
				ans[i] += a[q[st]];
			}
			mx = 0;
			for (int i = 0; i < L; i++) {
				mx = max(mx, a[l - i]);
				ans[w - i] += mx;
			}
		}
	}
	for (int i = 1; i <= w; i++)
		ans[i] += (dans[i] += dans[i - 1]);
	for (int i = 1; i <= w; i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}