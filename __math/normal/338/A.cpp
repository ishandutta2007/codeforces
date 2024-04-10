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

int main(){
	ll n,m,k; cin>>n>>m>>k;
	ll a = min((n-m)*k,n);
	ll b = n-a;

	ll block = b/k;

	ll x = ((mod_pow<ll>(2,block+1,MOD) - 2) % MOD + MOD) % MOD;
	x = x*k % MOD;

	x = x + (b - block * k);
	x += a-(n-m);
	x %= MOD;

	cout << x << endl;
}