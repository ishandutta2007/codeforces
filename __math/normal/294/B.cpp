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

int width[105][210];

int main(){
	int n; cin>>n;
	int t[100],w[100];
	FOR(i,n){
		cin>>t[i]>>w[i];
	}
	FOR(j,105) FOR(i,210) width[j][i] = -INF;
	width[0][0] = 0;

	FOR(i,n){
		FOR(wd,205){
			width[i+1][wd + t[i]] = max(width[i+1][wd + t[i]],width[i][wd] + t[i]);
			width[i+1][wd] = max(width[i+1][wd],width[i][wd] - w[i]);
		}
	}

	int ans = -1;
	FOR(i,210){
		if(width[n][i] >= 0){
			ans = i;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}