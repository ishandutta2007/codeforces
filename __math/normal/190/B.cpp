#define _USE_MATH_DEFINES
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


#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

double x_1,y_1,r_1,x_2,y_2,r_2;

double sqr(double x){ return x*x;}

double solve(){
	double len = sqrt( sqr(x_1-x_2) + sqr(y_1-y_2) );
	if(len > r_1 + r_2)
		return len - r_1 - r_2;
	else if(len + r_1 < r_2)
		return r_2 - (len + r_1);
	else if(len + r_2 < r_1)
		return r_1 - (len + r_2);
	else 
		return 0.0;
}

int main(){

	cin>>x_1>>y_1>>r_1;
	cin>>x_2>>y_2>>r_2;

	double ans = solve();
	ans /= 2.0;
	printf("%.15lf\n",ans);

	return 0;
}