/*input
2 2 4 4 2
1 10
10 20
	

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

const int MAXN = 200100;

int N, M, ta, tb, K;
int A[MAXN], B[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d %d %d %d %d", &N, &M, &ta, &tb, &K);
	if (K >= min(N, M)) return 0 * puts("-1");
	FOR(i, 1, N) scanf("%d", &A[i]);
	FOR(i, 1, M) scanf("%d", &B[i]);

	int ans = 0;
	for (int i = 0, j = 1; i < N && i <= K; ++i) {
		while (j <= M && A[i + 1] + ta > B[j]) ++j;
		int k = j + K - i;
		if (k > M) return 0 * puts("-1");
		ans = max(ans, B[k] + tb);
	}

	printf("%d", ans);

	return 0;
}