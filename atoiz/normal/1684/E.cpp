#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)
#define SORT(a) sort(begin(a), end(a))

#define SORTUNIQUE(a) sort(begin(a), end(a)), a.erase(unique(begin(a), end(a)), end(a))
#define LB(a,x) ((int) (lower_bound(ALL(a), x) - begin(a)))
#define UB(a,x) ((int) (upper_bound(ALL(a), x) - begin(a)))
#define FORL(i, a, b) for (int64_t i = a; i <= b; ++i)
#define FORBL(i, a, b) for (int64_t i = a; i >= b; --i)
#define FORANOPTR(i, a) for (auto i : a)
#define FORIT(i, a, b) for (auto i = a; i != b; ++i)

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define SP ' '
#define NL '\n'

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
#define fi first
#define se second

template <typename T>
ostream& operator<< (ostream &os, vector<T> &vec) 
{
	if (vec.empty()) return os;
	for (int i = 0; i < (int) vec.size() - 1; ++i) os << vec[i] << ' ';
	return os << vec.back();
}

void DB() {}
template <typename T, typename... Args>
void DB(T t, Args... a)
{
	#ifdef LOCAL
	cout << flush;
	cerr << t;
	DB(a...);
	cerr << flush;
	#endif
}

mt19937 rng((int) chrono::system_clock().now().time_since_epoch().count());

// start of code

void solve() {
	int n, k; cin >> n >> k;
	map<int, int> mp;
	VI a(n); FOR(i, 0, n-1) cin >> a[i], ++mp[a[i]];
	VI b(n, 1); FORA(x, a) if (x < SZ(b)) b[x] = 0;
	FOR(i, 1, SZ(b)-1) b[i] += b[i - 1];
	int s = find(ALL(b), k+1) - b.begin();
	if (s == SZ(b)) return cout << 0 << endl, void(0);
	vector<int> vec;
	for (auto it = mp.rbegin(); it != mp.rend() && it->first >= s; ++it) vec.push_back(it->second);
	sort(vec.rbegin(), vec.rend());
	while (!vec.empty() && vec.back() <= k) k -= vec.back(), vec.pop_back();
	cout << SZ(vec) << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tests; cin >> tests;
	while (tests--) solve();
}