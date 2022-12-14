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

inline int popc(ll x)
{
	int ans = 0;
	for (int i = 0; i < 60; ++i)
	{
		if ((x >> i) & 1)
		{
			++ans;
		}
	}
	return ans;
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	ll k;
	rd(n, k);

	if (k == 1)
	{
		pr(n);
		return;
	}

	vec<ll> v(n);
	rd(v);

	static ll g[100][100];
	static ll res[100][100];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (popc(v[i] ^ v[j]) % 3 == 0)
			{
				res[i][j] = g[i][j] = 1;
			}
			//pr.p(g[i][j]);
		}
		//pr();
	}
	
	static ll buf[100][100];

	const ll MOD = 1000000007;

	k -= 2;
	while (k > 0)
	{
		if (k & 1)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					buf[i][j] = 0;
					for (int k = 0; k < n; ++k)
					{
						(buf[i][j] += res[i][k] * g[k][j]) %= MOD;
					}
				}
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					res[i][j] = buf[i][j];
					//pr.p(res[i][j]);
				}
				//pr();
			}
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				buf[i][j] = 0;
				for (int k = 0; k < n; ++k)
				{
					(buf[i][j] += g[i][k] * g[k][j]) %= MOD;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				g[i][j] = buf[i][j];
			}
		}

		k >>= 1;
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			ans += res[i][j];
		}
	}
	pr(ans % MOD);
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