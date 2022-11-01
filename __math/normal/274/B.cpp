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


using namespace std;
typedef long long ll;
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<int> e[100000];
ll cost[100000];
bool used[100000];

Pll dfs(int v){
	used[v] = true;
	ll mv_min = 0,mv_plus = 0;
	ll child_move = 0;
	FOR(i,sz(e[v])){
		if(used[e[v][i]]) continue;
		Pll a = dfs(e[v][i]);
		mv_plus = max(mv_plus,a.first);
		mv_min = max(mv_min,a.second);
	}

	ll cur_point = mv_plus - mv_min;
	ll diff = cost[v] - cur_point;
	if(diff > 0){
		mv_plus += diff;
	} else {
		mv_min += -diff;
	}

	return Pll(mv_plus,mv_min);
}

int main(){
	int n; cin>>n;
	FOR(i,n-1){
		int a,b; cin>>a>>b;
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	FOR(i,n) cin>>cost[i];

	Pll ans = dfs(0);

	cout << ans.first + ans.second << endl;

	return 0;
}