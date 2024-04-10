#include <bits/stdc++.h>

const int N = 200005, P = 998244353, Inv2 = (P + 1) / 2;

int n, k, a[N], vis[N], pre[N], suf[N];

int qpow(int a, int b) {
	int s = 1;
	for (; b; b >>= 1) {
		if (b & 1) {
			s = 1ll * s * a % P;
		}
		a = 1ll * a * a % P;
	}
	return s;
}

struct BIT {
	int c[N];
	
	void add(int x, int v) {
		for (; x <= n; x += x & -x) {
			c[x] += v;
		}
	}
	
	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		if (a[i] == -1) {
			++k;
		} else {
			++vis[a[i]];
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (!vis[i]);
	}
	for (int i = n; i; --i) {
		suf[i] = suf[i + 1] + (!vis[i]);
	}
	
	int Invk = qpow(k, P - 2);
	int ans = 0;

	for (int i = n; i; --i) {
		if (a[i] != -1) {
			ans = (ans + T.query(a[i])) % P;
			T.add(a[i], 1);
		}
	}

	int prec = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == -1) {
			++prec;
		} else {
			ans = (ans + 1ll * prec * suf[a[i]] % P * Invk) % P;
		}
	}

	int sufc = 0;
	for (int i = n; i; --i) {
		if (a[i] == -1) {
			++sufc;
		} else {
			ans = (ans + 1ll * sufc * pre[a[i]] % P * Invk) % P;
		}
	}
	
	ans = (ans + (1ll * k * (k - 1) / 2) % P * Inv2) % P;
	std::cout << ans << std::endl;
}