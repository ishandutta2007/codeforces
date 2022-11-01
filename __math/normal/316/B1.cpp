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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n,x;
int a[ten(3)];
int dep[ten(3)];
int par[ten(3)];
map<int,int> mp;

bool dp[ten(3) * 2 + 10];

int dfs(int cur){
	if(dep[cur] != -1) return dep[cur];
	if(a[cur] == 0){
		par[cur] = cur;
		mp[cur]++;
		return dep[cur] = 0;
	}

	dep[cur] = dfs(a[cur] - 1) + 1;
	par[cur] = par[a[cur] - 1];
	mp[par[cur]]++;

	return dep[cur];
}

int main() { 
	cin>>n>>x;
	x--;
	FOR(i,n) cin>>a[i];

	memset(dep,-1,sizeof(dep));
	FOR(i,n){
		dfs(i);
	}

	dp[0] = true;
	mp.erase(par[x]);
	for(map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		int b = it->second;
		for(int i = n-1; i >= 0; i--) if(dp[i]){
			dp[i+b] = true;
		}
	}

	vector<int> ans;
	FOR(i,n) if(dp[i]) ans.push_back(i+1 + dep[x]);

	FOR(i,sz(ans)){
		if(ans[i] <= n){
			cout << ans[i] << endl;
		}
	}

	return 0;
}