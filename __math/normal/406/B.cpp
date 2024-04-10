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

bool x[ten(6)];
int main() {
	const int s = ten(6);
	int n;
	scanf("%d", &n);
	FOR(i, n) {
		int tmp; scanf("%d",&tmp);
		x[tmp - 1] = true;
	}

	vector<int> ans;
	int cnt = 0;
	vector<Pii> ok_lists;
	FOR(i, s / 2) {
		if (x[i] && x[s - i - 1]) cnt++;
		else if (x[i] || x[s - i - 1]) {
			if (x[i]) ans.push_back(s - i);
			else ans.push_back(i + 1);
		} else {
			ok_lists.push_back(Pii(i + 1, s - i));
		}
	}
	FOR(i, cnt) {
		ans.push_back(ok_lists[i].first);
		ans.push_back(ok_lists[i].second);
	}

	printf("%d\n", sz(ans));
	FOR(i, sz(ans)) printf("%d%c", ans[i], i == sz(ans) - 1 ? '\n' : ' ');

	return 0;
}