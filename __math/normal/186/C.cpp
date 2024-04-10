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

//bool comp(const P& x,const P& y)
//{
//	return greater<double>()(x.first,y.first);
//}

ll get_pow(ll n)
{
	ll x = 2;
	ll res = 1;
	while(n > 0){
		if(n& 1) res = res * x % MODULO;
		x = x * x % MODULO;
		n >>= 1;
	}
	return res;
}

int main(){
	ll n;
	cin >> n;
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}

	ll p = get_pow(n - 1);

	ll ans = p * (2 * p + 1) % MODULO;
	cout << ans << endl;

	return 0;
}