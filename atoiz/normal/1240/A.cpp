/*input
4
1
100
50 1
49 1
100
8
100 200 100 200 200 200 100 100
10 2
15 3
107
3
1000000000 1000000000 1000000000
50 1
50 1
3000000000
5
200 100 100 100 100
69 5
31 2
90

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

int solve()
{
	int n; cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) cin >> A[i];
	for (int i = 0; i < n; ++i) A[i] /= 100;
	sort(ALL(A)); reverse(ALL(A));
	
	vector<ll> B(n + 1, 0);
	for (int i = 0; i < n; ++i) B[i + 1] = B[i] + A[i];
	// for (int i = 0; i < n; ++i) cout << B[i + 1] << ' '; cout << endl;

	int x, y, a, b;
	cin >> x >> a >> y >> b;
	if (x < y) swap(x, y), swap(a, b);

	long long k;
	cin >> k;

	int cntA = 0, cntB = 0, cntAB = 0;
	for (int i = 1; i <= n; ++i) {
		if (i % a == 0 && i % b == 0) ++cntAB;
		else if (i % a == 0) ++cntA;
		else if (i % b == 0) ++cntB;
		// cout << B[cntAB] * (x + y) + (B[cntAB + cntA] - B[cntAB]) * x + (B[cntAB + cntA + cntB] - B[cntAB + cntA] * y) << endl;
		if (B[cntAB] * (x + y) + (B[cntAB + cntA] - B[cntAB]) * x + (B[cntAB + cntA + cntB] - B[cntAB + cntA]) * y >= k) return i;
	}
	return -1;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q; cin >> q;
	while (q--) {
		cout << solve() << '\n';
	}

	return 0;
}