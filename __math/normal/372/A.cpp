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
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n;
int s[ten(5) * 5];

bool C(int md){
	for (int i = 0; i < md; i++){
		int up = n - md + i;
		if (s[i] * 2 > s[up]) return false;
	}
	return true;
}

int main(){
	 cin >> n;
	FOR(i, n) cin >> s[i];

	sort(s, s + n);

	int l = 0,r = n / 2 + 1;
	while (r - l != 1){
		int md = (l + r) / 2;
		if (C(md)) l = md;
		else r = md;
	}

	int ans = n - l;

	cout << ans << endl;
	return 0;
}