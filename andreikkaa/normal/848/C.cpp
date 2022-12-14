/*
* C++11 code template for contests.
* @author: Andrei Kalendarov
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

#include "bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef double ld;

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
pair<int, int> val[N];
set<int> num[N];

struct node
{
	node *l, *r;
	pair<int, int> x;
	int y;
	ll sum;
};

node *t[4 * N];
node mem[N * 18 * 4];
int mp = 0;


inline node *new_t(pair<int, int> p)
{
	mem[mp] = {nullptr, nullptr, p, rand(), p.y};
	return mem + mp++;
}

inline ll get_sum(node *v)
{
	if(v == nullptr)
	{
		return 0;
	}
	return v->sum;
}

inline void recalc_t(node *v)
{
	v->sum = v->x.y + get_sum(v->l) + get_sum(v->r);
}

ll sum_t(node *v, int k)
{
	if(v == nullptr)
	{
		return 0;
	}

	if(v->x.x >= k)
	{
		return get_sum(v->r) + v->x.y + sum_t(v->l, k);
	}
	else
	{
		return sum_t(v->r, k);
	}
}

pair<node *, node *> split_t(node *v, pair<int, int> k)
{
	if(v == nullptr)
	{
		return {nullptr, nullptr};
	}

	if(v->x < k)
	{
		auto p = split_t(v->r, k);
		v->r = p.x;
		recalc_t(v);
		return {v, p.y};
	}
	else
	{
		auto p = split_t(v->l, k);
		v->l = p.y;
		recalc_t(v);
		return {p.x, v};
	}
}

node *merge_t(node *a, node *b)
{
	if(a == nullptr)
	{
		return b;
	}
	if(b == nullptr)
	{
		return a;
	}

	if(a->y > b->y)
	{
		a->r = merge_t(a->r, b);
		recalc_t(a);
		return a;
	}
	else
	{
		b->l = merge_t(a, b->l);
		recalc_t(b);
		return b;
	}
}

node *ins_t(node *v, node *t)
{
	auto p = split_t(v, t->x);
	return merge_t(p.x, merge_t(t, p.y));
}

node *ers_t(node *v, pair<int, int> k)
{
	auto p = split_t(v, k);
	k.y++;
	auto q = split_t(p.y, k);
	return merge_t(p.x, q.y);
}

ll get_t(int v, int l, int r, int L, int R)
{
	if(R <= l || r <= L)
	{
		return 0;
	}

	if(L <= l && r <= R)
	{
		return sum_t(t[v], L);
	}

	return get_t(v << 1, l, (l + r) >> 1, L, R) + 
	       get_t(v << 1 | 1, (l + r) >> 1, r, L, R);
}

void upd_t_add(int v, int l, int r, int L, pair<int, int> P)
{
	if(L < l || r <= L)
	{
		return;
	}

	t[v] = ins_t(t[v], new_t(P));

	if(r - l > 1)
	{
		upd_t_add(v << 1, l, (l + r) >> 1, L, P);
		upd_t_add(v << 1 | 1, (l + r) >> 1, r, L, P);
	}
}

void upd_t_rem(int v, int l, int r, int L, pair<int, int> P)
{
	if(L < l || r <= L)
	{
		return;
	}

	t[v] = ers_t(t[v], P);

	if(r - l > 1)
	{
		upd_t_rem(v << 1, l, (l + r) >> 1, L, P);
		upd_t_rem(v << 1 | 1, (l + r) >> 1, r, L, P);
	}
}

int a[N];

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, m;
	cin >> n >> m;

	map<int, int> prv;
	for(int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		
		a[i] = x;
		val[i] = {prv[x], i - prv[x]};
		prv[x] = i;
		num[x].insert(i);
		upd_t_add(1, 1, n + 1, i, val[i]);
	}

	for(int i = 0; i < m; ++i)
	{
		int t, l, r;
		cin >> t >> l >> r;

		if(t == 1)
		{
			int old = a[l];
			int now = r;
			a[l] = r;

			auto pos = num[old].find(l);
			auto nxt = pos;
			
			upd_t_rem(1, 1, n + 1, l, val[l]);

			++nxt;

			if(nxt != num[old].end())
			{
				upd_t_rem(1, 1, n + 1, *nxt, val[*nxt]);
				val[*nxt] = {val[l].x, *nxt - val[l].x};
				upd_t_add(1, 1, n + 1, *nxt, val[*nxt]);
			}
			
			num[old].erase(pos);
			num[now].insert(l);
			
			pos = num[now].find(l);
			nxt = pos;

			++nxt;
			if(nxt != num[now].end())
			{
				val[l] = {val[*nxt].x, l - val[*nxt].x};

				upd_t_rem(1, 1, n + 1, *nxt, val[*nxt]);
				val[*nxt] = {l, *nxt - l};
				upd_t_add(1, 1, n + 1, *nxt, val[*nxt]);
			}
			else
			{
				if(pos == num[now].begin())
				{
					val[l] = {0, l};
				}
				else
				{
					--pos;
					val[l] = {*pos, l - *pos};
				}
			}

			upd_t_add(1, 1, n + 1, l, val[l]);
		}
		else
		{
			cout << get_t(1, 1, n + 1, l, r + 1) << endl;
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
	cout << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl;
#endif
}
#else
class ANDREIKKAA_CLASS { public: ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS) { return mainFunction(ANDREIKKAA_CALL); } };
#endif