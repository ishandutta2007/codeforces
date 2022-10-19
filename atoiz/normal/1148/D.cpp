/*input
3
5 4
3 2
6 1

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

struct Pair
{
	int l, r, id;
} A[MAXN], B[MAXN];
int aptr = 0, bptr = 0;

int N;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	FOR(i, 1, N) {
		Pair p;
		scanf("%d %d", &p.l, &p.r);
		p.id = i;
		if (p.l < p.r) A[aptr++] = p;
		else B[bptr++] = p;
	}

	if (aptr > bptr) {
		sort(A, A + aptr, [&](Pair a, Pair b) { return a.r > b.r; });
		printf("%d\n", aptr);
		FOR(i, 0, aptr - 1) printf("%d ", A[i].id);
	} else {
		sort(B, B + bptr, [&](Pair a, Pair b) { return a.l < b.l; });
		printf("%d\n", bptr);
		FOR(i, 0, bptr - 1) printf("%d ", B[i].id);
	}

	return 0;
}