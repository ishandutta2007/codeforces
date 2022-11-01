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
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

void check(vector<int>& v){
	const int n = sz(v);
	bool used[ten(5) + 10] = {};
	int cur = 1;
	bool ok = true;
	for (auto i : v) {
		cur = ll(cur) * i % n;
		if (used[cur]) ok = false;
		used[cur] = true;
	}
	assert(ok);
}

int main(){
	int n; cin >> n;
	if (n <= 3) {
		printf("YES\n");
		FOR(i, n) printf("%d\n", i + 1);
		return 0;
	} else if (n == 4) {
		puts("YES");
		vector<int> ans = { 1, 3, 2, 4 };
		for (auto i : ans) printf("%d\n", i);
	} else {
		bool pr = true;
		for (int i = 2; i < n; i++) if (n % i == 0) pr = false;
		if (!pr) {
			puts("NO");
			return 0;
		}

		int root = 2;
		while (true) {
			static bool pool[ten(5) + 10];
			memset(pool, false, sizeof(pool));
			ll cur = 1;
			bool ok = true;
			FOR(i, n - 1){
				if (pool[(int)cur]) {
					ok = false;
					break;
				}
				pool[(int)cur] = true;
				cur = cur * root % n;
			}
			if (ok) break;
			root++;
		}

		vector<int> ans_e;
		FOR(i, n - 1){
			if (i % 2 == 0) ans_e.push_back(i);
			else ans_e.push_back(n - 1 - i);
		}
		ans_e.push_back(n - 1);

		vector<int> val;
		val.push_back(1);
		FOR(i, n - 2){
			val.push_back(val.back() * ll(root) % n);
		}
		val.push_back(n);
		vector<int> ans;
		for (auto i : ans_e) ans.push_back(val[i]);
		// check(ans);

		puts("YES");
		for (auto i : ans_e) printf("%d\n", val[i]);
	}

	return 0;
}