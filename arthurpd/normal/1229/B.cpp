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

ll x[MAXN];
vector<int> graph[MAXN];
ll ans = 0;
const ll mod = 1000000007;

void dfs(int a, int p, const map<ll,ll> &rdm)
{
	map<ll,ll> cur;
	cur[x[a]] = 1;
	for (auto kvp : rdm)
		cur[__gcd(x[a], kvp.first)] += kvp.second;

	//~ ll prev=  ans;
	for (auto kvp : cur)
		ans = (ans + (kvp.first % mod) * kvp.second) % mod;
	
	//~ debug(a, ans - prev);
	
	for (int i = 0; i < sz(graph[a]); i++)
		if (graph[a][i] != p)
			dfs(graph[a][i], a, cur);
}

int main()
{
	cin.sync_with_stdio(0);
 	cin.tie(0);
 	
 	int n, a, b;
 	cin >> n;
 	for (int i = 1; i <= n; i++)
		cin >> x[i];

 	for (int i = 1; i < n; i++)
 	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	map<ll,ll> tmp;
	
	dfs(1, 1, tmp);

	cout << ans << endl;
}