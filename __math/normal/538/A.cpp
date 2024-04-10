#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
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

// #pragma comment(linker,"/STACK:36777216")

int main() {
	string s = "CODEFORCES";
	string t; cin >> t;
	if (sz(t) < sz(s)) {
		puts("NO");
		return 0;
	}

	int l = 0;
	while (l < sz(s) && t[l] == s[l]) l++;
	int r = 0;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	while (r < sz(s) && t[r] == s[r]) r++;
	puts(l + r >= sz(s) ? "YES" : "NO");
}