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
	int n; cin >> n;
	vector<int> a(n);
	FOR(i, n) cin >> a[i];

	vector<int> b = a;
	sort(b.begin(), b.end());

	vector<Pii> ans;
	FOR(i, n){
		if (a[i] == b[i]) continue;
		int id = find(a.begin() + i, a.end(), b[i]) - a.begin();
		ans.emplace_back(i, id);
		swap(a[i], a[id]);
	}
	printf("%d\n", sz(ans));
	for (auto kv : ans) {
		printf("%d %d\n", kv.first, kv.second);
	}
}