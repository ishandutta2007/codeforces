/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

#ifndef ANDREIKKAA
#pragma GCC optimize ("O3")
#endif
//#define ANDREIKKAA_ALLOCATOR
//#define ANDREIKKAA_INTERACTIVE
const int _ML = 500;
const char _inpf[] =
#ifdef ANDREIKKAA
"input.txt"
#else
""
#endif
;
const char _outf[] =
#ifdef ANDREIKKAA
""
#else
""
#endif
;

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define rand rd
#define random_shuffle abcdefghijklmnopqrstuvwxyz
#ifndef ANDREIKKAA_INTERACTIVE
#define endl '\n'
#endif
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef double ld;
const ld PI = 3.14159265358979323846;
mt19937 rd(228);

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024 * 1024];
size_t _ptr = 0;
inline void* operator new (size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete (void*) { }
#endif

template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }

/* ________ CODE ________ */

const int N = 100 * 1000 + 228;
ll a[N];
ll b[N];

struct
{
	ll mx;
	ll p;
} t[4 * N];

inline void push_t(int v, int l, int r)
{
	t[v].mx += t[v].p;
	
	if(r - l > 1)
	{
		t[v << 1].p += t[v].p;
		t[v << 1 | 1].p += t[v].p;
	}
	
	t[v].p = 0;
}

inline void rec_t(int v)
{
	t[v].mx = max(t[v << 1].mx, t[v << 1 | 1].mx);
}

ll get_t(int v, int l, int r, int L, int R)
{
	push_t(v, l, r);
	if(R <= l || r <= L)
	{
		return -1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
	}
	
	if(L <= l && r <= R)
	{
		return t[v].mx;
	}
	
	return max(
		get_t(v << 1, l, (l + r) >> 1, L, R),
		get_t(v << 1 | 1, (l + r) >> 1, r, L, R)
	);
}

void upd_t(int v, int l, int r, int L, int R, ll X)
{
	push_t(v, l, r);
	if(R <= l || r <= L)
	{
		return;
	}
	
	if(L <= l && r <= R)
	{
		t[v].p = X;
		push_t(v, l, r);
		return;
	}
	
	upd_t(v << 1, l, (l + r) >> 1, L, R, X);
	upd_t(v << 1 | 1, (l + r) >> 1, r, L, R, X);
	rec_t(v);
}

void build_t(int v, int l, int r)
{
	if(r - l == 1)
	{
		t[v].mx = b[l];
	}
	else
	{
		build_t(v << 1, l, (l + r) >> 1);
		build_t(v << 1 | 1, (l + r) >> 1, r);
		rec_t(v);
	}
}

inline void mainFunction()
{
	int n, d;
	cin >> n >> d;
	
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	partial_sum(a, a + n, b);
	
	build_t(1, 0, n);
	
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ll now = get_t(1, 0, n, i, i + 1);
		if(now > d)
		{
			cout << -1 << endl;
			return;
		}
		
		if(a[i] == 0)
		{
			if(now < 0)
			{
				ll val = get_t(1, 0, n, i, n);
				if(d - val < -now)
				{
					cout << -1 << endl;
					return;
				}
				upd_t(1, 0, n, i, n, d - val);
				++ans;
			}
		}
	}
	
	cout << ans << endl;
}

/* ________ CODE ________ */

int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif
	if (_inpf[0] != '\0') assert(freopen(_inpf, "r", stdin) != nullptr);
	if (_outf[0] != '\0') assert(freopen(_outf, "w", stdout) != nullptr);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << setprecision(18);
	//cout << fixed;	
	mainFunction();
#if defined(ANDREIKKAA)
	cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}