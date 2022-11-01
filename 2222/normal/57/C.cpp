#include <algorithm>
#include <iostream>
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

int inv(int x) {
	int y = mod, a = 1, b = 0, z;
	for (; y; swap(x, y), swap(a, b)) {
		z = x / y;
		x %= y;
		a -= b * z;
	}
	return a < 0 ? a + mod : a;
}

inline int mul(int x, int y) { return (ll)x * y % mod; }

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	int n;
	cin >> n;
	int ra = 1, rb = 1;
	REP (i, n) {
		ra = mul(ra, 2 * n - 1 - i);
		rb = mul(rb, i + 1);
	}
	ra = mul(ra, inv(rb));
	if ((ra += ra) >= mod) ra -= mod;
	if ((ra -= n) < 0) ra += mod;
	cout << ra << endl;
	return 0;
}