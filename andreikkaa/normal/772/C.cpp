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

const ll N = 200 * 1000 + 2;
vector<ll> g[N];
vector<ll> l[N];

inline ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

inline vector<ll> f(ll x)
{
	vector<ll> v;
	for (ll i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
		{
			v.push_back(i);
			while (x % i == 0)
			{
				x /= i;
			}
		}
	}
	if (x != 1)
	{
		v.push_back(x);
	}
	return v;
}

ll gcdex(ll a, ll b, ll & x, ll & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcdex(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll inv(ll a, ll m)
{
	ll x, y;
	ll g = gcdex(a, m, x, y);
	if (g != 1)
		assert(false);
	else {
		x = (x % m + m) % m;
		return x;
	}
	return -228;
}

inline ll f1(ll x, ll y, ll m, ll d)
{
	ll c = m / d;
	assert(m % d == 0);
	assert(x % c == 0);
	assert(y % c == 0);

	return (ll)(inv(x / c, d) * y / c);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	ll n, m;
	cin >> n >> m;

	vector<ll> v(n);
	cin >> v;

	set<ll> s(all(v));

	for (ll i = 0; i < m; ++i)
	{
		ll g = gcd(i, m);

		if(s.find(i) == s.end())
			l[m / g].push_back(i);
	}

	vector<bool> u(m + 1);
	u[m] = true;
	for (ll i = m; i > 0; --i)
	{
		if (!u[i])
		{
			continue;
		}

		auto w = f(i);
		for (ll j : w)
		{
			u[i / j] = true;
			g[i].push_back(i / j);
		}
	}

	/*for (ll i = 1; i <= m; ++i) {
		cout << i << "->" << g[i] << endl;
		cout << i << " -> " << l[i] << endl;
	}*/

	vector<ll> dp(m + 1), pr(m + 1);
	for (ll i = 1; i <= m; ++i)
	{
		dp[i] = 0;
		pr[i] = -1;

		for (ll j : g[i])
		{
			if (dp[j] > dp[i])
			{
				dp[i] = dp[j];
				pr[i] = j;
			}
		}
		dp[i] += sz(l[i]);
	}

	cout << dp[m] << endl;
	vector<ll> ans;

	bool fl = true;
	ll lst = m;
	ll lsti = m;
	for (ll i = m; i != -1; i = pr[i])
	{
		if (!fl && sz(l[i]))
		{
			ans.push_back(f1(lst, l[i].front(), m, lsti));
		}

		if (fl && sz(l[i]))
		{
			fl = false;
			ans.push_back(l[i].front());
		}

		for (ll j = 0; j + 1 < sz(l[i]); ++j)
		{
			ans.push_back(f1(l[i][j], l[i][j + 1], m, i));
		}

		if (sz(l[i]))
		{
			lst = l[i].back();
			lsti = i;
		}
	}

	for (ll i : ans)
		cout << i % m << " ";
	cout << endl;
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