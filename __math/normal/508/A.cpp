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

bool board[1020][1020];

bool f(int a, int b){
	return board[a][b] && board[a - 1][b - 1] && board[a - 1][b] && board[a][b - 1];
}

bool check(int a, int b){
return f(a, b) || f(a+1, b) || 
	f(a, b+1) || f(a+1, b+1);
}

int main(){
	int n, m, k; cin >> n >> m >> k;
	int ans = 0;
	FOR(i, k) {
		int a, b; cin >> a >> b;
		board[a][b]++;
		if (check(a, b)) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << endl;
}