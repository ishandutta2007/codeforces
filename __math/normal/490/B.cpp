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

int a[ten(5) * 2], b[ten(5) * 2];

int main(){
	int n;
	scanf("%d", &n);
	FOR(i, n) scanf("%d%d", a + i, b + i);


	int two = -1;
	FOR(i, n) if (a[i] == 0) two = b[i];

	map<int, int> mp;
	FOR(i, n) mp[a[i]]++, mp[b[i]]++;
	int one = -1;
	vector<int> t;
	for (auto kv : mp) if (kv.second == 1) t.push_back(kv.first);
	FOR(i, n) if (t[0] == a[i] || t[1] == a[i]) one = a[i];

	map<int, int> mp2;
	FOR(i, n) mp2[a[i]] = b[i];

	vector<int> ans;
	FOR(i, n){
		int& use = (i % 2 == 0) ? one : two;
		ans.push_back(use);
		use = mp2[use];
	}

	FOR(i, n) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
}