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

class Solution
{
public:

	inline void solve()
	{
		const int MAX_N = 3000;
		static vec<int> g[MAX_N];

		int n, m;
		rd(n, m);

		for (int i = 0; i < m; ++i)
		{
			int a, b;
			rd(a, b);
			--a;
			--b;
			g[a].push_back(b);
		}

		const int16_t INF = -10000;
		static int16_t dist[MAX_N][MAX_N];
		for (int i = 0; i < MAX_N; ++i)
		{
			for (int j = 0; j < MAX_N; ++j)
				dist[i][j] = INF;
			dist[i][i] = 0;
		}
		static int in[3][MAX_N], out[3][MAX_N];

		for (int i = 0; i < n; ++i)
		{
			int qv[MAX_N];
			int ql = 0, qr = 1;
			qv[ql] = i;
			while (ql != qr)
			{
				int v = qv[ql];
				int16_t d = dist[i][v];
				++ql;
				for (int j : g[v])
				{
					if (dist[i][j] == INF)
					{
						dist[i][j] = d + 1;
						out[0][i] = out[1][i];
						out[1][i] = out[2][i];
						out[2][i] = j;

						if (d + 1 > dist[in[2][j]][j])
						{
							in[0][j] = in[1][j];
							in[1][j] = in[2][j];
							in[2][j] = i;
						}
						else if (d + 1 > dist[in[1][j]][j])
						{
							in[0][j] = in[1][j];
							in[1][j] = i;
						}
						else if (d + 1 > dist[in[0][j]][j])
						{
							in[0][j] = i;
						}

						qv[qr] = j;
						++qr;
					}
				}
			}
			dist[i][i] = INF;
		}

		int16_t ans = 0;
		int p0, p1, p2, p3;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dist[i][j] == INF)
				{
					continue;
				}

				int16_t cur = dist[i][j];
				for (int k = 2; k >= 0; --k)
				{
					if (in[k][i] == j)
						continue;

					for (int l = 2; l >= 0; --l)
					{
						if (out[l][j] == i or out[l][j] == in[k][i])
							continue;
						else
						{
							if (cur + dist[in[k][i]][i] + dist[j][out[l][j]] > ans)
							{
								ans = cur + dist[in[k][i]][i] + dist[j][out[l][j]];
								p0 = in[k][i];
								p1 = i;
								p2 = j;
								p3 = out[l][j];
							}
							break;
						}
					}
				}
			}
		}
		pr(p0 + 1, p1 + 1, p2 + 1, p3 + 1);
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