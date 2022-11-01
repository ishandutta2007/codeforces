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
const int MOD = 1000000000;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[2 * ten(5)];

int main() { 
	int n,m; cin>>n>>m;
	FOR(i,n) cin>>a[i];
	FOR(i,m){
		int t; cin>>t;
		if(t == 1){
			int x,v; cin>>x>>v;
			a[x-1] = v;
		} else if(t == 2){
			int l,r; cin>>l>>r;
			ll f0 = 0,f1 = 1;
			ll ans = 0;
			for(int i = l-1; i < r; i++){
				ans = (ans + f1 * a[i]) % MOD;
				ll tmp = f1;
				f1 = (f0 + f1) % MOD;
				f0 = tmp;
			}

			cout << ans << endl;

		} else {
			assert(false);
		}
	}

	return 0;
}