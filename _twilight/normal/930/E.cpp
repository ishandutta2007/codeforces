#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int Mod = 1e9 + 7;

#define ll long long

typedef class Zi {
	public:
		int v;
		
		Zi() : v(0) {	}
		Zi(int x) : v(x) {	}
		Zi(ll x) : v(x % Mod) { }

		friend Zi operator + (Zi a, Zi b) {
			return (((a.v += b.v) >= Mod) ? (a.v -= Mod) : (a.v));
		}	
		friend Zi operator - (Zi a, Zi b) {
			return (((a.v -= b.v) < 0) ? (a.v += Mod) : (a.v));
		}
		friend Zi operator * (Zi a, Zi b) {
			return a.v * 1ll * b.v;
		}
} Zi;

Zi qpow(Zi a, int p) {
	Zi rt = 1;
	for ( ; p; p >>= 1, a = a * a) {
		if (p & 1) {
			rt = rt * a;
		}
	}
	return rt;
}

typedef class Segment {
	public:
		int l, r;

		Segment(int l, int r) : l(l), r(r) {	}

		boolean operator < (Segment b) const {
			return (l ^ b.l) ? (l > b.l) : (r < b.r);
		}
} Segment;

const int N = 4e5 + 5;

int K, n, m;
vector<int> B;
vector<Segment> a0, a1, _a0, _a1;

void remove_inclusion(vector<Segment>& a, vector<Segment>& b) {
	sort(a.begin(), a.end());
	int r = K + 1;
	for (auto s : a) {
		if (s.r < r) {
			b.push_back(s);
			r = s.r;
		}
	}
	reverse(b.begin(), b.end());
}

int id0[N], id1[N];
Zi f[N], g0[N], g1[N];
int main() {
	scanf("%d%d%d", &K, &n, &m);
	for (int i = 1, l, r; i <= n; i++) {
		scanf("%d%d", &l, &r);
		_a0.emplace_back(l, r);
	}
	for (int i = 1, l, r; i <= m; i++) {
		scanf("%d%d", &l, &r);
		_a1.emplace_back(l, r);
	}
	remove_inclusion(_a0, a0);
	remove_inclusion(_a1, a1);
	B.push_back(0);
	for (auto s : a0) {
		B.push_back(s.l - 1);
		B.push_back(s.r);
	}
	for (auto s : a1) {
		B.push_back(s.l - 1);
		B.push_back(s.r);
	}
	B.push_back(K);
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	int t = B.size();
	memset(id0, -1, sizeof(id0));
	memset(id1, -1, sizeof(id1));
	int idx = 0;
	for (auto& s : a0) {
		s.l = lower_bound(B.begin(), B.end(), s.l - 1) - B.begin();
		s.r = lower_bound(B.begin(), B.end(), s.r) - B.begin();
		id0[s.r] = idx++;
	}
	idx = 0;
	for (auto& s : a1) {
		s.l = lower_bound(B.begin(), B.end(), s.l - 1) - B.begin();
		s.r = lower_bound(B.begin(), B.end(), s.r) - B.begin();
		id1[s.r] = idx++;
	}
	f[0] = 1;
	for (int i = 1, x; i < t; i++) {
		f[i] = f[i - 1] * qpow(2, B[i] - B[i - 1]);
		if (~(x = id0[i])) {
			Segment& s = a0[x];
			g0[i] = (g0[s.l] - g0[i - 1]) - f[s.l];
			f[i] = f[i] + g0[i];
		}
		if (~(x = id1[i])) {
			Segment& s = a1[x];
			g1[i] = g1[s.l] - g1[i - 1] - f[s.l];
			f[i] = f[i] + g1[i];
		}
		g0[i] = g0[i] + g0[i - 1];
		g1[i] = g1[i] + g1[i - 1];
	}
	printf("%d\n", f[t - 1].v);
	return 0;
}