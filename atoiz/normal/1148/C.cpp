/*input
2
2 1

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
int N, A[MAXN], P[MAXN];
pii ans[MAXN * 5];
int ptr = 0;

void doSwap(int i, int j)
{
	ans[ptr++] = pii(i, j);
	swap(P[A[i]], P[A[j]]);
	swap(A[i], A[j]);
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	FOR(i, 1, N) {
		scanf("%d", &A[i]);
		P[A[i]] = i;
	}

	FOR(i, 2, N-1) {
		int a = i, b = P[i];

		if (a == b) continue; 
		if (2 * abs(a - b) >= N) { doSwap(a, b); continue; }
		if (2 * abs(b - 1) >= N) { doSwap(b, 1); b = 1; }
		if (2 * abs(a - b) >= N) { doSwap(a, b); continue; }
		if (2 * abs(b - N) >= N) { doSwap(b, N); b = N; }
		if (2 * abs(a - b) >= N) { doSwap(a, b); continue; }
	}

	if (P[1] != 1) doSwap(1, N);

	// FOR(i, 1, N) assert(A[i] == i && P[i] == i);

	printf("%d\n", ptr);
	FOR(i, 0, ptr - 1) printf("%d %d\n", ans[i].fi, ans[i].se);

	return 0;
}