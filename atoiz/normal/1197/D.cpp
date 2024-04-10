/*input
5 2 1000
-13 -4 -9 -20 -11


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

const int MAXN = 300020;
ll A[MAXN], K;
int N, M;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d %d %I64d", &N, &M, &K);
	FOR(i, 0, N - 1) scanf("%I64d", &A[i]);

	ll ans = 0;
	FOR(rem, 0, M - 1) {
		for (int i = rem; i < N; i += M) A[i] -= K;

		ll cur = 0;
		FOR(i, rem, N - 1) {
			if (cur < 0 && i % M == rem) cur = 0;
			cur += A[i];
			if (cur > ans) ans = cur;
		}

		for (int i = rem; i < N; i += M) A[i] += K;
	}	
	
	cout << ans << endl;

	return 0;
}