/*input
cabac
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

const int MAXN = 1002000;
int B[3];
int A[MAXN], ptr = 0;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string S; cin >> S;

	int i = 1, j = SZ(S) - 2;
	for (; i < j; i += 2, j -= 2) {
		++B[S[i - 1] - 'a'];
		++B[S[i] - 'a'];
		++B[S[j + 1] - 'a'];
		++B[S[j] - 'a'];

		FOR(z, 0, 2) {
			if (B[z] >= 2) {
				A[ptr++] = z;
				break;
			}
		}
		FOR(z, 0, 2) B[z] = 0;
	}

	FOR(i, 0, ptr - 1) putchar(A[i] + 'a');
	--i, ++j;
	if (i <= j) putchar(S[i]);
	FORB(i, ptr - 1, 0) putchar(A[i] + 'a');

	return 0;
}