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


int main(){
	ll a[2], b[2];
	FOR(i, 2) cin >> a[i] >> b[i];
	ll oa[2], ob[2];
	FOR(i, 2) oa[i] = a[i], ob[i] = b[i];

	ll l[2]; FOR(i, 2) l[i] = a[i] * b[i];
	int mt = 0;

	int t[2][2] = {};
	FOR(i, 2){
		while (l[i] % 2 == 0) t[i][0]++, l[i] /= 2, (a[i] % 2 == 0 ? a[i] : b[i]) /= 2;
		while (l[i] % 3 == 0) t[i][1]++, l[i] /= 3, (a[i] % 3 == 0 ? a[i] : b[i]) /= 3;
	}

	if (l[0] != l[1]) {
		puts("-1");
		return 0;
	} else {
		int ans = 0;
		while (t[0][1] != t[1][1]) {
			int id = t[0][1] > t[1][1] ? 0 : 1;
			t[id][1]--;
			t[id][0]++;
			((oa[id] % 3 == 0 ? oa[id] : ob[id]) /= 3) *= 2;
			ans++;
		}
		while (t[0][0] != t[1][0]) {
			int id = t[0][0] > t[1][0] ? 0 : 1;
			t[id][0]--;
			ans++;
			((oa[id] % 2 == 0 ? oa[id] : ob[id]) /= 2) *= 1;
		}
		printf("%d\n", ans);

		cout << oa[0] << " " << ob[0] << endl;
		cout << oa[1] << " " << ob[1] << endl;
	}

}