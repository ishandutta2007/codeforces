#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define all(c) (c).begin(),(c).end()
#define FILL(c,val) memset((c),val,sizeof(c))

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;


//BEGIN!!!
int n,m;
int table[505][505];
int sum[505][505]; //1-indexed
int spl[505][505];

int block(int t,int b,int l,int r){
	return sum[b+1][r+1] - sum[b+1][l] - sum[t][r+1] + sum[t][l];
}

int main(){

	cin>>n>>m;
	FOR(i,n) FOR(j,m) cin>>table[i][j],spl[i][j] = table[i][j];
	FOR(i,n){
		int a = 0;
		FOR(j,m){
			a += table[i][j];
			sum[i+1][j+1] = sum[i][j+1] + a;
		}
	}

	int ans = INT_MIN;
	for(int k = 3; k <= n && k <= m; k += 2){
		FOR(i,n-k+1) FOR(j,m-k+1){
			spl[i][j] = block(i,i+k-1,j,j+k-1) - table[i+1][j] - spl[i+1][j+1];
			ans = max(ans,spl[i][j]);
		}
	}
	cout << ans << endl;

	return 0;
}