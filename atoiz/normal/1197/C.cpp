/*input
8 1
1 1 2 3 5 8 13 21

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

const int MAXN = 301000;
int N, K, A[MAXN], B[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d %d", &N, &K);
	FOR(i, 0, N - 1) scanf("%d", &A[i]);
	int ans = A[N - 1] - A[0];
	FOR(i, 0, N - 2) B[i] = A[i] - A[i + 1];
	sort(B, B + N - 1);
	FOR(i, 0, K - 2) ans += B[i];
	cout << ans << endl;

	return 0;
}