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

struct node
{
	node *l, *r;
	int sum;
	bool push;

	node(node* v)
	{
		l = v->l;
		r = v->r;
		sum = v->sum;
		push = v->push;
	}

	node()
	{
		l = r = 0;
		sum = push = 0;
	}
};

inline int get_t(node* v, int l)
{
	if (v->push)
		return l - v->sum;
	return v->sum;
}

node* build_t(int l, int r)
{
	auto v = new node;
	if (r - l > 1)
	{
		v->l = build_t(l, (l + r) / 2);
		v->r = build_t((l + r) / 2, r);
	}
	return v;
}

inline node *push_t(node *w, int l)
{
	if (w->push)
	{
		w->sum = l - w->sum;
		if (w->l != nullptr)
		{
			w->l = new node(w->l);
			w->r = new node(w->r);
			w->l->push = not w->l->push;
			w->r->push = not w->r->push;
		}
		w->push = false;
	}
	return w;
}

node* upd_t(node* v, int l, int r, const int L, const int V)
{
	if (L < l or r <= L)
		return v;

	auto w = new node(v);
	push_t(w, r - l);

	if (r - l == 1)
	{
		w->sum = V;
		w->push = false;
		return w;
	}
	
	w->l = upd_t(w->l, l, (l + r) / 2, L, V);
	w->r = upd_t(w->r, (l + r) / 2, r, L, V);
	w->sum = get_t(w->l, (l + r) / 2 - l) + get_t(w->r, r - (l + r) / 2);
	return w;
}

node *rev_t(node* v, int l, int r, const int L, const int R)
{
	if (R <= l or r <= L)
		return v;

	auto w = new node(v);
	push_t(w, r - l);
	
	if (L <= l and r <= R)
	{
		w->push = true;
		return w;
	}

	w->l = rev_t(w->l, l, (l + r) / 2, L, R);
	w->r = rev_t(w->r, (l + r) / 2, r, L, R);
	w->sum = get_t(w->l, (l + r) / 2 - l) + get_t(w->r, r - (l + r) / 2);
	return w;
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, m, q;
	rd(n, m, q);

	const int MAX_Q = 100 * 1000 + 228;
	static node* v[MAX_Q];
	v[0] = build_t(0, n * m);
	
	for (int i = 1; i <= q; ++i)
	{
		int t;
		rd(t);

		if (t == 1)
		{
			int x, y;
			rd(x, y);
			--x;
			--y;
			v[i] = upd_t(v[i - 1], 0, n * m, x * m + y, 1);
		}
		else if (t == 2)
		{
			int x, y;
			rd(x, y);
			--x;
			--y;
			v[i] = upd_t(v[i - 1], 0, n * m, x * m + y, 0);
		}
		else if (t == 3)
		{
			int x;
			rd(x);
			--x;
			v[i] = rev_t(v[i - 1], 0, n * m, x * m, x * m + m);
		}
		else
		{
			int x;
			rd(x);
			v[i] = v[x];
		}
		pr(get_t(v[i], n * m));
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