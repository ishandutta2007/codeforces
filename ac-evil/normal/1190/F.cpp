#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)

inline ll inc(ll a, ll b, ll p) {
	a += b;
	return a >= p ? a-p : a;
}

inline ll Mult(ll a, ll b, ll p) {
	ll c = a*b-(ll)((unsigned ll)((long double)a*b/p)*p);
	return c < 0 ? c+p : (c >= p ? c-p : c);
}

inline ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	for (register ll k = a; b; k = Mult(k, k, p), b >>= 1)
		if (b & 1) res = Mult(res, k, p);
	return res;
}

inline ll f(ll x, ll c, ll p) { return inc(Mult(x, x, p), c, p); }

int test[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
bool MR(ll P) {
	if (P <= 1) return false;
	ll s = P-1; int t = 0;
	while (!(s & 1)) s >>= 1, t++;
	rep(i, 0, 9) {
		if (P == test[i]) return true;
		else if (test[i] >= P) return false;
		ll a = qpow(test[i], s, P), nxt;
		rep(x, 1, t) {
			nxt = Mult(a, a, P);
			if (nxt == 1 && a != 1 && a != P-1) return false;
			a = nxt;
			if (a == 1) break;
		}
		if (a != 1) return false;
	}
	return true;
}

ll gcd(ll a, ll b) {
	if (!a || !b) return a ^ b;
	register ll t;
	while (t = a%b) a = b, b = t;
	return b;
}

ll Floyd(ll N) {
	ll c = rand() & 15, s = 1, t = f(s, c, N);
	for (;;) {
		ll _s = s, _t = t, prod = 1;
		rep(i, 1, 128) prod = Mult(prod, abs(_s - _t), N), _s = f(_s, c, N), _t = f(f(_t, c, N), c, N);
		ll d = gcd(prod, N);
		if (d == 1) { s = _s, t = _t; continue; }
		rep(i, 1, 128) {
			if ((d = gcd(abs(s-t), N)) != 1) return d;
			s = f(s, c, N), t = f(f(t, c, N), c, N);
		}
	}
}

vector<ll> fac;

ll PR(ll N) {
	if (N <= 1) return 0;
	if (MR(N)) {
		fac.push_back(N);
		return N;
	}
	ll ans;
	while ((ans = Floyd(N)) == N);
	return PR(ans), PR(N/ans);
}

int N;
ll M, P, base, phi, g, ord;

int main() {
	MR(3);
	scanf("%d%lld%lld", &N, &M, &P);
	base = PR(M), phi = M/base*(base-1);
	fac.clear(); PR(phi);
	//printf("%d\n", g);
	ord = phi;
	if (gcd(M, P) != 1) ord = 1;
	else rep(i, 0, (int)fac.size()-1) {
		while (!(ord % fac[i]) && qpow(P, ord/fac[i], M) == 1) ord /= fac[i];
	}
	
	if (!(M & 1) && M > 4) {
		if (N > phi-ord) { printf("-1"); return 0; }
		if (gcd(M, P) != 1) {
			for (ll i = 3; N; i += 2) printf("%d ", i), N--;
		}
		else if (P % 4 == 1) {
			ll k = (P-1)/4, d = phi/2/ord, p = 0;
			for (ll i = 1; N; i += 2) {
				if (i % 4 == 1) { if (p % d) printf("%d ", i), N--; }
				else printf("%d ", i), N--, p++;
			}
		} else {
			ll inv = qpow(P, M/2-1, M), k = (Mult(P, P, M)-1) / 4, d = phi/ord, p = 0;
			for (ll i = 1; N; i += 2) {
				if (i % 4 == 1) {
					if (p % d) printf("%d ", i), N--;
				} else {
					if ((Mult(i, inv, M)-1)/4 % d) printf("%d ", i), N--;
					p++;
				}
			}
		}
		return 0;
	}

	for (g = 1; ; g++) {
		int ok = 0;
		if (gcd(g, M) != 1) continue;
		rep(i, 0, (int)fac.size()-1) if (qpow(g, phi/fac[i], M) == 1) { ok = 1; break; }
		if (!ok) break;
	}

	if (N > phi-ord) printf("-1\n");
	else {
		ll w = g, t = 1;
		while (N) {
			if (t % (phi/ord)) printf("%lld ", w), N--;
			w = Mult(w, g, M), t++;
		}
	}
	//printf("%d\n", ord);
	return 0;
}