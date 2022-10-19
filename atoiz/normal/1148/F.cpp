/*input
1
1 1

*/

// https://codeforces.com/blog/entry/67316?#comment-515011

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

const int MAXN = 300100;
int N;
long long A[MAXN], M[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	FOR(i, 1, N) scanf("%I64d %I64d", &A[i], &M[i]);

	long long total = 0;
	FOR(i, 1, N) total += A[i];
	if (total < 0) FOR(i, 1, N) A[i] = -A[i];

	long long s = 0;
	FORB(k, 62, 0) {
		total = 0;
		FOR(i, 1, N) if ((M[i] & ((1ll << k) - 1)) == 0 && ((M[i] >> k) & 1)) total += A[i];
		if (total > 0) {
			FOR(i, 1, N) if ((M[i] >> k) & 1) A[i] = -A[i];
			s ^= (1ll << k);
		}
	}

	total = 0;
	FOR(i, 1, N) total += A[i];
	assert(total < 0);

	printf("%I64d", s);

	return 0;
}