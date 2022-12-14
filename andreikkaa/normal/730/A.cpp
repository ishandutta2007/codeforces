/*
* C++11 code template for contests.
* @author: Andrey Kalendarov
* @e-mail: andreykalendarov@gmail.com
*/

/*______ DEFINES _______*/

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
//#define ANDREIKKAA_TOPCODER
//#define ANDREIKKAA_ALLOCATOR
#define ANDREIKKAA_CLASS Solution
#define ANDREIKKAA_METHOD solve
#define ANDREIKKAA_PARAMETERS void
#define ANDREIKKAA_CALL
#define ANDREIKKAA_RETURN_TYPE void
typedef long long ll;
typedef long double ld;
const int MEMORY_LIMIT_MB = 200;
const int TIME_LIMIT_S = 1;
const char input_filename[] =
#if defined(ANDREIKKAA)
"input.txt"
#else
""
#endif
;
const char output_filename[] =
#if defined(ANDREIKKAA)
""
#else
""
#endif
;

/* ______ INCLUDES ______ */
#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

/* _____ ALLOCATION _____ */

#if defined(ANDREIKKAA_ALLOCATOR)
char alloc_memory[MEMORY_LIMIT_MB * 1000 * 1000];
size_t alloc_pointer = 0;
inline void* operator new(size_t x) { alloc_pointer += x; return alloc_memory + alloc_pointer - x; }
inline void operator delete(void*) { }
#endif

/*____ I-O OPERATORS ____*/
template<typename T, typename U> inline ostream &operator<<(ostream &out, const pair<T, U> &p) { out << p.first << ' ' << p.second; return out; }
template<typename T, typename U> inline istream &operator >> (istream &in, pair<T, U> &p) { in >> p.first >> p.second; return in; }
template<typename T> inline ostream &operator<<(ostream &out, const vector<T> &v) { if (v.empty()) return out; out << v.front(); for (auto it = ++v.begin(); it != v.end(); ++it) out << ' ' << *it; return out; }
template<typename T> inline istream &operator >> (istream &in, vector<T> &v) { for (auto &i : v) in >> i; return in; }

/* ________ CODE ________ */

vector<string> ans;

void fuck(string &s, vector<pair<int, int>> &v, int x)
{
	s[v[x].second] = '1';
	v[x].first = max(v[x].first - 1, 0);
}

void play(vector<pair<int, int>> &v, int x, int y)
{
	string s(v.size(), '0');
	fuck(s, v, x);
	fuck(s, v, y);
	ans.push_back(s);
}

void play(vector<pair<int, int>> &v, int x, int y, int z)
{
	string s(v.size(), '0');
	fuck(s, v, x);
	fuck(s, v, y);
	fuck(s, v, z);
	ans.push_back(s);
}

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0 ; i< n; ++i)
	{
		cin >> v[i].first;
		v[i].second = i;
	}

	if (n == 2)
	{
		if (v[0].first == v[1].first)
		{
			cout << v[rand() & 1].first << endl;
			cout << 0 << endl;
		}
		else
		{
			cout << 0 << endl;
			cout << max(v[0].first, v[1].first) << endl;
			for (int i = 0; i < max(v[0].first, v[1].first); ++i)
			{
				cout << "11" << endl;
			}
		}
		return;
	}

	sort(v.begin(), v.end());

	while (v[v.size() - 1].first != v[v.size() - 2].first)
	{
		play(v, v.size() - 1, v.size() - 3);
		sort(v.begin(), v.end());
	}

	while (v.front().first != v.back().first)
	{
		int p = n - 2;
		for (; p >= 0; --p)
		{
			if (v[p].first != v[p + 1].first)
			{
				++p;
				break;
			}
		}
		for (; p < n; )
		{
			if (n - p >= 5 or n - p == 3)
			{
				play(v, p, p + 1, p + 2);
				p += 3;
			}
			else if (n - p == 4 or n - p == 2)
			{
				play(v, p, p + 1);
				p += 2;
			}
			else
			{
				assert(false);
			}
		}
		sort(v.begin(), v.end());
	}

	cout << v[rand() % v.size()].first << endl;
	cout << ans.size() << endl;
	for (auto &i : ans)
		cout << i << endl;
}

class ANDREIKKAA_CLASS
{
public:
	ANDREIKKAA_RETURN_TYPE ANDREIKKAA_METHOD(ANDREIKKAA_PARAMETERS)
	{
#ifdef ANDREIKKAA
		freopen("input.txt", "r", stdin);
#endif
		cin.tie(nullptr);
		ios_base::sync_with_stdio(false);
		//cout << setprecision(20);
		//cout << fixed;
		return mainFunction(ANDREIKKAA_CALL);
	}
#if defined(ANDREIKKAA)
	inline ANDREIKKAA_CLASS() { _start = clock(); }
	inline ~ANDREIKKAA_CLASS() { cerr << "Time: " << (clock() - _start) / (ld)CLOCKS_PER_SEC << endl; }
private:
	time_t _start;
#endif
};

#if defined(ANDREIKKAA) || !defined(ANDREIKKAA_TOPCODER)
int main()
{
	auto _s = new ANDREIKKAA_CLASS; _s->ANDREIKKAA_METHOD(ANDREIKKAA_CALL); delete _s;
#if defined(ANDREIKKAA)
	while (true);
#endif
}
#endif