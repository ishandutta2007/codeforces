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

const int m = 86;
ll f[m] = {1, 2};
bool v[m];
ll G[m][2];

ll g(int i, bool carry) {
	if (i == -1) return !carry;
	if (i < 0) return 0;
	ll &res = G[i][carry];
	if (res < 0) {
		res = 0;
		if (v[i] && carry) {
			if (i >= 2 && !v[i - 1]) {
				res += g(i - 2, true);
			}
		} else {
			res = g(i - 1, false);
			if (i >= 2 && (carry || v[i]) && !v[i - 1]) {
				res += g(i - 2, true);
			}
		}
	}
	return res;
}

int main() {
	FOR (i, 2, m) {
		f[i] = f[i - 1] + f[i - 2];
	}
	int T;
	for (cin >> T; T --> 0; ) {
		ll x;
		cin >> x;
		for (int i = m - 1; i >= 0; --i) {
			if (f[i] <= x) {
				x -= f[i];
				v[i] = true;
			} else v[i] = false;
		}
		assert(x == 0);
		CL(G, -1);
		cout << g(m - 1, false) << endl;
	}
	return 0;
}