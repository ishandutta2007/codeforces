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

const int MEMORY_LIMIT_MB = 400;
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
{
public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const { return this->at(x); }
	inline T& operator[](size_t x) { return this->at(x); }
};

template<> class vec<bool> : public vector<bool>
{
public:
	using vector<bool>::vector;
	inline const_reference operator[](size_t x) const { return this->at(x); }
	inline reference operator[](size_t x) { return this->at(x); }
};
#endif // !ANDREIKKAA_UNSAFE_VECTOR

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

ll a[1000001];
ll sum[3000001];
ll suf[1000001];
pair<ll, ll> cnt[1000001];

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	rd(n);
	
	for (int i = 0; i < n; ++i)
		rd(a[i]);

	const ll MX = 3000000;
	
	sort(a, a + n);
	
	cnt[0] = { a[0], 1 };
	
	int ptr = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i - 1] == a[i])
		{
			++cnt[ptr].second;
		}
		else
		{
			++ptr;
			cnt[ptr] = { a[i], 1 };
		}
	}
	++ptr;

	for (int i = ptr - 1; i >= 0; --i)
	{
		suf[i] = suf[i + 1] + cnt[i].second;
	}

	ll tot = 0;

	for (int i = 0; i < ptr; ++i)
	{
		if (cnt[i].first * cnt[i].first > MX)
		{
			tot += (cnt[i].second * (cnt[i].second - 1));
		}
		else
		{
			sum[cnt[i].first * cnt[i].first] += (cnt[i].second * (cnt[i].second - 1));
		}

		for (int j = i + 1; j < ptr; ++j)
		{
			if (cnt[i].first * cnt[j].first > MX)
			{
				tot += 2 * cnt[i].second * suf[j];
				break;
			}
			else
			{
				sum[cnt[i].first * cnt[j].first] += 2 * cnt[i].second * cnt[j].second;
			}
		}
	}

	for (int i = MX - 1; i >= 0; --i)
	{
		sum[i] += sum[i + 1];
	}

	int m;
	rd(m);

	for (int i = 0; i < m; ++i)
	{
		int x;
		rd(x);

		pr(tot + sum[x]);
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