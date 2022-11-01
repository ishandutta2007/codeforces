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

bool used[ten(5)];
vector<Pii> e[ten(5)];
vector<int> ans;

bool dfs(int cur,bool h){
	used[cur] = true;
	bool ret = false;
	for (auto p : e[cur]) if(!used[p.first]){
		ret |= dfs(p.first,p.second == 2);
	}
	if ((!ret) && h) ans.push_back(cur+1), ret = true;
	return ret;
}

int main(){

	int n; cin >> n;
	FOR(i, n - 1){
		int x, y, t; cin >> x >> y >> t;
		x--, y--;
		e[x].emplace_back(y, t);
		e[y].emplace_back(x, t);
	}

	dfs(0,false);

	printf("%d\n", sz(ans));
	FOR(i, sz(ans)) printf("%d%c", ans[i], i == sz(ans) - 1 ? '\n' : ' ');

	return 0;
}