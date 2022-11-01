#define _USE_MATH_DEFINES
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

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!
typedef pair<double,int> P;

int gcd(int x,int y){
	int r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}


int main(){

	int w,h;
	cin>>w>>h;
	ll ans = 0;
	for(int i = 2; i <= h; i+= 2) for(int j = 2; j <= w; j+= 2) {
		ans += (h-i+1) * (w-j+1);
	}

	cout << ans << endl;

	return 0;
}