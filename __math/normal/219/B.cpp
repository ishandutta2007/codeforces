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


int main()
{
	ll p,d; cin>>p>>d;

	ll diff = 0;
	ll rank = 1;
	while(diff <= d){
		if(rank * 10 > p) break;
		ll a = 9 - (p % (rank * 10)) / rank;
		a = -(a-10);
		if(a == 10) a = 0;
		a *= rank;
		if(diff + a > d)
			break;
		p -= a;
		diff += a;
		rank *= 10;
	}

	cout << p << endl;

	return 0;
}