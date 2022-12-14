/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_UNSAFE_VECTOR

#ifdef ANDREIKKAA_UNSAFE_VECTOR
#define vec vector
#endif // ANDREIKKAA_UNSAFE_VECTOR

typedef long long ll;
typedef long double ld;

const int MEMORY_LIMIT_MB = 250;
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
#include <cctype>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdint>
#include <ctgmath>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <forward_list>
#include <initializer_list>
#include <regex>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*_______ TYPES ________*/

template<typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << p.first << ' ' << p.second;
	return out;
}

template<typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &p)
{
	in >> p.first >> p.second;
	return in;
}

#ifndef ANDREIKKAA_UNSAFE_VECTOR
template<typename T>
class vec : public vector<T>
{
public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const
	{
		return this->at(x);
	}
	inline T& operator[](size_t x)
	{
		return this->at(x);
	}
};

template<>
class vec<bool> : public vector<bool>
{
	using vector<bool>::vector;
public:
	inline const_reference operator[](size_t x) const
	{
		return this->at(x);
	}
	inline reference operator[](size_t x)
	{
		return this->at(x);
	}
};

template<typename T>
inline ostream &operator<<(ostream &out, const vec<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vec<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}
#endif // !ANDREIKKAA_UNSAFE_VECTOR

template<typename T>
inline ostream &operator<<(ostream &out, const vector<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
inline istream &operator>>(istream &in, vector<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}

/* _____ ALLOCATION _____ */

#ifdef ANDREIKKAA_ALLOCATOR
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x)
{
	alloc_pointer += x;
return alloc_memory + alloc_pointer - x;
}
inline void operator delete(void* x)
{

}
#endif

/* _______ INPUT _________*/

class Reader
{
public:
	inline Reader(const string &filename)
	{
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		if (not filename.empty())
			assert(freopen(filename.c_str(), "r", stdin) != nullptr);
	}

	template<typename T>
	inline void operator()(T &x)
	{
		cin >> x;
	}

	template<typename T, typename... Args>
	inline void operator()(T &x, Args &... args)
	{
		operator()(x), operator()(args...);
	}
};
Reader rd(input_filename);

/* _______ OUTPUT ________*/

class Printer
{
public:
	inline Printer(const string &filename)
	{
		//cout.precision(20);
		//cout << fixed;
		if (not filename.empty())
			assert(freopen(filename.c_str(), "w", stdout) != nullptr);
	}

	template<typename T>
	inline void out(const T x)
	{
		cout << x;
	}

	template<typename T, typename... Args>
	inline void out(const T x, const Args... args)
	{
		out(x), out(args...);
	}

	inline void operator()()
	{
		out('\n');
	}

	template<typename T>
	inline void operator()(const T x)
	{
		out(x), out('\n');
	}

	template<typename T, typename... Args>
	inline void operator()(const T x, const Args... args)
	{
		out(x), out(' '), operator()(args...);
	};
};
Printer pr(output_filename);

/* ________ CODE ________ */

const int H_MEM = (1 << 24);
const int H_MOD = H_MEM - 1;
int t_v[H_MEM];
int t_t[H_MEM];
int t_val[H_MEM];

inline void pls(int v, int t, int val)
{
	int h = ((v >> 1) + 123456 + (t << 1)) & H_MOD;
	for (; ; h = ((h + 1) & H_MOD))
	{
		if (t_v[h] == 0)
		{
			t_v[h] = v;
			t_t[h] = t;
			t_val[h] = val;
			return;
		}
		else if (t_v[h] == v and t_t[h] == t)
		{
			t_val[h] += val;
			return;
		}
	}
}

inline int ask(int v, int t)
{
	int h = ((v >> 1) + 123456 + (t << 1)) & H_MOD;
	for (; ; h = ((h + 1) & H_MOD))
	{
		if (t_v[h] == 0)
		{
			return 0;
		}
		else if (t_v[h] == v and t_t[h] == t)
		{
			return t_val[h];
		}
	}
}

inline void add_t(int v, int t, int val)
{
	for (; t <= 2000000; t |= (t + 1))
	{
		pls(v, t, val);
	}
}

inline int query_t(int v, int t)
{
	int ans = 0;
	for (; t >= 0; t = (t & (t + 1)) - 1)
	{
		ans += ask(v, t);
	}
	return ans;
}

class Solution
{
public:

	inline void solve()
	{
		int n;
		rd(n);
		
		unordered_map<int, int> ptr;
		ptr.rehash(n);
		const int SZ = 1000000;
		static int v[SZ];
		static int qa[SZ];
		static int qt[SZ];
		static int qx[SZ];
		for (int i = 0; i < n; ++i)
		{
			int a, t, x;
			rd(a, t, x);
			v[i] = t;
			qa[i] = a;
			qt[i] = t;
			qx[i] = x;
		}

		sort(v, v + n);
		int pos = unique(v, v + n) - v;

		for (int i = 0; i < n; ++i)
		{
			qt[i] = lower_bound(v, v + pos, qt[i]) - v + 1;
			if (qa[i] == 1)
			{
				add_t(qx[i], qt[i], 1);
			}
			else if (qa[i] == 2)
			{
				add_t(qx[i], qt[i], -1);
			}
			else
			{
				printf("%d\n", query_t(qx[i], qt[i]));
			}
		}
	}

	Solution()
	{
#ifdef ANDREIKKAA
		start = clock();
#endif // ANDREIKKAA
	}

	~Solution()
	{
#ifdef ANDREIKKAA
		cerr << "Time: " << (clock() - start) / (ld)CLOCKS_PER_SEC << endl;
#endif // ANDREIKKAA
	}
private:
#ifdef ANDREIKKAA
	time_t start;
#endif // ANDREIKKAA
};

int main()
{
	auto s = new Solution;
	s->solve();
	delete s;
#ifdef ANDREIKKAA 
#ifdef _WIN32
	while (true);
#endif // _WIN32
#endif // ANDREIKKAA
}