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
template<class T> void chmax(T& a, T b) { a = max(a, b); }
template<class T> void chmin(T& a, T b) { a = min(a, b); }

#pragma comment(linker,"/STACK:36777216")

int main(){

	int n; cin >> n;
	map<int, int> a, b, c;
	FOR(i, n){
		int tmp; cin >> tmp; a[tmp]++;
	}
	FOR(i, n-1){
		int tmp; cin >> tmp; b[tmp]++;
	}
	FOR(i, n-2){
		int tmp; cin >> tmp; c[tmp]++;
	}
	for (auto kv : a) {
		if (kv.second != b[kv.first]) {
			cout << kv.first << endl;
		}
	}
	for (auto kv : b) {
		if (kv.second != c[kv.first]) {
			cout << kv.first << endl;
		}
	}
}