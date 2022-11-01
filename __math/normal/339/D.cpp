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
const int MOD = 1000000009; // check!!!
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

int memo[18][1<<17];

int main(){
	int n,m; cin>>n>>m;
	FOR(i,1<<n) cin>>memo[0][i];

	FOR(i,n){
		int x = (1<<(n-i-1));
		FOR(j,x){
			if(i&1) memo[i+1][j] = (memo[i][2*j] ^ memo[i][2*j+1]);
			else    memo[i+1][j] = (memo[i][2*j] | memo[i][2*j+1]);
		}
	}

	FOR(i,m){
		int p,b; cin>>p>>b;
		p--;
		memo[0][p] = b;
		FOR(i,n){
			int np = (p%2) ? p-1 : p+1;
			if(i&1) b ^= memo[i][np];
			else    b |= memo[i][np];
			p /= 2;
			memo[i+1][p] = b;
		}
		cout << b << endl;
	}
}