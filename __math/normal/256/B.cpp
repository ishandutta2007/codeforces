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

ll n,x,y,c;

ll sq(ll x){
	if(x < 0) return 0;
	return x * x;
}

ll sq_2(ll x){
	if(x < 0) return 0;
	return x * (x+1) / 2;
}

ll C(ll t){
	ll lx = max(0LL,x-t);
	ll rx = min(n,x+t+1);
	ll ly = max(0LL,y-t);
	ll ry = min(n,y+t+1);
	
	ll lx_m = max(0LL,t-x);
	ll rx_m = max(0LL,x+t-n+1);
	ll ly_m = max(0LL,t-y);
	ll ry_m = max(0LL,y+t-n+1);

	ll ans = (rx - lx) * (ry - ly);

	ll mns = 0;
	mns += sq_2(t - lx_m-ly_m);
	mns += sq_2(t - lx_m-ry_m);
	mns += sq_2(t - rx_m-ly_m);
	mns += sq_2(t - rx_m-ry_m);

	ans -= mns;
	return ans;
}

int main(){

	cin>>n>>x>>y>>c;
	x--; y--;

	ll l = -1,r = 2*n-1;
	while(r-l!= 1){
		ll md = (l+r)/2;
		if(C(md) < c)
			l = md;
		else 
			r = md;
	}

	cout << r << endl;

    return 0;
}