/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;
#define x first
#define y second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const ld PI = acos(-1);

const int _ML = 200;
const char _inpf[] =
#if defined(ANDREIKKAA)
"input.txt"
#else
""
#endif
;
const char _outf[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024LL * 1024LL];
size_t _ptr = 0;
inline void* operator new(size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete(void*) { }
#endif

template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << _m.begin()->first << ": " << _m.begin()->second; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", " << _it->first << ": " << _it->second; return _out; }

/* ________ CODE ________ */

struct
{
	int el;
	int dp;
	int add;
} t[500228];

inline void push_t(int x, int sz)
{
	t[x].dp += t[x].add;
	if (sz > 1)
	{
		t[x << 1].add += t[x].add;
		t[x << 1 | 1].add += t[x].add;
	}
	t[x].add = 0;
}

inline void recalc_t(int x)
{
	t[x].dp = min(t[x << 1].dp + t[x << 1].add, t[x << 1 | 1].dp + t[x << 1 | 1].add);
}

void upd_t(int v, int l, int r, int L, int V)
{
	push_t(v, r - l);
	if (L < l || r <= L)
	{
		return;
	}

	if (r - l == 1)
	{
		t[v].el = V;
		return;
	}

	upd_t(v << 1, l, (l + r) >> 1, L, V);
	upd_t(v << 1 | 1, (l + r) >> 1, r, L, V);
	recalc_t(v);
}

void upd_suf_t(int v, int l, int r, int L, int R, int V)
{
	push_t(v, r - l);
	if (R <= l || r <= L)
	{
		return;
	}

	if (L <= l && r <= R)
	{
		t[v].add = V;
		push_t(v, r - l);
		return;
	}

	upd_suf_t(v << 1, l, (l + r) >> 1, L, R, V);
	upd_suf_t(v << 1 | 1, (l + r) >> 1, r, L, R, V);
	recalc_t(v);
}

int get_t(int v, int l, int r, int L)
{
	push_t(v, r - l);
	if (L < l || r <= L)
	{
		return -228228228;
	}

	if (r - l == 1)
	{
		return t[v].dp;
	}

	return max(
		get_t(v << 1, l, (l + r) >> 1, L),
		get_t(v << 1 | 1, (l + r) >> 1, r, L)
	);
}

int get_el_t(int v, int l, int r, int L)
{
	if (r - l == 1)
	{
		return t[v].el;
	}
	if (L < ((l + r) >> 1))
	{
		return get_el_t(v << 1, l, (l + r) >> 1, L);
	}
	else
	{
		return get_el_t(v << 1 | 1, (l + r) >> 1, r, L);
	}
}

int splay_t(int v, int l, int r, int V)
{
	push_t(v, r - l);
	if (t[v].dp > V)
	{
		return -1;
	}

	if (r - l == 1)
	{
		if (t[v].dp == V)
		{
			return l;
		}
		else
		{
			return -1;
		}
	}

	int ret = splay_t(v << 1 | 1, (l + r) >> 1, r, V);
	if (ret == -1)
	{
		return splay_t(v << 1, l, (l + r) >> 1, V);
	}
	else
	{
		return ret;
	}
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int p, tt;
		cin >> p >> tt;

		if (tt == 0)
		{
			upd_t(1, 0, m + 1, p, -228);
			upd_suf_t(1, 0, m + 1, p, m + 1, -1);
		}
		else
		{
			int v;
			cin >> v;
			upd_t(1, 0, m + 1, p, v);
			upd_suf_t(1, 0, m + 1, p, m + 1, 1);
		}

		int pos = splay_t(1, 0, m + 1, get_t(1, 0, m + 1, m) - 1);
		if (pos == -1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << get_el_t(1, 0, m + 1, pos + 1) << endl;
		}
	}
}

/* ________ CODE ________ */

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif
#pragma warning(push)
#pragma warning(disable: 4127)
	if (sizeof(_inpf) > 1)
		freopen(_inpf, "r", stdin);
	if (sizeof(_outf) > 1)
		freopen(_outf, "w", stdout);
#pragma warning(pop)
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << setprecision(20);
	//cout << fixed;
	mainFunction(ANDREIKKAA_CALL);
#if defined(ANDREIKKAA)
	cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
	while (true);
#endif
}
#else
class ANDREIKKAA_CLASS { public: ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS) { return mainFunction(ANDREIKKAA_CALL); } };
#endif