#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;
#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

using namespace std;

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
void reader(string& s) { static char buf[1000000 * 3]; reader(buf); s = buf; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }


// 01rbg
inline void convert(uint32_t *ptr, const string &s){
	const int n = s.size();
	for (int i = 0; i < n; ++i) {
		ptr[i >> 5] |= static_cast<uint32_t>(s[i] - '0') << (i & 31);
	}
}

#ifndef _MSC_VER
static inline int32_t __attribute__((always_inline))
mm_popcnt_u32(uint32_t x){
	int32_t result;
	__asm__("popcnt %1, %0" : "=r" (result) : "r" (x));
	return result;
}
#else
#	define mm_popcnt_u32 _mm_popcnt_u32
#endif


static uint32_t a[6400];
static uint32_t b[32][6400];

int main(){
	// EtH[}bg
	string a_str, b_str;
	reader(a_str, b_str);
	convert(a, a_str);
	convert(b[0], b_str);
	// b  [1, 31] rbgp
	for (int i = 1; i < 32; ++i) {
		const int m = (b_str.size() + 31) / 32;
		b[i][0] = (b[i - 1][0] << 1);
		for (int j = 1; j <= m; ++j) {
			b[i][j] = (b[i - 1][j] << 1) | (b[i - 1][j - 1] >> 31);
		}
	}
	// NG
	int q;
	reader(q);
	while (q--) {
		int p1, p2, len;
		reader(p1, p2, len);
		// ab (MOD 64) 
		const int k = (32 - ((p2 - p1) & 31)) & 31;
		const uint32_t *s = a + (p1 >> 5);
		const uint32_t *t = b[k] + ((p2 + k) >> 5);
		const int offset = p1 & 31;
		int answer = 0;
		if (offset + len < 32) {
			// 32bitn[I[
			const uint32_t mask =
				((1u << (offset + len)) - 1) &
				~((1u << offset) - 1);
			answer = mm_popcnt_u32((*s ^ *t) & mask);
		} else {
			// n[
			const uint32_t hmask = ~((1u << offset) - 1);
			answer += mm_popcnt_u32((*s ^ *t) & hmask);
			len -= (32 - offset); ++s; ++t;
			// 
			while (len >= 32) {
				answer += mm_popcnt_u32(*s ^ *t);
				len -= 32; ++s; ++t;
			}
			// I[
			const uint64_t tmask = (1u << len) - 1;
			answer += mm_popcnt_u32((*s ^ *t) & tmask);
		}
		writerLn(answer);
	}
	return 0;
}