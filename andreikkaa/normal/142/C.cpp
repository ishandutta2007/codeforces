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

const int N = 9;
int8_t dp[N * N][1 << (2 * N + 1)];
int8_t rc[N * N][1 << (2 * N + 1)];
int8_t bt[N * N][1 << (2 * N + 1)];

#define f(x, y) (((x >> y) & 1) == 0)
#define z(x, y) (x & ~(1 << y))

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, m;
	cin >> n >> m;

	fill((int8_t*)dp, (int8_t*)dp + N * N * (1 << (2 * N + 1)), -128);
	
	const int MSK = (1 << (2 * m + 1)) - 1;
	dp[0][MSK ^ 1] = 0;

	for (int i = 1; i < n * m; ++i)
	{
		int y = i % m;
		for (int j = 0; j <= MSK; ++j)
		{
			if (dp[i - 1][j] < 0)
			{
				continue;
			}

			if (dp[i - 1][j] > dp[i][(j << 1) & MSK])
			{
				dp[i][(j << 1) & MSK] = dp[i - 1][j];
				rc[i][(j << 1) & MSK] = 0;
				bt[i][(j << 1) & MSK] = (int8_t)(j >> (2 * m));
			}
			if (y >= 2 && f(j, 0) && f(j, 1) && f(j, m) && f(j, 2 * m))
			{
				int nw = (j << 1) | 7 | (1 << (m + 1));
				if (dp[i - 1][j] + 1 > dp[i][nw])
				{
					dp[i][nw] = dp[i - 1][j] + 1;
					rc[i][nw] = 1;
				}
			}

			if (1 <= y && y + 1 < m && f(j, m - 1) && f(j, 2 * m - 2) && f(j, 2 * m - 1) && f(j, 2 * m))
			{
				int nw = (j << 1) | 1 | (1 << m) | (1 << (2 * m - 1)) | (1 << (2 * m));
				if (dp[i - 1][j] + 1 > dp[i][nw])
				{
					dp[i][nw] = dp[i - 1][j] + 1;
					rc[i][nw] = 2;
				}
			}

			if (2 <= y && f(j, m - 1) && f(j, m) && f(j, m + 1) && f(j, 2 * m - 1))
			{
				int nw = (j << 1) | 1 | (1 << m) | (1 << (m + 1)) | (1 << (m + 2)) | (1 << (2 * m));
				nw &= MSK;
				if (dp[i - 1][j] + 1 > dp[i][nw])
				{
					dp[i][nw] = dp[i - 1][j] + 1;
					rc[i][nw] = 3;
					bt[i][nw] = (int8_t)(j >> (2 * m));
				}
			}
			if (y + 2 < m && f(j, m - 1) && f(j, m - 2) && f(j, m - 3) && f(j, 2 * m - 1))
			{
				int nw = (j << 1) | 1 | (1 << m) | (1 << (m - 1)) | (1 << (m - 2)) | (1 << (2 * m));
				nw &= MSK;
				if (dp[i - 1][j] + 1 > dp[i][nw])
				{
					dp[i][nw] = dp[i - 1][j] + 1;
					rc[i][nw] = 4;
					bt[i][nw] = (int8_t)(j >> (2 * m));
				}
			}
		}
	}
	
	static char ans[N][N];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			ans[i][j] = '.';

	int msk = max_element(dp[n * m - 1], dp[n * m - 1] + MSK + 1) - dp[n * m - 1];

	cout << (int)dp[n * m - 1][msk] << endl;
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			int x = i * m + j;
			if (rc[x][msk] == 0)
			{
				msk |= (bt[x][msk] << (2 * m + 1));
				msk >>= 1;
				continue;
			}
			else if (rc[x][msk] == 1)
			{
				ans[i][j] = ans[i][j - 1] = ans[i][j - 2] = ans[i - 1][j - 1] = ans[i - 2][j - 1] = 'A' + dp[x][msk] - 1;
				msk >>= 1;
				msk = z(msk, 0);
				msk = z(msk, 1);
				msk = z(msk, m);
				msk = z(msk, 2 * m);
			}
			else if (rc[x][msk] == 2)
			{
				ans[i][j] = ans[i - 1][j] = ans[i - 2][j] = ans[i - 2][j + 1] = ans[i - 2][j - 1] = 'A' + dp[x][msk] - 1;
				msk >>= 1;
				msk = z(msk, m - 1);
				msk = z(msk, 2 * m);
				msk = z(msk, 2 * m - 1);
				msk = z(msk, 2 * m - 2);
			}
			else if (rc[x][msk] == 3)
			{
				ans[i][j] = ans[i - 1][j] = ans[i - 2][j] = ans[i - 1][j - 1] = ans[i - 1][j - 2] = 'A' + dp[x][msk] - 1;
				msk |= (bt[x][msk] << (2 * m + 1));
				msk >>= 1;
				msk = z(msk, m - 1);
				msk = z(msk, m);
				msk = z(msk, m + 1);
				msk = z(msk, 2 * m - 1);
			}
			else if (rc[x][msk] == 4)
			{
				ans[i][j] = ans[i - 1][j] = ans[i - 2][j] = ans[i - 1][j + 1] = ans[i - 1][j + 2] = 'A' + dp[x][msk] - 1;
				msk |= (bt[x][msk] << (2 * m + 1));
				msk >>= 1;
				msk = z(msk, m - 1);
				msk = z(msk, m - 2);
				msk = z(msk, m - 3);
				msk = z(msk, 2 * m - 1);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << ans[i][j];
		}
		cout << endl;
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