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

vector<int> vec(vector<int> a, vector<int> b)
{
	for(int i = 0; i < 5; ++i)
	{
		b[i] -= a[i];
	}
	return b;
}

int sc(vector<int> a, vector<int> b)
{
	int res = 0;
	for(int i= 0; i < 5; ++i)
	{
		res += a[i] * b[i];
	}
	return res;
}

bool f(const vector<vector<int>> &p, int a, int b, int c)
{
	return sc(vec(p[a], p[b]), vec(p[a], p[c])) > 0;
}


inline void mainFunction()
{
	int n;
	cin >> n;
		
	vector<vector<int>> p;
	p.assign(n, vector<int>(5));
	cin >> p;
	
	if(n <= 2)
	{
		cout << n << endl;
		for(int i = 1; i <= n; ++i)
		{
			cout << i << endl;
		}
		return;
	}
	
	vector<int> st(n);
	vector<int> unk, ok;
	
	for(int i = 0; i < n; ++i)
	{
		unk.push_back(i);
	}
	
	while(!unk.empty())
	{
		if(sz(unk) >= 3)
		{
			int ss = sz(unk);
			if(f(p, unk[ss - 1], unk[ss - 2], unk[ss - 3]))
			{
				ok.push_back(unk[ss - 1]);
				st[unk[ss - 1]] = 2;
				unk.pop_back();
				continue;
			}
			else
			{
				ok.push_back(unk[ss - 2]);
				ok.push_back(unk[ss - 3]);
				st[unk[ss - 2]] = 2;
				st[unk[ss - 3]] = 2;
				unk.erase(unk.end() - 3, unk.end() - 1);
				continue;
			}
		}
		else if(sz(unk) == 2)
		{
			if(f(p, unk[0], unk[1], ok[0]))
			{
				ok.push_back(unk[0]);
				st[unk[0]] = 2;
				unk.erase(unk.begin());
				continue;
			}
			else
			{
				ok.push_back(unk[1]);
				st[unk[1]] = 2;
				unk.pop_back();
				continue;
			}
		}
		else
		{
			for(int i : ok)
			{
				for(int j : ok)
				{
					if(i == j)
					{
						continue;
					}
					
					if(f(p, unk[0], i, j))
					{
						cout << 0 << endl;
						return;
					}
				}
			}
			cout << 1 << endl;
			cout << unk[0] + 1 << endl;
			return;
		}
	}
	assert(false);
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