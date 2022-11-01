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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int a[101],b[101];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i= 0; i <= n; i++) cin>>a[i];
	for(int i= 0; i <= m; i++) cin>>b[i];
	if(b[0] < 0){
		a[0] *= -1;
		b[0] *= -1;
	}
	if(n == m){
		int g = gcd(abs(a[0]),abs(b[0]));
		printf("%d/%d\n",a[0] / g, b[0] / g);
	} else if(n > m){
		if(a[0] < 0){
			puts("-Infinity");
		} else {
			puts("Infinity");
		}
	} else {
		puts("0/1");
	}

	return 0;
}