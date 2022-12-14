/*
* C++11 code template for contests.

* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

#pragma GCC optimize ("O3")
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

const int _ML = 250;
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

const int N = 35001;
const int K = 51;

struct node
{
	node *l, *r;
	int mx, pu;
};

node mem[N * K * 4];
int ptr = 0;

node* new_t()
{
	return mem + ptr++;
}

node* build_t(int l, int r, int v)
{
	node *cur = new_t();
	cur->mx = v;
	if(r - l != 1)
	{
		cur->l = build_t(l, (l + r) >> 1, v);
		cur->r = build_t((l + r) >> 1, r, v);
	}
	return cur;
}

void push_t(node *v, int l, int r)
{
	if(r - l > 1)
	{
		v->l->pu += v->pu;
		v->r->pu += v->pu;
	}
	
	v->mx += v->pu;
	v->pu = 0;
}

void upd_t(node *v, int l, int r, int L, int R)
{
	push_t(v, l, r);

	if(R <= l || r <= L)
	{
		return;
	}

	if(L <= l && r <= R)
	{
		++v->pu;
		push_t(v, l, r);
		return;
	}

	upd_t(v->l, l, (l + r) >> 1, L, R);
	upd_t(v->r, (l + r) >> 1, r, L, R);
	v->mx = max(v->l->mx, v->r->mx);
}

void ass_t(node *v, int l, int r, int L, int V)
{
	push_t(v, l, r);
	if(L < l || r <= L)
	{
		return;
	}

	if(r - l == 1)
	{
		v->mx = V;
		return;
	}

	ass_t(v->l, l, (l + r) >> 1, L, V);
	ass_t(v->r, (l + r) >> 1, r, L, V);
	v->mx = max(v->l->mx, v->r->mx);
}

int get_t(node *v, int l, int r, int L, int R)
{
	push_t(v, l, r);
	if(R <= l || r <= L)
	{
		return 0;
	}

	if(L <= l && r <= R)
	{
		return v->mx;
	}

	return max(
	get_t(v->l, l, (l + r) >> 1, L, R),
	get_t(v->r, (l + r) >> 1, r, L, R)
	);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, k;
	cin >> n >> k;
	
	vector<node*> t(k + 1);
	for(int i = 0; i <= k; ++i)
		t[i] = build_t(0, n + 1, (i == 0 ? -228 * n : 0));
	ass_t(t[0], 0, n + 1, 0, 0);

	static int lp[N];
	
	for(int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		
		for(int j = 0; j <= k; ++j)
		{
	//		cout << "upd " << j << " " << lp[x] << ".." << i + 1 << endl;
			upd_t(t[j], 0, n + 1, lp[x], i + 1);
		}
		for(int j = 1; j <= k; ++j)
		{
	//		cout << "ass " << j << " " << i << "=" << get_t(t[j - 1], 0, n, 0, i + 1) << endl;
			ass_t(t[j], 0, n + 1, i, get_t(t[j - 1], 0, n, 0, i + 1));
		}

		lp[x] = i;
	}

	cout << get_t(t[k], 0, n + 1, n, n + 1) << endl;
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
	//while (true);
#endif
}
#else
class ANDREIKKAA_CLASS { public: ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS) { return mainFunction(ANDREIKKAA_CALL); } };
#endif