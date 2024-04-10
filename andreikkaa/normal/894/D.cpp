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

const int N = 1000 * 1000 + 228;
int par[N], lft[N], rgt[N];
vector<ll> len[N];
vector<ll> ps[N];
int n;

ll ask(int v, int h, int l)
{
	ll pos = upper_bound(all(len[v]), h + l) - len[v].begin();
	if(pos == 0)
	{
		return 0;
	}
	
	return (h + l) * pos - ps[v][pos - 1];
}

void dfs(int v, int l, int w)
{
	if(v > n)
	{
		return;
	}
	
	len[w].push_back(l);
	
	dfs(2 * v, l + lft[v], w);
	dfs(2 * v + 1, l + rgt[v], w);
}

inline void mainFunction()
{
	int m;
	cin >> n >> m;
	
	for(int i = 1; i < n; ++i)
	{
		int x;
		cin >> x;
		
		if(i & 1)
		{
			lft[(i + 1) / 2] = x;
		}
		else
		{
			rgt[(i + 1) / 2] = x;
		}
		par[i + 1] = x;
	}
	
	for(int i = 1; i <= n; ++i)
	{
		dfs(i, 0, i);
		sort(all(len[i]));
		ps[i] = len[i];
		partial_sum(all(ps[i]), ps[i].begin());
	}
	
	for(int i = 0; i < m; ++i)
	{
		int a, h;
		cin >> a >> h;
		
		int len = par[a];
		int lst = a;
		int cur = a / 2;
		
		ll ans = ask(lst, h, 0);
		while(cur > 0 && len <= h)
		{
			ans += h - len;
			if(cur * 2 == lst && cur * 2 + 1 <= n)
			{
				ans += ask(cur * 2 + 1, h,  - len - rgt[cur]);
			}
			else if(cur * 2 + 1 == lst)
			{
				ans += ask(cur * 2, h,  - len - lft[cur]);
			}
			len += par[cur];
			lst /= 2;
			cur /= 2;
		}
		cout << ans << endl;
	}
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