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
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

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

template<class T> T extgcd(T a,T b,T& x,T& y){
  for (T u = y = 1, v = x = 0; a; ) {
    T q = b / a;
    swap(x -= q * u, u);
    swap(y -= q * v, v);
    swap(b -= q * a, a);
  }
  return b;
}

template<class T> T md_inverse(T a,T m){
	T x,y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

int main(){
	string s;
	cin>>s;
	int k; cin>>k;

	int A = sz(s);
	ll B = mod_pow<ll>(2LL,A,MOD);

	ll ans = 0;

	FOR(i,sz(s)) if(s[i] == '0' || s[i] == '5'){
		int X = i;
		ll P = (mod_pow<ll>(B,k,MOD) - 1);
		ll Q = mod_pow<ll>(2,X,MOD);
		ll T = P * md_inverse<ll>(B-1,MOD) % MOD * Q % MOD;
		ans = (ans + T) % MOD;
	}

	cout << ans << endl;

	return 0;
}