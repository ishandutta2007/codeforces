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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

bool num[ten(6) + 1];
int ok[ten(6) + 1];

bool C(int h){
	memset(ok, 0, sizeof(ok));
	for (int i = h + 1; i <= ten(6); i++) {
		if (!num[i]) continue;
		for (int j = i; j <= ten(6); j += i) {
			if(j + h <= ten(6)) ok[j + h] += 1;
			if (j + i <= ten(6)) ok[j + i] -= 1;
		}
	}
	FOR(i, ten(6)){
		ok[i + 1] += ok[i];
	}
	FOR(i,ten(6)+1) 
		if (ok[i] && num[i]) return true;
	return false;
}

int main() {
	int n; scanf("%d", &n);
	FOR(i, n){
		int a; scanf("%d", &a);
		num[a] = true;
	}

	int l = 0, r = ten(6) + 1;
	while (r - l != 1) {
		int md = (l + r) / 2;
		bool b = C(md);
		if (b) l = md;
		else r = md;
	}

	printf("%d\n",l);

}