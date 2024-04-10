#include <bits/stdc++.h>
using namespace std;

template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }

template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}

template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}

template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}

#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) ((int)(x).size())

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }

// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out

#define MAXN 112345

ll deg[MAXN];
vector<int> more_graph[MAXN];

ll calc(int i)
{
	return (deg[i] - sz(more_graph[i])) * 1ll * sz(more_graph[i]);
}

int main()
{
	cin.sync_with_stdio(0);
 	cin.tie(0);
 	
 	int n, m, a, b, q;
 	cin >> n >> m;
 	for (int i = 0; i < m; i++)
 	{
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
		//~ less_graph[max(a, b)].insert(min(a, b));
		more_graph[min(a, b)].push_back(max(a, b));
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += calc(i);
	
	printf("%lld\n", ans);
	cin >> q;
	while (q--)
	{
		cin >> a;
		ans -= calc(a);
		for (int b : more_graph[a])
		{
			ans -= calc(b);

			//~ less_graph[b].erase(a);
			more_graph[b].push_back(a);

			ans += calc(b);
			
			//~ less_graph[a].insert(b);
		}
		
		more_graph[a].clear();

		ans += calc(a);

		printf("%lld\n", ans);
	}
	
}