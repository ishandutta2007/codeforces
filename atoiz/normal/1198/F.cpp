/*input
4
2 3 6 7

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
#include <random>
#include <chrono>

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

mt19937 rng(chrono::system_clock().now().time_since_epoch().count());

const long long BASE = 1e9 + 7;

void print(vi &P, vi& color)
{
	cout << "YES" << '\n';
	int N = SZ(P);
	vi ans(N);
	FOR(i, 0, N - 1) ans[P[i]] = color[i] + 1;
	FORA(i, ans) cout << i << ' ';
	exit(0);
}

vi factorize(int x)
{
	vi ans;
	int i = 2;
	for (; i * i <= x; ++i) {
		if (x % i == 0) ans.push_back(i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) ans.push_back(x);
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vi A(N);
	FOR(i, 0, N - 1) cin >> A[i];
	
	int tmp = 0;
	FOR(i, 0, N - 1) tmp = __gcd(tmp, A[i]);
	if (tmp > 1) return cout << "NO" << endl, 0;

	vi P(N), color(N);
	iota(ALL(P), 0);
	shuffle(ALL(P), rng);
	vi B(N);
	FOR(i, 0, N - 1) B[i] = A[P[i]];

	tmp = B[0];
	int sz = 1;
	FOR(i, 1, N - 1) {
		if (tmp != __gcd(tmp, B[i])) {
			tmp = __gcd(tmp, B[i]);
			swap(B[i], B[sz]);
			swap(P[i], P[sz]);
			++sz;
		}
	}
	assert(tmp == 1);
	tmp = 0;
	FOR(i, sz, N - 1) tmp = __gcd(tmp, B[i]);
	if (tmp == 1) {
		fill_n(color.begin(), sz, 1);
		print(P, color);
	}

	FOR(i, 0, sz - 1)
	{
		tmp = 0;
		FOR(j, 0, N - 1) if (i != j) tmp = __gcd(tmp, B[j]);
		if (tmp > 1) return cout << "NO" << endl, 0;
	}

	FOR(i1, 0, 0) FOR(i2, i1 + 1, sz - 1) {
		vector<int> f1 = factorize(B[i1]), f2 = factorize(B[i2]);
		vector<unordered_set<int>> dp(N + 1);
		dp[0].insert((1 << (SZ(f1) + SZ(f2))) - 1);

		FOR(i, 0, N - 1) {
			if (i == i1 || i == i2) {
				dp[i + 1] = dp[i];
				continue;
			}
			int m1 = ((1 << SZ(f2)) - 1) << SZ(f1), m2 = (1 << SZ(f1)) - 1;
			FOR(j, 0, SZ(f1) - 1) if (B[i] % f1[j] == 0) m1 ^= (1 << j);
			FOR(j, 0, SZ(f2) - 1) if (B[i] % f2[j] == 0) m2 ^= (1 << (SZ(f1) + j));

			FORA(x, dp[i]) {
				tmp = m1 & m2 & x;
				if ((m2 & x) != tmp) dp[i + 1].insert(m1 & x);
				if ((m1 & x) != tmp) dp[i + 1].insert(m2 & x);
				if ((m1 & x) == (m2 & x)) dp[i + 1].insert(tmp);
			}
		}

		if (dp[N].find(0) == dp[N].end()) continue;

		int last = 0;
		FORB(i, N - 1, 0) {
			if (i == i1) color[i] = 0;
			else if (i == i2) color[i] = 1;
			else {
				int m1 = ((1 << SZ(f2)) - 1) << SZ(f1), m2 = (1 << SZ(f1)) - 1;
				FOR(j, 0, SZ(f1) - 1) if (B[i] % f1[j] == 0) m1 ^= (1 << j);
				FOR(j, 0, SZ(f2) - 1) if (B[i] % f2[j] == 0) m2 ^= (1 << (SZ(f1) + j));

				FORA(x, dp[i]) {
					if ((m1 & x) == last) {
						last = x, color[i] = 0;
						break;
					}
					if ((m2 & x) == last) {
						last = x, color[i] = 1;
						break;
					}
				}
			}
		}
		print(P, color);
	}

	cout << "NO" << endl;

	return 0;
}