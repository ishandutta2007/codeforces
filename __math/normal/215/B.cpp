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
#include <ctime>

using namespace std;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!

#define FOR(i,n) for(int i = 0 ;i < (n); i++)

int n,m,k;
double x[10000],y[10000],z[10000];
double a,b;

int main()
{
	cin>>n;
	FOR(i,n) cin>>x[i];
	cin>>m;
	FOR(i,m) cin>>y[i];
	cin>>k;
	FOR(i,k) cin>>z[i];
	cin>>a>>b;

	double r1 = *max_element(x,x+n);
	double p1 = *max_element(y,y+m);
	double p2 = *min_element(z,z+k);
	double ans = r1 * sqrt(b * p1 / (b * p1 + a * p2));

	printf("%.15lf\n",ans);

	return 0;
}