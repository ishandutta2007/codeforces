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

vector<int> solve(string s){
	const vector<int> NO = { -1 };
	int a = 0, b = 0, c = 0;
	int cur = 0;
	for (auto x : s) {
		if (x == '(') a++, cur++;
		else if (x == ')') b++, cur--;
		else cur--, c++;
		if (cur < 0) return NO;
	}

	vector<int> ret;
	FOR(i, c) ret.push_back(1);
	ret[sz(ret) - 1] += cur;

	string s2;
	int y = 0;
	for (auto x : s) {
		if (x != '#') s2.push_back(x);
		else {
			FOR(_, ret[y]) s2.push_back(')');
			y++;
		}
	}

	a = 0, b = 0, c = 0;
	cur = 0;
	for (auto x : s2) {
		if (x == '(') a++, cur++;
		else if (x == ')') b++, cur--;
		if (cur < 0) return NO;
	}

	return ret;
}

int main(){
	string s;
	cin >> s;
	auto ans = solve(s);
	for (auto x : ans) cout << x << endl;

	return 0;
}