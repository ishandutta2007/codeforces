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
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void
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

/* ________ CODE ________ */

const int MAX_N = 5002;
const int MAX_C = 200 * 1000 + 228;
vector<int> g[MAX_N];
vector<pair<int, int>> sh[MAX_N];
int t_cnt[MAX_C * 4];
ll t_sum[MAX_C * 4];
bool zer[MAX_C * 4];

inline void push_t(int v, int l, int r)
{
	if (not zer[v])
		return;
	
	zer[v] = false;
	t_cnt[v] = 0;
	t_sum[v] = 0;
	if (r - l > 1)
	{
		zer[2 * v] = zer[2 * v + 1] = true;
	}
}

void upd_t(int v, int l, int r, const int X, const int Y)
{
	push_t(v, l, r);
	if (X < l or r <= X)
		return;

	if (r - l == 1)
	{
		t_cnt[v] += Y;
		t_sum[v] += (ll)X * Y;
		return;
	}

	upd_t(2 * v, l, (l + r) >> 1, X, Y);
	upd_t(2 * v + 1, (l + r) >> 1, r, X, Y);
	t_cnt[v] = t_cnt[2 * v] + t_cnt[2 * v + 1];
	t_sum[v] = t_sum[2 * v] + t_sum[2 * v + 1];
}

ll get_t(int v, int l, int r, const int X)
{
	push_t(v, l, r);
	if (r - l == 1)
	{
		assert(X <= t_cnt[v]);
		return (ll)X * l;
	}
	push_t(2 * v, l, (l + r) >> 1);
	if (t_cnt[2 * v] >= X)
	{
		return get_t(2 * v, l, (l + r) >> 1, X);
	}
	else
	{
		return get_t(2 * v + 1, (l + r) >> 1, r, X - t_cnt[2 * v]) + t_sum[2 * v];
	}
}

ll get_t(const int X)
{
	push_t(1, 0, MAX_C);
	if (t_cnt[1] < X)
	{
		return 1000000001;
	}
	return get_t(1, 0, MAX_C, X);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int w;
	cin >> w;
	for (int i = 0; i < w; ++i)
	{
		int c, k, p;
		cin >> c >> k >> p;
		sh[c].push_back({ k, p });
	}

	int q;
	cin >> q;

	static int qv[MAX_N], qd[MAX_N];
	static bool used[MAX_N];
	for (int i = 0; i < q; ++i)
	{
		zer[1] = true;
		memset(used, 0, sizeof(used));

		int ql = 0;
		int qr = 1;

		int gg, r, a;
		cin >> gg >> r >> a;

		qv[ql] = gg;
		qd[ql] = 0;
		used[gg] = true;

		int lstd = -1;
		while (ql != qr)
		{
			int v = qv[ql];
			int d = qd[ql];
			++ql;

			if (d != lstd)
			{
				if (get_t(r) <= a)
				{
					cout << d - 1 << endl;
					goto ok;
				}
				lstd = d;
			}
			for (auto &j : sh[v])
			{
				upd_t(1, 0, MAX_C, j.second, j.first);
			}
			
			for (int j : g[v])
			{
				if (not used[j])
				{
					qv[qr] = j;
					qd[qr] = d + 1;
					used[j] = true;
					++qr;
				}
			}
		}
		if (get_t(r) <= a)
		{
			cout << qd[qr - 1] << endl;
			goto ok;
		}
		cout << -1 << endl;
	ok:;
	}
}

class ANDREIKKAA_CLASS
{
public:
	ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS)
	{
#ifdef ANDREIKKAA
		freopen("input.txt", "r", stdin);
#endif
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