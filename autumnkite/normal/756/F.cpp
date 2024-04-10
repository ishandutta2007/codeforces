#include <bits/stdc++.h>

const int P = 1000000007;

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

struct state {
	int l, r;
	int v;
	int c;
	int w;
	
	state() : l(0), r(0), v(0), c(0) {}
	state(int _l, int _r, int _v, int _c, int _w) : l(_l), r(_r), v(_v), c(_c), w(_w) {}
};

state plus(state a, state b) {
	return state(-1, -1, (1ll * a.v * qpow(10, b.c) + b.v) % P, (a.c + b.c) % (P - 1), (a.w + b.w) % P);
}

int as(int n) {
	return 1ll * n * (n - 1) % P * qpow(2, P - 2) % P;
}

int gs(int a, int n, int c) {
	if (a == 1) {
		return c;
	} else {
		return 1ll * (qpow(a, n) + P - 1) * qpow((P + a - 1) % P, P - 2) % P;
	}
}

int ags(int a, int n, int c) {
	if (a == 1) {
		return as(c);
	} else {
		int an = qpow(a, n);
		int inv = qpow((P + a - 1) % P, P - 2);
		return (1ll * c * an + 1ll * (P - a) * (an + P - 1) % P * inv) % P * inv % P;
	}
}

state solve(std::string x) {
	int n = x.size();
	state res(-1, -1, 0, 0, 0);
	int c = 1, w = 1;
	for (int i = 1; i < n; ++i) {
		state tmp(-1, -1, 0, 9ll * c % (P - 1) * i % (P - 1), 9ll * w % P * i % P);
		tmp.v = 1ll * qpow(10ll * w % P, (P + 10ll * c - 2) % (P - 1)) * ags(qpow(10ll * w % P, P - 2), 10ll * c % (P - 1), 10ll * w % P) % P;
		tmp.v = (tmp.v + 1ll * qpow(10ll * w % P, (P + 10ll * c - 2) % (P - 1)) * (P - ags(qpow(10ll * w % P, P - 2), c, w)) % P) % P;
		res = plus(res, tmp);
		c = 10ll * c % (P - 1);
		w = 10ll * w % P;
	}
	int xc = 0, xw = 0;
	for (int i = 0; i < n; ++i) {
		xc = (10ll * xc + x[i] - '0') % (P - 1);
		xw = (10ll * xw + x[i] - '0') % P;
	}
	state tmp(-1, -1, 0, 1ll * (xc + P - 1 - c) * n % (P - 1), 1ll * (xw + P - w) % P * n % P);
	tmp.v = 1ll * qpow(10ll * w % P, (P + xc - 2) % (P - 1)) * ags(qpow(10ll * w % P, P - 2), xc, xw) % P;
	tmp.v = (tmp.v + 1ll * qpow(10ll * w % P, (P + xc - 2) % (P - 1)) * (P - ags(qpow(10ll * w % P, P - 2), c, w)) % P) % P;
	res = plus(res, tmp);
	return res;
}

state minus(std::string a, std::string b) {
	int p = (int)b.size() - 1;
	while (p >= 0 && b[p] == '9') {
		b[p] = '0';
		--p;
	}
	if (p == -1) {
		b = '1' + b;
	} else {
		++b[p];
	}
	
	state sa = solve(a), sb = solve(b);
	int c = (sb.c - sa.c + P - 1) % (P - 1);
	return state(-1, -1, (1ll * (P - sa.v) * qpow(10, c) + sb.v) % P, 
	             c, (sb.w - sa.w + P) % P);
}

state mul(state a, state b) {
	return state(-1, -1, 1ll * b.v * gs(qpow(10, b.c), a.c, a.w) % P, 
	             1ll * a.c * b.c % (P - 1), 1ll * a.w * b.w % P);
}

int main() {
	std::string s;
	std::cin >> s;
	s = '(' + s + ')';

	auto calc = [&](state a, state b, int op) {
		if (op == 2) {
			return mul(a, b);
		} else if (op == 0) {
			return plus(a, b);
		} else {
			return minus(s.substr(a.l, a.r - a.l), s.substr(b.l, b.r - b.l));
		}
	};

	int l = 0, r = 0, v = 0;
	std::vector<state> sta;
	std::vector<int> op;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (isdigit(s[i])) {
			++r;
			v = (10ll * v + s[i] - '0') % P;
		} else {
			if (s[i] != '(') {
				if (l < r) {
					sta.emplace_back(l, r, v, r - l, r - l);
				}
			} else if (l < r) {
				int t = 0;
				for (int j = l; j < r; ++j) {
					t = (10ll * t + s[j] - '0') % (P - 1);
				}
				sta.emplace_back(-1, -1, -1, t, v);
			} else {
				sta.emplace_back(-1, -1, -1, 1, 1);
			}
			l = i + 1, r = i + 1, v = 0;
			if (s[i] != ')') {
				int t = s[i] == '(' ? 2 : (s[i] == '+' ? 0 : 1);
				while (!op.empty() && op.back() != 2 && op.back() >= t) {
					state tmp = calc(sta[sta.size() - 2], sta[sta.size() - 1], op.back());
					sta.pop_back();
					sta.back() = tmp;
					op.pop_back();
				}
				op.push_back(t);
			} else {
				int lst = -1;
				while (!op.empty() && lst != 2) {
					state tmp = calc(sta[sta.size() - 2], sta[sta.size() - 1], op.back());
					lst = op.back();
					sta.pop_back();
					sta.back() = tmp;
					op.pop_back();
				}
			}
		}
	}
	std::cout << sta[0].v << "\n";
}