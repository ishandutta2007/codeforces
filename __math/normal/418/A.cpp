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
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool used[1000][1000];

int main() {
	int n, k; cin >> n >> k;

	if (n <= 2) {
		puts("-1");
		return 0;
	}

	vector<Pii> anses;
	bool ok = true;
	FOR(i, n) FOR(j, k) {
		int ni = (i + j + 1) % n;
		if (i == ni || used[ni][i]) {
			ok = false;
			break;
		}
		used[i][ni] = used[ni][i] = true;
		anses.emplace_back(i, ni);
	}
	if (!ok) {
		puts("-1");
		return 0;
	}

	printf("%d\n",sz(anses));
	for (auto i : anses) {
		printf("%d %d\n", i.first + 1, i.second + 1);
	}

	return 0;
}