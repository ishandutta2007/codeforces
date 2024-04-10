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
int k,b,n,t;

int main()
{
	cin>>k>>b>>n>>t;
	if(k == 1){
		int ans = n + (1 - t) / b;
		cout << max(0,ans) << endl;
		return 0;
	}
	
	double a = (double)b / (k - 1);
	double lg = (a + 1)/(a + t);
	int ans = n + (int)(log(lg) / log(k) - 1e-8);

	cout << max(0,ans) << endl;

	return 0;
}