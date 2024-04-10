/*input
6
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long n;
	cin >> n;
	if (n == 1) return cout << 1 << endl, 0;

	vl pfs;
	ll x = n;
	for (ll i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			pfs.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) pfs.push_back(x);

	if (SZ(pfs) > 1) return cout << 1 << endl, 0;
	assert(SZ(pfs) == 1);
	cout << pfs[0] << endl;

	return 0;
}