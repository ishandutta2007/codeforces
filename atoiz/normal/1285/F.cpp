/*input
3
13 35 77


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
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

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

const int MAX = 100001, CUTOFF = 300;
bitset<MAX> all_set[CUTOFF], flag;
bool is_prime[MAX];
vector<int> prime_factors[MAX];
int N;

int read()
{
	register int ans = 0;
	register char ch = getchar();
	for (; ch < 48 || ch > 57; ch = getchar());
	for (; 47 < ch && ch < 58; ch = getchar()) ans = ans * 10 + ch - 48;
	return ans;
}

signed main()
{
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 2; i < MAX; ++i) is_prime[i] = 1;
	for (int i = 2; i < MAX; ++i) prime_factors[i].reserve(8);
	for (int i = 2; i < MAX; ++i) {
		prime_factors[i].push_back(i);
		for (int j = i + i; j < MAX; j += i) {
			is_prime[j] = 0;
			prime_factors[j].push_back(i);
		}
	}

	for (int i = 2; i < CUTOFF; ++i) {
		all_set[i].flip();
		for (int j = i; j < MAX; j += i) {
			all_set[i][MAX - j] = 0;
		}
	}

	N = read();
	for (int i = 0; i < N; ++i) {
		flag[MAX - read()] = 1;
	}

	for (int i = MAX - 1; i > 0; --i) {
		if (flag[MAX - i]) {
			for (int x : prime_factors[i]) {
				flag[MAX - i / x] = 1;
			}
		}
	}

	for (int i = 2; i < CUTOFF; ++i) {
		if (is_prime[i]) {
			all_set[i] &= flag;
		}
	}

	ll ans = 0;
	bitset<MAX> cur;
	for (int i = MAX - 1; i > 0 && 1ll * i * i > ans; --i) if (flag[MAX - i]) {
		cur = flag;

		for (int x : prime_factors[i]) if (x < CUTOFF) {
			cur &= all_set[x];
		}

		for (int j = (int) cur._Find_first(); j < MAX && 1ll * (MAX - j) * i > ans; j = cur._Find_next(j)) {
			if (__gcd(MAX - j, i) == 1) {
				ans = max(ans, 1ll * (MAX - j) * i);
				break;
			}
		}
	}

	cout << ans << endl;
	// cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;

	return 0;
}