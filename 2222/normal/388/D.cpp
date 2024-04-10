#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int mod = 1000000007;

inline int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
inline int mul(int x, int y) { return (ll)x * y % mod; }
inline int two(int k) { return (1ll << k) % mod; }
inline int two0(int k) { return k ? two(k - 1) : 1; }

int F[30][2][31];

int f(int K, int i, bool less, int fr) {
	if (i < 0)
		return 1;
	int &res = F[i][less][fr];
	if (res < 0) {
		if (less) {
			res = mul(f(K, i - 1, 1, fr), two(fr));
			res = add(res, f(K, i - 1, 1, fr + 1));
		} else if (K & 1 << i) {
			res = f(K, i - 1, 0, fr + 1);
			if (fr) {
				res = add(res, mul(f(K, i - 1, 0, fr), two0(fr)));
				res = add(res, mul(f(K, i - 1, 1, fr), two0(fr)));
			} else {
				res = add(res, f(K, i - 1, 1, 0));
			}
		} else {
			res = mul(f(K, i - 1, 0, fr), two0(fr));
		}
	}
	return res;
}

int main() {
    for (int k; cin >> k; ) {
		CL(F, -1);
		cout << f(k, 29, 0, 0) << endl;
	}
    return 0;
}