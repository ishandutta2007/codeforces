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

ll a[2* ten(5) + 10];
int n; 
ll dp[2][2 * ten(5) + 10];
bool used[2][2 * ten(5) + 10];

ll dfs(bool b,int idx){
	if(dp[b][idx] != -2) return dp[b][idx];
	if(	used[b][idx] ) return dp[b][idx] = -1;

	used[b][idx] = true;

	ll nxt = idx;
	if(b) nxt -= a[idx];
	else nxt += a[idx];

	ll ret;

	if(nxt <= 1 || nxt > n){
		if(nxt == 1) ret = -1;
		else ret = a[idx];
	} else {
		ll d = dfs(!b,nxt);
		if(d == -1) ret = -1;
		else ret = d + a[idx];
	}

	used[b][idx] = false;
	return dp[b][idx] = ret;
}

int main(){
	cin>>n;
	FOR(i,n-1) cin>>a[i+2];

	FOR(i,2) FOR(j,2 * ten(5) + 10) dp[i][j] = -2;

	for(int i = 1; i < n; i++){
		ll ret = dfs(true,i+1);
		if(ret != -1) ret += i;
		if(ret == -1) cout << -1 << endl;
		else cout << ret << endl;
	}

	return 0;
}