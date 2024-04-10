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
#ifdef ONLINE_JUDGE
#define typeof(X) __typeof(X)
#else
#define typeof(X) decltype(X)
#endif
#define FOREACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define sz(c) ((int)(c).size())

typedef unsigned int ull;

ull* upper[5000];
ull* lower[5000];
int dp[5000][5000];

int main(){
	FOR(i,5000){
		upper[i] = (ull*)calloc(5000-i,sizeof(ull));
		lower[i] = (ull*)calloc(5000-i,sizeof(ull));
	}

	string s; cin>>s;
	int n = sz(s);
	FOR(i,n){
		upper[i][0] = s[i]; 
		for(int j = 1; i+j < n; j++){
			upper[i][j] = upper[i][j-1] * MODULO + s[i+j];
		}
	}
	reverse(s.begin(),s.end());
	FOR(i,n){
		lower[i][0] = s[i]; 
		for(int j = 1; i+j < n; j++){
			lower[i][j] = lower[i][j-1] * MODULO + s[i+j];
		}
	}
	FOR(i,n) dp[i][0] = 1;
	for(int i = 1; i < n; i++){
		for(int l = 0; l + i < n; l++){
			int r = l + i;
			dp[l][i] = dp[l+1][i-1] + dp[l][i-1];
			if(i > 1) dp[l][i] -= dp[l+1][i-2];
			int add = (upper[l][i] == lower[n-1-r][i]);
			dp[l][i] += add;
		}
	}

	int q; cin>>q;
	FOR(i,q){
		int l,r; cin>>l>>r;
		l--; r--;
		cout << dp[l][r-l] << endl;
	}

    return 0;
}