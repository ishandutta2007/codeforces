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

const int N = 200 * 1000 + 228;
struct
{
	ll v, p;
} t[4 * N];

void push_t(int v, int l, int r)
{
	t[v].v = max(t[v].v, t[v].p);
	if (r - l > 1)
	{
		t[v << 1].p = max(t[v << 1].p, t[v].p);
		t[v << 1 | 1].p = max(t[v << 1 | 1].p, t[v].p);
	}
	t[v].p = 0;
}

ll get_t(int v, int l, int r, const int L, const int R)
{
	push_t(v, l, r);
	if (R <= l || r <= L)
	{
		return 0;
	}

	if (L <= l && r <= R)
	{
		return t[v].v;
	}

	return max(
		get_t(v << 1, l, (l + r) >> 1, L, R),
		get_t(v << 1 | 1, (l + r) >> 1, r, L, R)
	);
}

void upd_t(int v, int l, int r, const int L, const ll V)
{
	push_t(v, l, r);
	if (L < l || r <= L)
	{
		return;
	}

	if (r - l == 1)
	{
		t[v].p += V;
		push_t(v, l, r);
		return;
	}

	upd_t(v << 1, l, (l + r) >> 1, L, V);
	upd_t(v << 1 | 1, (l + r) >> 1, r, L, V);
	t[v].v = max(t[v << 1].v, t[v << 1 | 1].v);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	cin >> n;

	vector<pair<pair<int, int>, int>> v(n);
	cin >> v;


	sort(all(v), [](const pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
	{
		if (a.x.y == b.x.y)
			return a.x.x > b.x.x;
		return a.x.y > b.x.y;
	});

	vector<int> s;
	for (auto &i : v)
	{
		s.push_back(i.x.x);
		s.push_back(i.x.y);
	}
	sort(all(s));
	s.resize(unique(all(s)) - s.begin());

	for (auto &i : v)
	{
		i.x.x = lower_bound(all(s), i.x.x) - s.begin();
		i.x.y = lower_bound(all(s), i.x.y) - s.begin();
	}

	for (int i = 0; i < n; ++i)
	{
		ll x = get_t(1, 0, sz(s), 0, v[i].x.y);
		upd_t(1, 0, sz(s), v[i].x.x, x + v[i].y);
	}

	cout << get_t(1, 0, sz(s), 0, sz(s)) << endl;
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