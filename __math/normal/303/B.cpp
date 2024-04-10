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

ll n,m,x,y,a,b;

int main(){
	cin>>n>>m>>x>>y>>a>>b;

	ll g = gcd(a,b);
	a /= g,b /= g;

	ll s = min(n/a,m/b);
	a *= s;
	b *= s;

	ll c_max = n - a;
	ll d_max = m - b;

	ll e_min = a; ll e_max = c_max * 2 + a;
	ll f_min = b; ll f_max = d_max * 2 + b;

	//if(e_min % 2 == 1) e_min++;
	//if(e_max % 2 == 1) e_max--;
	//if(f_min % 2 == 1) f_min++;
	//if(f_max % 2 == 1) f_max--;

	x *= 2;
	y *= 2;

	ll ox,oy;

	if(x < e_min) ox = e_min;
	else if(x > e_max) ox = e_max;
	else ox = x;

	if(y < f_min) oy = f_min;
	else if(y > f_max) oy = f_max;
	else oy = y;

	ll ans_x = (ox - a) / 2;
	ll ans_y = (oy - b) / 2;

	cout << ans_x << " " << ans_y << " " <<  ans_x + a << " " << ans_y + b  << endl;

	return 0;
}