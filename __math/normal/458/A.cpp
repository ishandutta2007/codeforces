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
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int check(vector<int>& v) {
	for (int i = 0; i < sz(v); i++) {
		if (v[i] == 0) continue;
		if (v[i] == 1) {
			if (i + 2 >= sz(v)) return 1;
			if (v[i + 1] == -1){
				if (v[i + 2] == 1) return 1;
				v[i]--;
				v[i + 1]++;
				v[i + 2]++;
			} else {
				return 1;
			}
		} else {
			if (i + 2 >= sz(v)) return -1;
			if (v[i + 1] == 1) {
				if (v[i + 2] == -1) return -1;
				v[i]++;
				v[i + 1]--;
				v[i + 2]--;
			} else {
				return -1;
			}
		}
	}
	return 0;
}

int main() {
	string s, t; cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	vector<int> v;
	FOR(i, max(sz(s), sz(t))){
		v.push_back(0);
		if (i < sz(s)) v[sz(v) - 1] += s[i] - '0';
		if (i < sz(t)) v[sz(v) - 1] -= t[i] - '0';
	}
	reverse(v.begin(), v.end());
	
	int flag = check(v);

	if (flag == 1) puts(">");
	else if (flag == 0) puts("=");
	else puts("<");

	return 0;
}