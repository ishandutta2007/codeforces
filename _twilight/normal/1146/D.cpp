#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int inf = (~0u >> 2);

#define ll long long

typedef class Node {
	public:
		int p, d;

		Node(int p, int d) : p(p), d(d) {	}

		boolean operator < (Node b) const {
			return d > b.d;
		}
} Node;

int m, a, b;
int f[100005];

ll s2(int n) {
	return 1ll * n * (n + 1) / 2;
}

int main() {
	scanf("%d%d%d", &m, &a, &b);
	for (int i = 0; i < a; i++)
		f[i] = inf;
	priority_queue<Node> Q;
	Q.push(Node(0, f[0] = 0));
	while (!Q.empty()) {
		int p = Q.top().p;
		int d = Q.top().d;
		Q.pop();
		if (d ^ f[p]) {
			continue;
		}
		int e = (((p - b) % a) + a) % a;
		int k = max(max((b + a - 1 - p) / a, 0) * a + p, d);
		if (k < f[e]) {
			Q.push(Node(e, f[e] = k));
		}
	}
	ll ans = 0;
	for (int i = 0; i < a; i++) {
		if (f[i] <= m) {
			int c = (f[i] - i) / a + 1;
			int R = (m - i) / a;
			ans += 1ll * c * (m - f[i] + 1);
			ans += 1ll * (R - c + 1) * (m - i + 1);
			ans -= 1ll * a * (s2(R) - s2(c - 1));
		}
	}
	printf("%lld\n", ans);
	return 0;
}