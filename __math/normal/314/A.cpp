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

ll a[ten(5) * 2 + 10];

int main() { 
	int n; ll k; cin>>n>>k;
	FOR(i,n) cin>>a[i+1];

	ll b = 0;
	ll cnt = 1;
	ll sm = n;

	for(int i = 1; i <= n; i++){
		ll c = -(cnt-1) * (sm-cnt) * a[i];
		c += b;
		if(c < k){
			printf("%d\n",i);
			sm--;
		} else {
			b += a[i] * (cnt-1);
			cnt++;
		}
	}

	return 0;
}