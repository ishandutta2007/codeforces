/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS 
#define ANDREIKKAA_CALL 
#define ANDREIKKAA_RETURN_TYPE void
#define fori(i, n) for(auto i = 0; i < n; ++i)
#define forn(n) for(auto _ = 0; _ < n; ++_)
#define forr(i, s, f) for(auto i = s; i < f; ++i)
#define alll(a) a.begin(), a.end()

typedef long long ll;
typedef long double ld;
const int MEMORY_LIMIT_MB = 50;
const int TIME_LIMIT_S = 1;
const char input_filename[] =
#if defined(ANDREIKKAA)
//""
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

/* ______ INCLUDES ______ */
#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/* _____ ALLOCATION _____ */

#if defined(ANDREIKKAA_ALLOCATOR)
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x) { alloc_pointer += x; return alloc_memory + alloc_pointer - x; }
inline void operator delete(void*) { }
#endif

/*____ I-O OPERATORS ____*/
template<typename T, typename U> inline ostream &operator<<(ostream &out, const pair<T, U> &p) { out << p.first << ' ' << p.second; return out; }
template<typename T, typename U> inline istream &operator >> (istream &in, pair<T, U> &p) { in >> p.first >> p.second; return in; }
template<typename T> inline ostream &operator<<(ostream &out, const vector<T> &v) { if (v.empty()) return out; out << v.front(); for (auto it = ++v.begin(); it != v.end(); ++it) out << ' ' << *it; return out; }
template<typename T> inline istream &operator >> (istream &in, vector<T> &v) { for (auto &i : v) in >> i; return in; }

/* _______ INPUT _________*/
class Reader
{
public:
	inline Reader(const string &filename) { if (not filename.empty()) assert(freopen(filename.c_str(), "r", stdin) != nullptr); }
	template<typename T> inline void operator()(T &x) { cin >> x; }
	template<typename T, typename... Args> inline void operator()(T &x, Args &... args) { operator()(x), operator()(args...); }
	template<typename T> inline T r() { T x; cin >> x; return x; }
};
Reader rd(input_filename);

/* _______ OUTPUT ________*/

class Printer
{
public:
	inline Printer(const string &filename) { if (not filename.empty()) assert(freopen(filename.c_str(), "w", stdout) != nullptr); }
	template<typename T> inline void p(const T x) { cout << x; }
	template<typename T, typename... Args> inline void p(const T x, const Args... args) { p(x), p(args...); }
	inline void operator()() { p('\n'); }
	template<typename T> inline void operator()(const T x) { p(x), p('\n'); }
	template<typename T, typename... Args> inline void operator()(const T x, const Args... args) { p(x), p(' '), operator()(args...); };
	inline void f() { cout.flush(); }
};
Printer pr(output_filename);

/* ________ CODE ________ */

const int N = 1002;
const int LN = 10;
int l2[N];
int sp[LN][N][LN][N];
int a[N][N];

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{	
	l2[0] = -1;
	forr (i, 1, N)
	{
		l2[i] = l2[i - 1] + ((i & (i - 1)) == 0);
	}

	int n, m;
	rd(n, m);

	forr(i, 1, n + 1)
	{
		forr(j, 1, m + 1)
		{
			rd(a[i][j]);
		}
	}

	for (int i = n; i >= 1; --i)
	{
		for (int j = m; j >= 1; --j)
		{
			if (a[i][j] == 0)
			{
				continue;
			}
			a[i][j] += min({ a[i + 1][j], a[i][j + 1], a[i + 1][j + 1] });
			sp[0][i][0][j] = a[i][j];
		}
	}

	for (int xp = 0; (1 << xp) <= n; ++xp)
	{
		for (int x = 1; x + (1 << xp) - 1 <= n; ++x)
		{
			if (xp > 0)
			{
				for (int y = 1; y <= m; ++y)
				{
					sp[xp][x][0][y] = max(sp[xp - 1][x][0][y], sp[xp - 1][x + (1 << (xp - 1))][0][y]);
				}
			}
			
			for (int yp = 1; (1 << yp) <= m; ++yp)
			{
				for (int y = 1; y + (1 << yp) - 1 <= m; ++y)
				{
					sp[xp][x][yp][y] = max(sp[xp][x][yp - 1][y], sp[xp][x][yp - 1][y + (1 << (yp - 1))]);
				}
			}
		}
	}

	int t;
	rd(t);

	forn(t)
	{
		int x1, y1, x2, y2;
		rd(x1, y1, x2, y2);

		int l = 0;
		int sz = min(y2 - y1 + 1, x2 - x1 + 1);
		int r = sz + 1;

		while (l != r)
		{
			int m = (l + r) / 2;
			int lgx = l2[x2 - x1 + 1 - m + 1];
			int lgy = l2[y2 - y1 + 1 - m + 1];

			if (max({ sp[lgx][x1][lgy][y1], sp[lgx][x2 - m + 1 - (1 << lgx) + 1][lgy][y1],
			sp[lgx][x1][lgy][y2 - m + 1 - (1 << lgy) + 1], sp[lgx][x2 - m - (1 << lgx) + 2][lgy][y2 - m + 1 - (1 << lgy) + 1] }) >= m)
			{
				l = m + 1;
			}
			else
			{
				r = m;
			}
		}
		pr(l - 1);
	}
}

class ANDREIKKAA_CLASS
{
public:
	ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS)
	{
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		//cout << setprecision(20);
		//cout << fixed;
		return mainFunction(ANDREIKKAA_CALL);
	}
#if defined(ANDREIKKAA)
	inline ANDREIKKAA_CLASS() { _start = clock(); }
	inline ~ANDREIKKAA_CLASS() { cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl; }
private:
	time_t _start;
#endif
};

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
	auto _s = new ANDREIKKAA_CLASS; _s->ANDREIKKAA_METHOD(ANDREIKKAA_CALL); delete _s;
#if defined(ANDREIKKAA)
	while (true);
#endif
}
#endif