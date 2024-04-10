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
#define fori(i, n) for(auto i = 0; i < (n); ++i)
#define forn(n) for(auto _ = 0; _ < (n); ++_)
#define forr(i, s, f) for(auto i = s; i < f; ++i)

typedef long long ll;
typedef long double ld;
const int MEMORY_LIMIT_MB = 200;
const int TIME_LIMIT_S = 1;
const char input_filename[] =
#if defined(ANDREIKKAA)
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

const int MAX = 1002;
int t[MAX][MAX];
pair<int, int> dw[MAX][MAX];
pair<int, int> r[MAX][MAX];

pair<int, int> f(int x, int y)
{
	int a = 0;
	int b = 0;
	forn(x)
	{
		tie(a, b) = make_tuple(dw[a][b].first, dw[a][b].second);
	}
	forn(y)
	{
		tie(a, b) = make_tuple(r[a][b].first, r[a][b].second);
	}
	return{ a, b };
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, m, q;
	rd(n, m, q);

	forr(i, 0, n + 1)
	{
		forr(j, 0, m + 1)
		{
			if(i * j)
				rd(t[i][j]);
			dw[i][j] = { i + 1, j };
			r[i][j] = { i, j + 1 };
		}
	}

	vector<vector<int>> v(n, vector<int>(m));
	forn(q)
	{
		int a, b, c, d, h, w;
		rd(a, b, c, d, h, w);

		auto l1 = f(a, b - 1);
		auto u1 = f(a - 1, b);
		auto r1 = f(a, b + w - 1);
		auto d1 = f(a + h - 1, b);

		auto l2 = f(c, d - 1);
		auto u2 = f(c - 1, d);
		auto r2 = f(c, d + w - 1);
		auto d2 = f(c + h - 1, d);

		forn(h)
		{
			swap(r[l1.first][l1.second], r[l2.first][l2.second]);
			swap(r[r1.first][r1.second], r[r2.first][r2.second]);
			tie(l1.first, l1.second) = make_tuple(dw[l1.first][l1.second].first, dw[l1.first][l1.second].second);
			tie(r1.first, r1.second) = make_tuple(dw[r1.first][r1.second].first, dw[r1.first][r1.second].second);
			tie(l2.first, l2.second) = make_tuple(dw[l2.first][l2.second].first, dw[l2.first][l2.second].second);
			tie(r2.first, r2.second) = make_tuple(dw[r2.first][r2.second].first, dw[r2.first][r2.second].second);
		}

		forn(w)
		{
			swap(dw[u1.first][u1.second], dw[u2.first][u2.second]);
			swap(dw[d1.first][d1.second], dw[d2.first][d2.second]);
			tie(u1.first, u1.second) = make_tuple(r[u1.first][u1.second].first, r[u1.first][u1.second].second);
			tie(d1.first, d1.second) = make_tuple(r[d1.first][d1.second].first, r[d1.first][d1.second].second);
			tie(u2.first, u2.second) = make_tuple(r[u2.first][u2.second].first, r[u2.first][u2.second].second);
			tie(d2.first, d2.second) = make_tuple(r[d2.first][d2.second].first, r[d2.first][d2.second].second);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		auto l1 = f(i, 1);
		for (int j = 1; j <= m; ++j)
		{
			pr.p(t[l1.first][l1.second], ' ');
			tie(l1.first, l1.second) = make_tuple(r[l1.first][l1.second].first, r[l1.first][l1.second].second);
		}
		pr();
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