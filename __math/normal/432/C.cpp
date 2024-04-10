#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool prime[100001];
int lower_p[ten(5) + 1];

//f
void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) {
		if (prime[i]) lower_p[i] = i;
		else lower_p[i] = lower_p[i - 1];
	}
}

int place[ten(5)];
int _a[ten(5) + 1];

int main() {
	init_prime();

	int n;
	cin >> n;
	FOR(i, n) {
		int a; cin >> a;
		a--;
		place[a] = i;
		_a[i] = a;
	}
	vector<Pii> ans;
	FOR(i, n) {
		while (place[i] != i) {
			int cur_place = place[i];
			int diff = place[i] - i;
			int use = lower_p[abs(diff) + 1] - 1;
			int other_place;
			if (diff > 0) {
				other_place = place[i] - use;
			} else if (diff < 0) {
				other_place = place[i] + use;
			}
			if (cur_place > other_place) swap(cur_place, other_place);
			ans.emplace_back(cur_place, other_place);
			swap(_a[cur_place], _a[other_place]);
			place[_a[cur_place]] = cur_place;
			place[_a[other_place]] = other_place;
		}
	}

	printf("%d\n", sz(ans));
	FOR(i, sz(ans)) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);

	return 0;
}