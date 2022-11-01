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


char t[500][501];
int n, m, k;

const int da[] = { 1, 0, -1, 0 }, db[] = { 0, 1, 0, -1 };

Pii first(){
	FOR(i, n) FOR(j, m) if (t[i][j] == '.') return Pii(i, j);
}
bool used[500][500];

void dfs(int i, int j){
	used[i][j] = true;
	FOR(x, 4){
		int ni = i + da[x], nj = j + db[x];
		if (ni < 0 || ni >= n || nj < 0 || nj >= m || used[ni][nj]) continue;
		if (t[ni][nj] != '.') continue;
		dfs(ni, nj);
	}
	if(k) t[i][j] = 'X',k--;
}

int main(){
	cin >> n >> m >> k;
	FOR(i, n) cin >> t[i];

	Pii p = first();
	dfs(p.first,p.second);

	FOR(i, n) cout << t[i] << endl;;

	return 0;
}