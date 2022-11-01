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

int solve(int n, int m, int i, int j, int a, int b){
	n -= i;
	m -= j;
	if (n % a != 0 || m % b != 0){
		return INF;
	}
	n /= a;
	m /= b;

	if ((n + m) % 2 != 0){
		return INF;
	}

	return abs((n + m) / 2) + abs((n - m) / 2);
}

int main(){
	int n, m, i, j, a, b;
	cin >> n >> m >> i >> j >> a >> b;

	int ans = 1;

	if ((i - 1 < a && n - i < a) || (j - 1 < b && m - j < b)){
		if ((i == 1 || i == n) && (j == 1 || j == m)) ans = 0;
		else ans = INF;
	}
	if (ans == 1){
		int ans1 = solve(1, 1, i, j, a, b);
		int ans2 = solve(1, m, i, j, a, b);
		int ans3 = solve(n, 1, i, j, a, b);
		int ans4 = solve(n, m, i, j, a, b);

		ans = min(min(ans1, ans2), min(ans3, ans4));
	}

	if (ans == INF) cout << "Poor Inna and pony!" << endl;
	else cout << ans << endl;

	return 0;
}