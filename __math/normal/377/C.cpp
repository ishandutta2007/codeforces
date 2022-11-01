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

int n,m;
vector<int> s;
char action[20];
int mv[20];

int memo[1 << 20];

int dfs(int cur, int S){
	if (memo[S] != INF) return memo[S];
	if (cur == m) return memo[S] = 0;

	int cur_pt = INF;

	FOR(i, m) if ((S & (1 << i)) == 0){
		int add_pt = 0;
		if (action[cur] != 'b'){
			if (mv[cur] == 1) add_pt += s[i];
			else add_pt -= s[i];
		}
		int one_pt = dfs(cur + 1, S | (1 << i));
		one_pt += add_pt;
		if (cur_pt == INF) cur_pt = one_pt;
		if (mv[cur] == 1) cur_pt = max(cur_pt, one_pt);
		else cur_pt = min(cur_pt, one_pt);
	}

	return memo[S] = cur_pt;
}

int main(){
	cin >> n;
	s.resize(n);
	FOR(i, n) cin >> s[i];
	cin >> m;
	FOR(i, m) cin >> action[i] >> mv[i];
	
	sort(s.rbegin(), s.rend());
	s.erase(s.begin() + m, s.end());
	reverse(s.begin(), s.end());

	FOR(i, 1 << 20) memo[i] = INF;

	int ans = dfs(0, 0);

	cout << ans << endl;

	return 0;
}