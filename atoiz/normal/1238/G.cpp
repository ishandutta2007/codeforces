/*input
4
1 5 4 2
2 4 2
0 4 5 4
2 5 3 1
1 2 4
3 1 3
2 3 5 1
2 1 1
1 4 3

*/

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
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 5e5 + 7;
int N, M, C, C0;
tuple<int, int, int> friends[MAXN];
map<int, int> storage;

int read()
{
	int ans = 0; register char ch = getchar();
	for (; ch < 48 || 57 < ch; ch = getchar());
	for (; 47 < ch && ch < 58; ch = getchar()) ans = ans * 10 + ch - 48;
	return ans;
}

ll solve()
{
	N = read(), M = read(), C = read(), C0 = read();
	for (int i = 0; i < N; ++i) {
		int t = read(), a = read(), b = read();
		friends[i] = make_tuple(t, a, b);
	}
	friends[N++] = make_tuple(0, C0, 0);
	friends[N++] = make_tuple(M, 0, 0);

	sort(friends, friends + N);

	storage.clear();
	int curTime = 0, storageSize = 0;
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		int t, a, b;
		tie(t, a, b) = friends[i];
		// cout << t << ' ' << a << ' ' << b << endl;
		while (curTime < t) {
			if (storage.empty()) return -1;
			auto p = storage.begin();
			int add = min(t - curTime, p->se);
			ans += 1ll * add * p->fi;
			curTime += add;
			storageSize -= add;
			p->se -= add;
			if (!p->se) storage.erase(storage.begin());
		}

		storage[b] += a;
		storageSize += a;
		while (storageSize > C) {
			auto p = prev(storage.end());
			int rem = min(storageSize - C, p->se);
			storageSize -= rem;
			p->se -= rem;
			if (!p->se) storage.erase(prev(storage.end()));	
		}
	}
	return ans;
}

signed main()
{
	int t = read();
	while (t--) printf("%I64d\n", solve());

	return 0;
}