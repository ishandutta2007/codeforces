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


int main() {
	int n, k; cin >> n >> k;
	if (n == 1 && k == 0) {
		puts("1");
		return 0;
	}
	if (n == 1 || n / 2 > k) {
		puts("-1");
		return 0;
	}

	int n2 = n / 2;
	int rem = k - n2 + 1;
	int m = (n2 - 1) * 2 + n % 2;
	vector<int> ans;
	int cnt = 1;
	ans.push_back(rem);
	ans.push_back(rem * 2);
	FOR(i, n2 - 1) {
		if (rem == cnt || rem == cnt + 1 || rem * 2 == cnt || rem * 2 == cnt + 1) {
			i--;
			cnt++;
			continue;
		} else {
			ans.push_back(cnt);
			ans.push_back(cnt + 1);
		}
		cnt += 2;
	}
	if (n % 2) {
		while (rem == cnt || rem == cnt + 1 || rem * 2 == cnt || rem * 2 == cnt + 1) cnt++;
		ans.push_back(cnt);
	}
	FOR(i, n) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}


	return 0;
}