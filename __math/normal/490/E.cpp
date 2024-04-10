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

int n;
string s[ten(5)];
int cmp[ten(5)];

bool f(string& l, string& r){
	if (sz(l) != sz(r)) return sz(l) < sz(r);
	FOR(i, sz(l)){
		char rv = r[i] == '?' ? '9' : r[i];
		if (l[i] != rv) return l[i] < r[i];
	}
	return false;
}

int main(){
	cin >> n;
	FOR(i, n) cin >> s[i];
	FOR(i, sz(s[0])){
		if (s[0][i] == '?') s[0][i] = (i == 0 ? '1' : '0');
	}
	bool ok = true;
	FOR(i, n - 1){
		FOR(j, sz(s[i+1])){
			if (s[i+1][j] != '?') continue;
			bool h = false;
			FOR(k, 10){
				if (j == 0 && k == 0) continue;
				s[i+1][j] = k + '0';
				bool b2 = f(s[i], s[i + 1]);
				if (b2) {
					h = true;
					break;
				}
			}
			if (!h) break;
		}
		bool b = f(s[i], s[i + 1]);
		if (!b) {
			ok = false;
			break;
		}
	}

	if (!ok) puts("NO");
	else {
		puts("YES");
		FOR(i, n) printf("%s\n",s[i].c_str());
	}
}