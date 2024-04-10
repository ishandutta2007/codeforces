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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main(){

	int a[3][3];
	FOR(i,3) FOR(j,3) cin>>a[i][j];

	int b[3];
	FOR(i,3) b[i] = accumulate(a[i],a[i]+3,0);
	int id = max_element(b,b+3) - b;
	int sum = b[id] + 1;
	FOR(i,3){
		a[i][i] = sum - b[i];
	}

	int sum2 = a[0][0] + a[1][1] + a[2][2];
	FOR(i,3){
		a[i][i] += (sum - sum2) / 2;
	}

	FOR(i,3){
		printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
	}

    return 0;
}