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
	int n; cin >> n;
	int a[10] = {};
	for (int p = 0; p < 10; p++) {
		a[p] += n % 10;
		n /= 10;
	}
	vector<string> vs;
	for (int i = 1; i <= 9; i++) {
		string s;
		FOR(j, 10){
			if (a[j]) {
				s.push_back('1');
				a[j]--;
			} else s.push_back('0');
		}
		while (sz(s) && s.back() == '0') s.pop_back();
		reverse(s.begin(), s.end());
		if (sz(s)) vs.push_back(s);
	}

	cout << sz(vs) << endl;
	for (auto x : vs) cout << x << " ";
	cout << endl;
}