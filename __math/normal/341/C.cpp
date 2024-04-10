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
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }


ll memo[2010][2010];

ll dfs(int a,int b){
	ll &ret = memo[a][b];
	if(ret != -1) return ret;
	ret = 0;
	if(a == 0 && b == 0) return ret = 1;
	if(b == 0){
		return ret = a * dfs(a-1,0) % MOD;
	}
	if(a > 0){
		ret += a * dfs(a,b-1) % MOD;
	}
	if(b > 1){
		ret += (b-1) * dfs(a+1,b-2) % MOD;
	}

	return ret %= MOD;
}

int a[2000];
bool fr[2000];
bool placed[2000];

int main(){
	memset(memo,-1,sizeof(memo));

	int n; cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(i,n){
		if(a[i] != -1){
			placed[i] = true;
			fr[a[i] - 1] = true;
		}
	}

	int a = 0,b = 0;
	FOR(i,n){
		if(placed[i]) continue;
		if(fr[i]) a++;
		else b++;
	}

	ll ans = dfs(a,b);

	cout << ans << endl;
}