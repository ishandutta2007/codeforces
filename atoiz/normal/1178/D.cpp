/*input
8
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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 3000;
int N;
bool isPrime[MAXN];
vector<pii> edges;

bool solve()
{
	FOR(i, 1, N) edges.emplace_back(i, i % N + 1);
	int cur = N, d = N / 2;
	for (int i = 1; i <= N / 2 && !isPrime[cur]; ++i, ++cur) {
		edges.emplace_back(i, (i + d - 1) % N + 1);
	}
	return isPrime[cur];
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	FOR(i, 2, MAXN - 1) isPrime[i] = 1;
	FOR(i, 2, MAXN - 1) if (isPrime[i]) for (int j = i + i; j < MAXN; j += i) isPrime[j] = 0;

	cin >> N;
	solve();

	cout << SZ(edges) << '\n';
	FORA(a, edges) cout << a.fi << ' ' << a.se << '\n';

	return 0;
}