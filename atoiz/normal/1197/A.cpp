/*input
4
4
1 3 1 3
3
3 3 2
5
2 3 3 4 2
3
1 1 2

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

const int MAXN = 100300;
int A[MAXN], N;

int solve()
{
	FORB(i, N - 2, 0) {
		if (A[i + 1] >= 2) return i;
	}
	return 0;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> N;
		FOR(i, 0, MAXN - 1) A[i] = 0;
		FOR(i, 0, N - 1) {
			int x; cin >> x;
			++A[x];
		}
		FORB(i, MAXN - 2, 0) A[i] += A[i + 1];
		cout << solve() << '\n';
	}

	return 0;
}