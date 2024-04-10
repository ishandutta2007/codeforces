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
const int INF = 1000000000 + 1; //1e9 + 1

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int n,k;
int a[24];
int X[2];

int sum[1<<24];
int memo[1<<24];

void calc_sum(){
	sum[0] = 0;
	FOR(i,n){
		int x = 1<<i;
		FOR(j,x){
			ll b = sum[j] + (ll)a[i];
			sum[j+x] = b > INF ? INF : (int)b;
		}
	}
}

bool contain(int sm){
	FOR(i,k) if(X[i] == sm) return true;
	return false;
}

int dp(){
	memo[(1<<n)-1] = 1;

	for(int S = (1<<n)-2; S >= 0; S--){
		int val = ((1<<n)-1) ^ S;
		int sm = 0;
		if(contain(sum[val])) continue;
		for(int v = 0; v < n; v++){
			if(!(S & (1<<v))){
				sm += memo[S | (1<<v)];
				if(sm > MOD) sm -= MOD;
			}
		}
		memo[S] = sm;
	}

	return memo[0];
}

int main(){
	cin>>n; FOR(i,n) cin>>a[i];
	cin>>k; FOR(i,k) cin>>X[i];

	memset(sum,-1,sizeof(sum));
	memset(memo,0,sizeof(memo));

	calc_sum();
	int ans = dp();

	cout << ans << endl;

	return 0;
}