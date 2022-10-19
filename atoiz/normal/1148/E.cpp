/*input
3
1 5 10
3 5 7

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

const int MAXN = 300010;

int N;
pii S[MAXN];
int T[MAXN];
int change[MAXN];
#define inc incc
#define dec decc
int inc[MAXN], iptr = 0, dec[MAXN], dptr = 0;

int ans[MAXN][3], aptr = 0;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d", &N);

	FOR(i, 1, N) {
		scanf("%d", &S[i].fi);
		S[i].se = i;
	}

	FOR(i, 1, N) scanf("%d", &T[i]);

	sort(S + 1, S + 1 + N); sort(T + 1, T + N + 1);

	long long total = 0;
	FOR(i, 1, N) {
		change[i] = T[i] - S[i].fi;
		// cout << S[i].se << ": " << change[i] << endl;
		total += change[i];

		if (change[i] < 0) dec[dptr++] = i;
		else if (change[i] > 0) inc[iptr++] = i;
	}

	if (total != 0) return 0 * puts("NO");

	int i = 0, j = 0;
	while (i < iptr && j < dptr) {
		int l = inc[i], r = dec[j];
		if (l > r) return 0 * puts("NO");

		int d = min(change[l], -change[r]);

		ans[aptr][0] = S[l].se, ans[aptr][1] = S[r].se, ans[aptr][2] = d; ++aptr;

		S[l].fi += d, S[r].fi -= d;
		change[l] -= d, change[r] += d;

		if (change[l] == 0) ++i;
		if (change[r] == 0) ++j;
	}

	assert(i == iptr && j == dptr);

	puts("YES");
	printf("%d\n", aptr);
	FOR(i, 0, aptr - 1) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);

	return 0;
}