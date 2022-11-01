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
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!


ll solve(ll digit,ll mx){

	ll ans = 0;
	//1
	if(digit <= mx) ans++;

	for(ll l = 10; (l + 1) * digit <= mx; l *= 10){
		ll start = (l + 1) * digit;
		ll add = 0;
		for(ll c = 10; c < l; c *= 10) add = (add * 10) + 9;
		ll end = min(start + add * 10,mx);
		ll sub = end - start;
		ans += sub / 10 + 1;
	}

	return ans;
}

ll l,r;

int main(){
	cin>>l>>r;

	ll ans = 0;
	for (int i = 1; i < 10; i++){
		ans += solve(i,r);
		ans -= solve(i,l - 1);
	}

	cout << ans << endl;

	return 0;
}