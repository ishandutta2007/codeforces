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

const int MAX_N = 51;
int dp[MAX_N][256][256];

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	string s;
	rd(s);

	assert(count(s.begin(), s.end(), '.') <= 1);

	if (count(s.begin(), s.end(), '.') == 0)
	{
		s.push_back('.');
	}
	
	int ptr;
	for (ptr = 0; s[ptr] == '0'; ++ptr)
	{
	}
	s.erase(s.begin(), s.begin() + ptr);

	while (s.back() == '0')
	{
		s.pop_back();
	}

	int pos = s.find('.');
	if (pos == 0)
	{
		int pw = -1;
		for (ptr = 1; ptr < s.size(); ++ptr)
		{
			if (s[ptr] == '0')
			{
				--pw;
			}
			else
			{
				break;
			}
		}

		string buf = s.substr(ptr);
		assert(not buf.empty());
		if (buf.size() == 1)
		{
			pr.p(buf[0], 'E', pw);
		}
		else
		{
			pr.p(buf[0], '.', buf.substr(1), 'E', pw);
		}
	}
	else if (pos == 1)
	{
		if (s.size() == 2)
		{
			pr.p(s[0]);
		}
		else
		{
			pr.p(s[0], '.', s.substr(2));
		}
	}
	else if(pos == s.size() - 1)
	{
		//Z
		int pw = s.size() - 2;
		string lol = s.substr(1, s.size() - 2);
		while (not lol.empty() and lol.back() == '0')
		{
			lol.pop_back();
		}

		if (lol.empty())
		{
			pr.p(s[0], 'E', pw);
		}
		else
		{
			pr.p(s[0], '.', lol, 'E', pw);
		}
	}
	else
	{
		//XYZ.ABC
		s.erase(s.begin() + pos);
		pr.p(s[0], '.', s.substr(1), 'E', pos - 1);
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