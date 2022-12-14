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

const int N = 1010;
const int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int u[N][N];
int n, m;

bool ok(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int cnt[2];
void dfs(int x, int y, int c)
{
	if (!ok(x, y) || u[x][y])
	{
		return;
	}
	u[x][y] = c;
	++cnt[c - 1];

	for (int i = 0; i < 8; ++i)
	{
		dfs(x + dx[i], y + dy[i], 3 - c);
	}
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	cin >> n >> m;

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!u[i][j])
			{
				cnt[0] = cnt[1] = 0;
				dfs(i, j, 1);
				ans += max(cnt[0], cnt[1]);
			}
		}
	}
	cout << ans << endl;
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