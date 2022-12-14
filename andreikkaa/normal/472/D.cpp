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
typedef long long ll;
typedef long double ld;
#define first x
#define second y
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

#include "bits/stdc++.h"
using namespace std;

#if defined(ANDREIKKAA_ALLOCATOR)
char _mem[_ML * 1024LL * 1024LL];
size_t _ptr = 0;
inline void* operator new(size_t _x) { _ptr += _x; return _mem + _ptr - _x; }
inline void operator delete(void*) { }
#endif

template<typename T, typename U> inline ostream &operator<<(ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<<(ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator<<(ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator<<(ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << _m.begin()->first << ": " << _m.begin()->second; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", " << _it->first << ": " << _it->second; return _out; }

/* ________ CODE ________ */

const int N = 2002;
vector<pair<int, int>> g[N];
vector<int>* dd;

void dfs(int v, int d, int p)
{
	if (dd->operator[](v) != d)
	{
		cout << "NO" << endl;
		exit(0);
	}

	for (auto &i : g[v])
	{
		if (i.x != p)
		{
			dfs(i.x, d + i.y, v);
		}
	}
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	cin >> a;

	for (int i = 0; i < n; ++i)
	{
		if (a[i][i] != 0)
		{
			cout << "NO" << endl;
			return;
		}
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i][j] != a[j][i])
			{
				cout << "NO" << endl;
				return;
			}
		}
	}

	vector<bool> u(n);
	const int INF = 1000 * 1000 * 1000 + 1;
	vector<pair<int, int>> mn(n, {INF, -1});

	mn[0] = { 0, -1 };
	for (int j = 0; j < n; ++j)
	{
		int v = -1;
		for (int i = 0; i < n; ++i)
		{
			if (!u[i] && (v == -1 || mn[i] < mn[v]))
			{
				v = i;
			}
		}
		if (mn[v].x == INF)
		{
			cout << "NO" << endl;
			return;
		}
		u[v] = true;

		if (mn[v].y != -1)
		{
			if (mn[v].x == 0)
			{
				cout << "NO" << endl;
				return;
			}
			g[v].push_back({ mn[v].y, mn[v].x });
			g[mn[v].y].push_back({ v, mn[v].x });
		}

		for (int i = 0; i < n; ++i)
		{
			if (!u[i] && mn[i] > make_pair(a[v][i], i))
			{
				mn[i] = { a[v][i], v };
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		dd = &(a[i]);
		dfs(i, 0, -1);
	}

	cout << "YES" << endl;
}

/* ________ CODE ________ */

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
#if defined(ANDREIKKAA)
	time_t _start = clock();
#endif

	if (sizeof(_inpf) > 1)
		freopen(_inpf, "r", stdin);
	if (sizeof(_outf) > 1)
		freopen(_outf, "w", stdout);
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << setprecision(20);
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