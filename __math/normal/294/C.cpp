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


// ax+by=gcd(a,b)x,y(|x| <= b , |y| <= a)
template<class T> T extgcd(T a,T b,T& x,T& y){
	if(b == 0){
		x = 1; y = 0;
		return a;
	} else {
		T g = extgcd(b,a % b,y,x);
		y -= (a / b) * x;
		return g;
	}
}

// aygcd(a,m)(mod m) ---> return y;
template<class T> T md_inverse(T a){
	T x,y;
	ll m = MOD;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

template<class T> ll mod_pow(T a,T n, T mod){
	ll ret = 1;
	ll p = a % mod;
	while(n){
		if(n&1) ret = ret * p % mod;
		p = p * p % mod;
		n>>=1;
	}
	return ret;
}


ll frac[2000];
ll f_inv[2000];

void init(){
	frac[0] = 1;
	for(int i = 1; i < 2000; i++){
		frac[i] = frac[i-1] * i % MOD;
	}
	FOR(i,2000){
		f_inv[i] = md_inverse(frac[i]);
	}
}

int main(){
	init();

	int n,m; cin>>n>>m;
	vector<int> a;
	FOR(i,m){
		int x; cin>>x;
		a.push_back(x);
	}

	sort(a.begin(),a.end());

	ll ans = frac[n-m];
	int left = a[0] - 1;
	int right = n - a[sz(a)-1];
	ans = ans * f_inv[left] % MOD * f_inv[right] % MOD;

	FOR(i,sz(a) - 1){
		int x = a[i+1] - a[i] - 1;
		if(x == 0) continue;
		ans = ans * f_inv[x] % MOD;
		ans = ans * mod_pow<ll>(2,x-1,MOD) % MOD;
	}

	cout << ans << endl;

	return 0;
}