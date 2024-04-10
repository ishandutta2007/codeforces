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

int popcount(ll x){
	x = (x & 0x5555555555555555ULL) + ((x & 0xAAAAAAAAAAAAAAAAULL) >> 1);
	x = (x & 0x3333333333333333ULL) + ((x & 0xCCCCCCCCCCCCCCCCULL) >> 2);
	x = (x & 0x0F0F0F0F0F0F0F0FULL) + ((x & 0xF0F0F0F0F0F0F0F0ULL) >> 4);
	return (int)(x * 0x0101010101010101ULL >> 56);
}

int main(){
	int n; cin>>n;
	map<ll,int> mp;
	FOR(i,n){
		ll x; cin>>x;
		mp[x]++;
	}

	ll ans = 0;

	ll e = 0;
	ll upper = 0;
	for(map<ll,int>::iterator it = mp.begin(); it != mp.end(); it++){
		ll diff = (it->first - e);
		ll nxt_upper = (diff < 32) ? (upper >> diff) : 0;

		int pv = popcount(upper);
		int nt = popcount(nxt_upper);

		ans += diff - (pv - nt); //0

		upper = nxt_upper + it->second;
		e = it->first;
	}

	while(upper){
		if(upper % 2 == 0) ans++;
		upper /= 2;
	}

	cout << ans << endl;

	return 0;
}