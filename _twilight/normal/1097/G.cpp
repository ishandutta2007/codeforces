#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

typedef vector<int> Poly;

ostream& operator << (ostream& os, const Poly& a) {
	for (auto x : a)
		os << x << ' ';
	os << '\n';
	return os;
}

const int Mod = 1e9 + 7;

int n, K;
int S[205][205];
vector<int> G[100005];

void inc(int& x) {
	if (x >= Mod)
		x -= Mod;
}
void dec(int& x) {
	if (x < 0)
		x += Mod;
}

Poly operator + (Poly a, Poly b) {
	if (a.size() < b.size())
		a.resize(b.size());
	for (int i = (signed) b.size() - 1; ~i; i--)
		inc(a[i] += b[i]);
	return a;
}
Poly operator * (Poly a, Poly b) {
	int n = (signed) a.size(), m = (signed) b.size();
	Poly c (min(n + m - 1, K + 1), 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m && i + j <= K; j++) {
			c[i + j] = (c[i + j] + 1ll * a[i] * b[j]) % Mod;
		}
	}
	return c;
}

typedef class dp_t {
	public:
		Poly f, g;

		dp_t(int p, int fa) {
			for (auto e : G[p]) {
				if (e ^ fa) {
					dp_t t(e, p);
					f = (f + g) * (t.f + t.g) + t.f + f;
					g = g + t.g;
				}
			}
			f = f * Poly{2} + g + Poly{1};
			if (fa)
				g = g * Poly{1, 1} + f * Poly{0, 1};
		}
} dp_t;

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	S[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		S[i][0] = 0, S[i][i] = 1;
		for (int j = 1; j < i; j++) {
			S[i][j] = (1ll * S[i - 1][j] * j + S[i - 1][j - 1]) % Mod;
		}
	}
	dp_t d (1, 0);
	int fac = 1, ans = 0;
	for (int i = 0; i <= K && i < (signed) d.f.size(); i++) {
		ans = (ans + 1ll * S[K][i] * fac % Mod * d.f[i]) % Mod;
		fac = 1ll * fac * (i + 1) % Mod;
	}
	printf("%d\n", ans);
	return 0;
}