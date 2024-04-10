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

int a[100];

int main(){
	int n, k; cin >> n >> k;
	FOR(i, n) cin >> a[i];

	vector<Pii> v;
	FOR(i, n) v.emplace_back(a[i], i + 1);
	sort(v.begin(), v.end());

	vector<int> ans;
	FOR(i, n){
		if (k >= v[i].first) {
			k -= v[i].first;
			ans.push_back(v[i].second);
		}
	}
	sort(ans.begin(), ans.end());
	
	printf("%d\n", sz(ans));
	FOR(i, sz(ans)) printf("%d%c", ans[i], i == sz(ans) - 1 ? '\n' : ' ');
}