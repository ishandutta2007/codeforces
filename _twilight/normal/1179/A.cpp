#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long
#define pli pair<ll, int>

const int N = 1e5 + 5, Q = 3e5 + 5;

int n, q;
pli qs[Q];
int a[N * 3];
int resA[Q], resB[Q];

int main() {
	scanf("%d%d", &n, &q);
	int mx = 0, st = 0, ed = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + st + i);
		mx = max(mx, a[st + i]);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%lld", &qs[i].first);
		qs[i].second = i;
	}
	sort(qs + 1, qs + q + 1);
	int t = 1, A, B, pq = 1;
	while (pq <= q && a[st + 1] != mx) {
		A = a[st + 1], B = a[st + 2];
		if (A > B) {
			a[++st + 1] = A;
			a[++ed] = B;
		} else {
			a[++st + 1] = B;
			a[++ed] = A;
		}
		while (pq <= q && qs[pq].first == t) {
			resA[qs[pq].second] = A;
			resB[qs[pq].second] = B;
			pq++;
		}
		t++;
	}
	for (int i = pq; i <= q; i++) {
		int idx = ((qs[i].first - t) % (n - 1));
		resA[qs[i].second] = mx;
		resB[qs[i].second] = a[st + 2 + idx];
	}	
	for (int i = 1; i <= q; i++) {
		printf("%d %d\n", resA[i], resB[i]);
	}
	return 0;
}