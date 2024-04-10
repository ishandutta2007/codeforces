#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

class FastInput {
	bool _end;
public:
	FastInput() : _end(false) {}

	operator void*() { return _end ? 0 : (void*)this; }

	template<typename T>
	void read_signed(T *res) {
		char c = skip();
		bool sign = false;
		if(c == '-') sign = true, c = gc();
		T x = 0;
		for(; '0' <= c && c <= '9'; c = gc())
			x = x * 10 + (c - '0');
		*res = !sign ? x : -x;
	}

	FastInput &operator()(int &res) { read_signed(&res); return *this; }

private:
	static char gc() {
#if defined(__GNUC__) && !defined(__MINGW32__)
		return (char)getchar_unlocked();
#elif defined(_MSC_VER)
		return (char)_getchar_nolock();
#else
		return (char)getchar();
#endif
	}

	static bool is_delim(char c) {
		return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == EOF;
	}

	char skip() {
		if(_end) return EOF;
		char c;
		for(c = gc(); c != -1 && is_delim(c); c = gc());
		if(c == EOF) _end = true;
		return c;
	}
} in;

class FastOutput {
public:
	template<typename T>
	void print_signed(T x) {
		char buf[24]; int n = 0; bool sign = false;
		if(x < 0) sign = true;
		//depends on the -x % y behaviour
		do buf[n ++] = x % 10, x /= 10; while(x != 0);
		if(!sign) {
			while(n > 0) pc('0' + buf[-- n]);
		} else {
			pc('-');
			while(n > 0) pc('0' - buf[-- n]);
		}
	}

	void print_char(char x) {
		pc(x);
	}

	FastOutput &operator()(char x) { print_char(x); return *this; }
	FastOutput &operator()(int x) { print_signed(x); return *this; }

private:
	static void pc(char c) {
#if defined(__GNUC__) && !defined(__MINGW32__)
		putchar_unlocked(c);
#elif defined(_MSC_VER)
		_putchar_nolock(c);
#else
		putchar(c);
#endif
	}
} out;

class SparseTable2D {
public:
	enum { N = (1000 + 7) / 8 * 8, LogN = 10 };
	typedef short Val;
	alignas(16) Val table[LogN + 1][LogN + 1][N + 8][N + 8];

	template<typename Array>
	void init(int n, int m, const Array &a) {
		int lgn = log2i(n), lgm = log2i(m);
		rep(y, n) rep(x, m)
			table[0][0][y][x] = a[y][x];
		for(int j = 1; j <= lgm; ++ j) {
			int w = m - (1 << j) + 1;
			rep(y, n)
				max_vector(table[0][j][y], table[0][j - 1][y], table[0][j - 1][y] + (1 << (j - 1)), w);
		}
		for(int i = 1; i <= lgn; ++ i) for(int j = 0; j <= lgm; ++ j) {
			int h = n - (1 << i) + 1, w = m - (1 << j) + 1;
			rep(y, h)
				max_vector(table[i][j][y], table[i - 1][j][y], table[i - 1][j][y + (1 << (i - 1))], w);
		}
	}

	//[yL,yR] x [xL,xR]
	Val query(int yL, int xL, int yR, int xR) const {
		int lgy = log2i(yR - yL + 1);
		int lgx = log2i(xR - xL + 1);
		const auto &v = table[lgy][lgx];
		yR -= (1 << lgy) - 1;
		xR -= (1 << lgx) - 1;
		return mymax(mymax(v[yL][xL], v[yL][xR]), mymax(v[yR][xL], v[yR][xR]));
	}

private:
	static void max_vector(Val *dst, const Val *src1, const Val *src2, int n) {
		if(((intptr_t)src2 & 15) == 0) {
			for(int i = 0; i < n; i += 8) {
				auto x = _mm_load_si128((const __m128i*)(src1 + i));
				auto y = _mm_load_si128((const __m128i*)(src2 + i));
				auto z = _mm_max_epi16(x, y);
				_mm_store_si128((__m128i*)(dst + i), z);
			}
		} else {
			for(int i = 0; i < n; i += 8) {
				auto x = _mm_load_si128((const __m128i*)(src1 + i));
				auto y = _mm_loadu_si128((const __m128i*)(src2 + i));
				auto z = _mm_max_epi16(x, y);
				_mm_store_si128((__m128i*)(dst + i), z);
			}
		}
	}

	static Val mymax(Val x, Val y) {
		return x < y ? y : x;
	}

	static int log2i(uint32_t n) {
		return bsr(n);
	}

	static int bsr(uint32_t x) {
#if defined(__GNUC__)
		return 31 - __builtin_clz(x);
#else
		int r = 0;
		if(x & 0xffff0000U) x >>= 16, r += 16;
		if(x & 0xff00U) x >>= 8, r += 8;
		if(x & 0xf0U) x >>= 4, r += 4;
		if(x & 0xcU) x >>= 2, r += 2;
		if(x & 0x2U) r += 1;
		return r;
#endif
	}
};

int main() {
	int n; int m;
	while(in(n)(m)) {
		vector<vector<int> > a(n, vector<int>(m));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j)
			in(a[i][j]);
		vector<vector<short>> dp(n + 1, vector<short>(m + 1));
		for(int i = n - 1; i >= 0; -- i)
			for(int j = m - 1; j >= 0; -- j)
				dp[i][j] = a[i][j] == 0 ? 0 : min({ dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1] }) + 1;
		static SparseTable2D st2d;
		st2d.init(n, m, dp);
		int q;
		in(q);
		rep(ii, q) {
			int yL, xL, yR, xR;
			in(yL)(xL)(yR)(xR), -- yL, -- xL;
			int lo = 0, up = min(yR - yL, xR - xL);
			while(up - lo > 0) {
				int mid = (lo + up + 1) / 2;
				int val = st2d.query(yL, xL, yR - mid, xR - mid);
				if(val >= mid)
					lo = mid;
				else
					up = mid - 1;
			}
			out(lo)('\n');
		}
	}
	return 0;
}