/*input
4
51 25 99 25


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

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n + 1);
	FOR(i, 1, n) cin >> a[i];

	vector<int> b;
	int s = 0, s1 = 0;
	FOR(i, 1, n) {
		s += a[i];
		if (i == 1 || a[i] * 2 <= a[1]) {
			b.push_back(i);
			s1 += a[i];
		}
	}

	if (s1 <= s - s1) return cout << 0, 0;
	cout << b.size() << endl;
	for (int i : b) cout << i << ' ';

	return 0;
}