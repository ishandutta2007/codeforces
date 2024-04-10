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

const int MAX_N = 3002;
const int INF = 100 * 1000 * 1000;

struct rib {
	int b, u, c, f;
	size_t back;
};

void add_rib(vector < vector<rib> > & g, int a, int b, int u, int c) {
	rib r1 = { b, u, c, 0, g[b].size() };
	rib r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back(r1);
	g[b].push_back(r2);
}

int a[MAX_N];
int b[MAX_N];

inline ANDREIKKAA_RETURN_TYPE mainFunction(ANDREIKKAA_PARAMETERS)
{
	int n, p, s;
	cin >> n >> p >> s;
	
	vector<vector<rib>> g(n + 5);
	add_rib(g, n + 1, n + 4, p, 0);
	add_rib(g, n + 2, n + 4, s, 0);
	add_rib(g, n + 3, n + 4, n - p - s, 0);

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
		add_rib(g, 0, i + 1, 1, 0);
		add_rib(g, i + 1, n + 1, 1, -a[i]);
		add_rib(g, i + 1, n + 2, 1, -b[i]);
		add_rib(g, i + 1, n + 3, 1, 0);
	}
	
	int flow = 0, cost = 0;
	int S = 0;
	int T = n + 4;
	int maxx = p + s;
	while (flow < p + s) {
		vector<int> id(n + 5, 0);
		vector<int> d(n + 5, INF);
		vector<int> q(n + 5);
		vector<int> p(n + 5);
		vector<size_t> p_rib(n + 5);
		int qh = 0, qt = 0;
		q[qt++] = S;
		d[S] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n + 5)  qh = 0;
			for (size_t i = 0; i<g[v].size(); ++i) {
				rib & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n + 5)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n + 5 - 1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_rib[r.b] = i;
				}
			}
		}
		if (d[T] == INF)  break;
		int addflow = maxx - flow;
		for (int v = T; v != S; v = p[v]) {
			int pv = p[v];  size_t pr = p_rib[v];
			//cout << pv << " -> " << g[pv][pr].b << endl;
			addflow = min(addflow, g[pv][pr].u - g[pv][pr].f);
		}
		//cout << endl;
		for (int v = T; v != S; v = p[v]) {
			int pv = p[v];  size_t pr = p_rib[v], r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}
	cout << -cost << endl;
	static vector<int> ans[2];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < 3; ++j)
		{
			if (g[i][j].f == 1)
			{
				ans[j - 1].push_back(i);
			}
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j : ans[i])
		{
			cout << j << " ";
		}
		cout << endl;
	}
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