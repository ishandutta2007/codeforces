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

double SQ(double x){return x*x;}

int main()
{
	double x[2],y[2],r[4];
	cin>>x[0]>>y[0]>>r[0]>>r[1]>>x[1]>>y[1]>>r[2]>>r[3];
	double ls = sqrt(SQ(x[0]-x[1])+SQ(y[0]-y[1]));

	int ans = 0;
	if(ls >= r[0]+r[3] || ls + r[0] <= r[2] || ls + r[3] <= r[0]) ans++;
	if(ls >= r[1]+r[3] || ls + r[1] <= r[2] || ls + r[3] <= r[1]) ans++;
	if(ls >= r[2]+r[1] || ls + r[2] <= r[0] || ls + r[1] <= r[2]) ans++;
	if(ls >= r[3]+r[1] || ls + r[3] <= r[0] || ls + r[1] <= r[3]) ans++;

	cout << ans << endl;
}