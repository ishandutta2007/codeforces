#include <bits/stdc++.h>
using namespace std;
//Fast IO start
namespace io {
	const int BUFSIZE = 1 << 20;
	char ibuf[BUFSIZE + 1], *is = ibuf, *it = ibuf;
	char obuf[BUFSIZE + 1], *os = obuf, *ot = obuf + BUFSIZE;
	inline char read_char() {
		if (is == it) {
			it = (is = ibuf) + fread(ibuf, 1, BUFSIZE, stdin);
			if (is == it) *it++ = EOF;
		}
		return *is++;
	}
	template <class T>
	inline void read_int(T &x) {
		T f = 1;
		char c = read_char();
		while (!isdigit(c)) {
			if (c == '-') f = -1;
			c = read_char();
		}
		x = 0;
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = read_char();
		}
		x *= f;
	}
	inline void read_str(char *s) {
		char c = read_char();
		while (c <= ' ') {
			c = read_char();
		}
		while (c > ' ') {
			*s++ = c;
			c = read_char();
		}
		*s = 0;
	}
	inline void flush() {
		fwrite(obuf, 1, os - obuf, stdout);
		os = obuf;
	}
	inline void print_char(char c) {
		*os++ = c;
		if (os == ot) {
			flush();
		}
	}
	template <class T>
	inline void print_int(T x, char c = 0) {
		static char q[40];
		if (!x) {
			print_char('0');
		} else {
			if (x < 0) {
				print_char('-');
				x = -x;
			}
			int top = 0;
			while (x) {
				q[top++] = x % 10 + '0';
				x /= 10;
			}
			while (top--) {
				print_char(q[top]);
			}
		}
		if (c) print_char(c);
	}
	inline void print_str(char *s, char c = 0) {
		while (*s) {
			print_char(*s++);
		}
		if (c) print_char(c);
	}
	struct flusher_t {
		inline ~flusher_t() {
			flush();
		}
	} flusher;
}
using io::read_char;
using io::read_int;
using io::read_str;
using io::print_char;
using io::print_int;
using io::print_str;
//Fast IO end
const int N = 200005;
const int V = 1000005;
struct BIT {
	long long bit[V];
	inline void add(int i, long long x) {
		i++;
		while (i < V) {
			bit[i] += x;
			i += i & -i;
		}
	}
	inline long long sum(int i) {
		i++;
		long long ret = 0;
		while (i > 0) {
			ret += bit[i];
			i -= i & -i;
		}
		return ret;
	}
} b0, b1;
int n, m, Q, a[N], b[N];
multiset<int> sta, stb;
inline long long query(int x) {
	long long c0 = b0.sum(x), c1 = b1.sum(x);
	return c1 + (m - c0) * x;
}
int main() {
	read_int(n);
	read_int(m);
	read_int(Q);
	long long dlt = 0;
	for (int i = 1; i <= n; i++) read_int(a[i]), sta.insert(a[i]), dlt += a[i];
	for (int i = 1; i <= m; i++) read_int(b[i]), stb.insert(b[i]), b0.add(b[i], 1), b1.add(b[i], b[i]), dlt -= b[i];
	while (Q--) {
		int ty;
		read_int(ty);
		if (ty == 1) {
			int pos, x;
			read_int(pos);
			read_int(x);
			sta.erase(sta.find(a[pos]));
			dlt += x - a[pos];
			a[pos] = x;
			sta.insert(a[pos]);
		} else if (ty == 2) {
			int pos, x;
			read_int(pos);
			read_int(x);
			stb.erase(stb.find(b[pos]));
			dlt -= x - b[pos];
			b0.add(b[pos], -1);
			b1.add(b[pos], -b[pos]);
			b[pos] = x;
			b0.add(b[pos], 1);
			b1.add(b[pos], b[pos]);
			stb.insert(b[pos]);
		} else {
			int x;
			read_int(x);
			long long ans = -1e18;
			int mn = min(*sta.begin(), *stb.begin()), mxb = *stb.rbegin();
			ans = max(ans, query(mxb - x) - 1ll * n * min(mn, mxb - x));
			ans = max(ans, 1ll * (m - n) * (mn - x));
			auto it = sta.lower_bound(mxb + x);
			if (it != sta.end())
				ans = max(ans, query((*it) - x) - ((*it) - x) - 1ll * (n - 1) * min(mn, (*it) - x));
			if (it != sta.begin()) {
				--it;
				ans = max(ans, query((*it) - x) - ((*it) - x) - 1ll * (n - 1) * min(mn, (*it) - x));
			}
			ans += dlt;
			print_int(ans, '\n');
		}
	}
	return 0;
}