/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

//#pragma GCC optimize ("O3")
//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void

#define first x
#define second y
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef long double ld;

#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const ld PI = acos(-1);

const int _ML = 500;
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
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }

/* ________ CODE ________ */

struct t2
{
	t2 *l, *r;
	int x, y, sz;
};

const int MAX_N = 200 * 1000;
t2 mem[MAX_N * 2 * 18 * 2];
int ptr = 0;

t2 *new_t2(int x)
{
	mem[ptr].x = x;
	mem[ptr].y = rand();
	mem[ptr].sz = 1;
	return mem + ptr++;
}

inline int get_sz(t2 *v)
{
	if (v == nullptr)
		return 0;
	return v->sz;
}

inline void recalc_t2(t2 *v)
{
	if (v == nullptr)
		return;
	
	v->sz = get_sz(v->l) + get_sz(v->r) + 1;
}

pair<t2*, t2*> split_t2(t2 *v, int x)
{
	if (v == nullptr)
		return{ nullptr, nullptr };

	if (x < v->x)
	{
		auto p = split_t2(v->l, x);
		v->l = p.y;
		recalc_t2(v);
		return{ p.x, v };
	}
	else
	{
		auto p = split_t2(v->r, x);
		v->r = p.x;
		recalc_t2(v);
		return{ v, p.y };
	}
}

t2 *merge_t2(t2 *v, t2 *w)
{
	if (v == nullptr)
		return w;
	if (w == nullptr)
		return v;

	if (v->y > w->y)
	{
		v->r = merge_t2(v->r, w);
		recalc_t2(v);
		return v;
	}
	else
	{
		w->l = merge_t2(v, w->l);
		recalc_t2(w);
		return w;
	}
}

inline int get_t2(t2* v, int x)
{
	int ans = 0;
	while (v)
	{
		if (x < v->x)
		{
			v = v->l;
		}
		else
		{
			ans += get_sz(v->l) + 1;
			v = v->r;
		}
	}
	return ans;
}

t2 *ins_t2(t2 *v, t2 *x)
{
	if (v == nullptr)
		return x;

	if (v->y > x->y)
	{
		if (v->x < x->x)
		{
			v->r = ins_t2(v->r, x);
		}
		else
		{
			v->l = ins_t2(v->l, x);
		}
		++v->sz;
		return v;
	}
	else
	{
		x->sz = v->sz + 1;
		auto p = split_t2(v, x->x);
		x->l = p.x;
		x->r = p.y;
		return x;
	}
}

t2 *ers_t2(t2 *v, int x)
{
	if (v == nullptr)
		return v;

	if (v->x == x)
	{
		return merge_t2(v->l, v->r);
	}
	else
	{
		if (x < v->x)
		{
			v->l = ers_t2(v->l, x);
		}
		else
		{
			v->r = ers_t2(v->r, x);
		}
		--v->sz;
		return v;
	}
}

t2* t1[MAX_N * 4];

void build_t1(int v, int l, int r)
{
	if (r - l != 1)
	{
		build_t1(v << 1, l, (l + r) >> 1);
		build_t1(v << 1 | 1, (l + r) >> 1, r);
	}

	for (int i = l; i < r; ++i)
	{
		t1[v] = ins_t2(t1[v], new_t2(i));
	}
}

ll ans = 0;
void upd_t1(int v, int l, int r, int P, int Q, int X, int Y)
{
	if (Q < l || r <= P)
	{
		return;
	}

	if (l <= P && Q < r)
	{
		//ok
	}
	else if(l <= P)
	{
		t1[v] = ers_t2(t1[v], X);
		t1[v] = ins_t2(t1[v], new_t2(Y));
	}
	else if(Q < r)
	{
		t1[v] = ers_t2(t1[v], Y);
		t1[v] = ins_t2(t1[v], new_t2(X));
	}
	else
	{
		ans += (r - l) - 2 * get_t2(t1[v], X);
		ans += 2 * get_t2(t1[v], Y) - (r - l);
		return;
	}

	if (r - l > 1)
	{
		upd_t1(v << 1, l, (l + r) >> 1, P, Q, X, Y);
		upd_t1(v << 1 | 1, (l + r) >> 1, r, P, Q, X, Y);
	}
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, q;
	cin >> n >> q;

	build_t1(1, 0, n);

	vector<int> p(n);
	iota(all(p), 0);

	for (int i = 0; i < q; ++i)
	{
		int l, r;
		cin >> l >> r;
		if (l > r)
			swap(l, r);

		if (l == r)
		{
			cout << ans << endl;
			continue;
		}

		--l;

		upd_t1(1, 0, n, l, r - 1, p[l], p[r - 1]);

		if (p[l] < p[r - 1])
			++ans;
		else
			--ans;
		swap(p[l], p[r - 1]);

		cout << ans << endl;
	}
}

/* ________ CODE ________ */

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif
	if (_inpf[0] != '\0')
		assert(freopen(_inpf, "r", stdin) != nullptr);
	if (_outf[0] != '\0')
		assert(freopen(_outf, "w", stdout) != nullptr);
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