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


ll n,m;

int main()
{
	ll ans = 0;

	cin>>n>>m;
	FOR(i,n){
		ll t,T,x,c; cin>>t>>T>>x>>c;
		ll min_set = T - t;

		if(min_set > 0){
			ll cost;
			ll num = (m-1) / min_set + 1;
			if(num * c <= m * x + c)
				cost = num * c;
			else 
				cost = m * x + c;
			ans += cost;
		} else {
			ans += c + x * m;
		}
	}


	cout << ans << endl;

	return 0;
}