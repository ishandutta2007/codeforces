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

int a,b,n;

int is_good_sum(int sm){
	while(sm){
		int x = sm % 10;
		if(x != a && x != b) return false;
		sm /= 10;
	}
	return true;
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

// aygcd(a,m)(mod m) ---> return y;
template<class T> T md_inverse(T a,T m){
	T x,y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll fact_t[ ten(6) + 1 ];
//n! % MOD \z
void build_fact_table()
{
	fact_t[0] = 1;
	for(int i = 1; i < sizeof(fact_t) / sizeof(ll); i++){
		fact_t[i] = (fact_t[i - 1] * i) % MOD;
	}
}

// nCk % MOD(build_fact_table)
template<class T> T combi(T n,T k){
	if(n < 0 || k < 0 || n < k) return 0;
	T a1 = fact_t[n],a2 = fact_t[k], a3 = fact_t[n-k];
	return (a1 * md_inverse<ll>(a2 * a3 % MOD, MOD)) % MOD;
}

int main(){
	build_fact_table();

	cin>>a>>b>>n;
	if(a > b) swap(a,b);

	ll ans = 0;
	FOR(i,n + 1){
		int sm = a * i + b * (n-i);
		if(is_good_sum(sm)){
			int l = n,r = i;
			if(a == 0) l--;
			ans = (ans + combi<ll>(l,r)) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}