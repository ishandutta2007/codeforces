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
//#define ANDREIKKAA_UNSAFE_VECTOR

#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void

#ifdef ANDREIKKAA_UNSAFE_VECTOR
#define vec vector
#endif // ANDREIKKAA_UNSAFE_VECTOR

typedef long long ll;
typedef long double ld;

const int MEMORY_LIMIT_MB = 200;
const int TIME_LIMIT_S = 1;

const char input_filename[] =
#ifdef ANDREIKKAA
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#ifdef ANDREIKKAA
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
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctgmath>
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

#ifdef ANDREIKKAA_ALLOCATOR
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x)
{
	alloc_pointer += x;
return alloc_memory + alloc_pointer - x;
}
inline void operator delete(void*)
{
	
}
#endif

/*_______ TYPES ________*/

#ifndef ANDREIKKAA_UNSAFE_VECTOR
template<typename T> class vec : public vector<T>
{ public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const { return this->at(x); }
	inline T& operator[](size_t x) { return this->at(x); }
};

template<> class vec<bool> : public vector<bool>
{ public:
	using vector<bool>::vector;
	inline const_reference operator[](size_t x) const { return this->at(x); }
	inline reference operator[](size_t x) { return this->at(x); }
};
#endif // !ANDREIKKAA_UNSAFE_VECTOR

/*____ I-O OPERATORS ____*/

template<typename T, typename U> inline ostream &operator<<(ostream &out, const pair<T, U> &p) { out << p.first << ' ' << p.second; return out; }
template<typename T, typename U> inline istream &operator>>(istream &in, pair<T, U> &p) { in >> p.first >> p.second; return in; }
template<typename T> inline ostream &operator<<(ostream &out, const vector<T> &v) { if (v.empty()) return out; out << v.front(); for (auto it = ++v.begin(); it != v.end(); ++it) out << ' ' << *it; return out; }
template<typename T> inline istream &operator>>(istream &in, vector<T> &v) { for (auto &i : v) in >> i; return in; }

/* _______ INPUT _________*/

class Reader
{ public:
	inline Reader(const string &filename) { if (not filename.empty()) assert(freopen(filename.c_str(), "r", stdin) != nullptr); }
	template<typename T> inline void operator()(T &x) { cin >> x; }
	template<typename T, typename... Args> inline void operator()(T &x, Args &... args) { operator()(x), operator()(args...); }
	template<typename T> inline T r() { T x; cin >> x; return x; }
};
Reader rd(input_filename);

/* _______ OUTPUT ________*/

class Printer
{ public:
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

struct point
{
	ld x, y;
};
const ld EPS = 1e-6;

bool g(point p)
{
	return abs(round(p.x) - p.x) <= EPS and abs(round(p.y) - p.y) <= EPS;
}

pair<point, point> inter_cir_lin(ld r, ld a, ld b, ld c)
{
	ld x = -a * c / (a * a + b * b);
	ld y = -b * c / (a * a + b * b);
	ld d = sqrt(r * r - c / (a * a + b * b));
	ld m = d / sqrt(a * a + b * b);
	return{ {x + b * m, y - a * m}, {x - b * m, y + a * m} };
}

pair<point, point> inter_cir_cir(ld r, ld a, ld b, ld s)
{
	return inter_cir_lin(r, -2 * a, -2 * b, a * a + b * b + r * r - s * s);
}

bool neq(ld a, ld b)
{
	return abs(a - b) > EPS;
}

void f(ld a, ld b, ld c)
{
	for (ld x = -a; x <= a; ++x)
	{
		ld y = sqrt(a * a - x * x);

		if (not g({ x, y }))
			continue;
		auto v = inter_cir_cir(c, x, y, b);
		if (g(v.first) and neq(0, x) and neq(0, y) and neq(x, v.first.x) and neq(y, v.first.y) and neq(v.first.x, 0) and neq(v.first.y, 0))
		{
			pr("YES");
			pr(0, 0);
			pr(x, y);
			pr(v.first.x, v.first.y);
			exit(0);
		}

		if (g(v.second) and neq(0, x) and neq(0, y) and neq(x, v.second.x) and neq(y, v.second.y) and neq(v.second.x, 0) and neq(v.second.y, 0))
		{
			pr("YES");
			pr(0, 0);
			pr(x, y);
			pr(v.second.x, v.second.y);
			exit(0);
		}
	}
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int a, b;
	rd(a, b);

	f(a, b, hypot(a, b));
	f(a, hypot(a, b), b);
	f(b, a, hypot(a, b));
	pr("NO");
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
#ifdef ANDREIKKAA
	inline ANDREIKKAA_CLASS() { _start = clock(); }
	inline ~ANDREIKKAA_CLASS() { cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl; }
private:
	time_t _start;
#endif
};

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
	auto _s = new ANDREIKKAA_CLASS;
	_s->ANDREIKKAA_METHOD(ANDREIKKAA_CALL);
	delete _s;
#ifdef ANDREIKKAA
#ifdef _WIN32
	while (true);
#endif // _WIN32
#endif // ANDREIKKAA
}
#endif