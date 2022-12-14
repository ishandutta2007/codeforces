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
//#define all(a) a.begin(), a.end()

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
inline void operator divete(void*) { }
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

const int MAX_DIV = 6720 + 228;
const int MAX_N = 1001;
const int INF = MAX_DIV * 228;

inline ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int ans[MAX_N][MAX_DIV];
ll sum[MAX_N][MAX_DIV];
int wh[MAX_N][MAX_DIV];
unordered_map<ll, int> u;

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	u.rehash(MAX_DIV * 10);
	int n;
	ll k;
	rd(n, k);
	static pair<ll, int> a[MAX_DIV];
	forr(i, 1, n + 1)
	{
		rd(a[i].first);
		a[i].second = i;
	}

	if (k == 1)
	{
		pr(1);
		pr(min_element(a + 1, a + n + 1)->second);
		return;
	}

	static ll div[MAX_DIV];
	int ptr = 0;
	ll to = (ll)sqrt(k);
	for (ll i = 1; i <= to; ++i)
	{
		if (k % i == 0)
		{
			div[ptr] = i;
			div[ptr + 1] = k / i;
			ptr += 2;
		}
	}
	sort(div, div + ptr);
	ptr = unique(div, div + ptr) - div;
	fori(i, ptr)
	{
		u[div[i]] = i;
	}

	static int num[MAX_N][MAX_DIV];
	fill(num[0], num[0] + MAX_DIV, INF);
	num[0][0] = 0;

	forr(i, 1, n + 1)
	{
		fori(j, ptr)
		{
			num[i][j] = num[i - 1][j];
			sum[i][j] = sum[i - 1][j];
			ans[i][j] = -1;
			wh[i][j] = j;
			int par = u[div[j] / gcd(div[j], a[i].first)];
			if (num[i - 1][par] + 1 < num[i][j] or (num[i - 1][par] + 1 == num[i][j] and sum[i - 1][par] + a[i].first < sum[i][j]))
			{
				num[i][j] = num[i - 1][par] + 1;
				sum[i][j] = sum[i - 1][par] + a[i].first;
				ans[i][j] = a[i].second;
				wh[i][j] = par;
			}
		}
		//pr(i, num[i], sum[i], prv[i], ans[i]);
	}

	--ptr;
	if (num[n][ptr] == INF)
	{
		pr(-1);
		return;
	}
	pr(num[n][ptr]);
	for (int i = n; i > 0; --i)
	{
		if (ans[i][ptr] != -1)
		{
			pr.p(ans[i][ptr], ' ');
			ptr = wh[i][ptr];
		}
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