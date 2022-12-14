/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/* ______ TEMPLATE ______ */

#define _CRT_SECURE_NO_WARNINGS
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
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
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;

template<class T>
class vec : public vector<T>
{
public:
	using vector<T>::vector;
	inline const T operator[](size_t x) const
	{
		return this->at(x);
	}
	inline T operator[](size_t x)
	{
		return this->at(x);
	}
};

template<>
class vec<bool> : public vector<bool>
{
	using vector<bool>::vector;
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
ostream &operator<<(ostream &out, const vec<T> &v)
{
	if (v.empty())
		return out;
	out << v.front();
	for (auto it = ++v.begin(); it != v.end(); ++it)
		out << ' ' << *it;
	return out;
}

template<typename T>
istream &operator>>(istream &in, vec<T> &v)
{
	for (auto &i : v)
		in >> i;
	return in;
}

/**  FAST ALLOCATOR
char alloc_memory[250 * 1000 * 1000];
size_t alloc_pointer = 0;
void* operator new(size_t x)
{
alloc_pointer += x;
return alloc_memory + alloc_pointer - x;
}
void operator delete(void* x)
{

}
*/

/* ________ CODE ________ */

class Solution
{
public:



	inline void solve()
	{
		ll n, k;
		in(n, k);

		ll l = 0, r = n - 1;
		ll ans = 0;
		for (int i = 0; i < k; ++i)
		{
			if (l >= r)
				break;
			++ans;
			++l;
			--r;
			if (l > r)
				break;
			ans += 2 * (r - l + 1);
		}
		out(ans);
	}

	Solution()
	{
#ifdef ANDREIKKAA
		solution_redirect_io("input.txt", "");
#else
		solution_redirect_io("", "");
#endif // ANDREIKKAA
		solution_setup();
	}

	~Solution()
	{
		deb("Time:", clock() / (ld)CLOCKS_PER_SEC);
		fflush(stdout);
	}
private:

	void solution_setup()
	{
		cin.tie(nullptr), ios_base::sync_with_stdio(false);
		/*cout.precision(20);*/
	}

	void solution_redirect_io(const string &in, const string &out)
	{
		if (not in.empty())
			freopen(in.c_str(), "r", stdin);
		if (not out.empty())
			freopen(out.c_str(), "w", stdout);
	}

	template<typename T>
	inline void in(T &x)
	{
		cin >> x;
	}

	template<typename T, typename... Args>
	inline void in(T &x, Args &... args)
	{
		in(x), in(args...);
	}

	template<typename T>
	inline void raw(const T x)
	{
		cout << x;
	}

	template<typename T, typename... Args>
	inline void raw(const T x, const Args... args)
	{
		raw(x), raw(args...);
	}

	inline void out()
	{
		raw('\n');
	}

	template<typename T>
	inline void out(const T x)
	{
		raw(x), raw('\n');
	}

	template<typename T, typename... Args>
	inline void out(const T x, const Args... args)
	{
		raw(x), raw(' '), out(args...);
	};

	template<typename T>
	inline void solution_deb(const T x)
	{
#ifdef ANDREIKKAA
		raw(x);
#endif //ANDREIKKAA
	}

	template<typename T, typename... Args>
	inline void solution_deb(const T x, const Args... args)
	{
		solution_deb(x), solution_deb(' '), solution_deb(args...);
	};

	template<typename... Args>
	inline void deb(const Args... args)
	{
		solution_deb("<<"), solution_deb(args...), solution_deb(">>"), solution_deb('\n');
	};
};

int main()
{
	auto s = new Solution;
	s->solve();
	delete s;

#ifdef ANDREIKKAA
#ifdef _WIN32
	while (true) {}
#endif //WIN32
#endif // ANDREIKKAA
}