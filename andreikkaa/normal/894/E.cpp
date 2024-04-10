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

vector<pair<int, int>> g[N], rg[N], ng[N];
ll ans[N], def[N];
int clr[N];
bool u[N];
vector<ll> sums, ps;

vector<int> ord;
void dfs(int v)
{
	if(u[v])
	{
		return;
	}
	u[v] = true;
	
	for(auto i : g[v])
	{
		dfs(i.x);
	}
	ord.push_back(v);
}

void dfs2(int v, int c)
{
	if(u[v])
	{
		return;
	}
	u[v] = true;
	
	clr[v] = c;
	for(auto i : rg[v])
	{
		dfs2(i.x, c);
	}
}

inline ll f(ll x)
{
	int pos = upper_bound(all(sums), x) - sums.begin();
	return pos * x - ps[pos - 1];
}

ll dfs_ans(int v)
{
	if(u[v])
	{
		return ans[v] + def[v];
	}
	u[v] = true;
	
	for(auto i : ng[v])
	{
		ans[v] = max(ans[v], i.y + dfs_ans(i.x));
	}
	return ans[v] + def[v];
}

inline void mainFunction()
{
	ll sum = 0;
	for(int i = 1; sum <= 100 * 1000 * 1000; ++i)
	{
		sums.push_back(sum);
		sum += i;
	}
	
	ps = sums;
	partial_sum(all(ps), ps.begin());
	
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		g[a].push_back({b, c});
		rg[b].push_back({a, c});
	}
	
	for(int i = 1; i <= n; ++i)
	{
		dfs(i);
	}
	
	reverse(all(ord));
	memset(u, 0, sizeof u);
	int clr = 0;
	
	for(int i : ord)
	{
		if(!u[i])
		{
			dfs2(i, clr);
			++clr;
		}
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(auto j : g[i])
		{
			if(::clr[i] != ::clr[j.x])
			{
				ng[::clr[i]].push_back({::clr[j.x], j.y});
			}
			else
			{
				def[::clr[i]] += f(j.y);
			}
		}
	}
	
	int s;
	cin >> s;
	
	memset(u, 0, sizeof u);
	cout << dfs_ans(::clr[s]) << endl;
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