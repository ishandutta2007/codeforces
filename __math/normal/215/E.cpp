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


vector<int> mobius(int size){
	vector<int> ret(size);
	vector<int>flag(size);
	ret[1] = 1;
	for(int i= 2; i < size; i++){
		int u = 1 - flag[i];
		ret[i] = -u;
		for(int j = i; j < size; j += i) flag[j] += u;
	}
	return ret;
}

ll solve(ll c){

	vector<int> mo = mobius(64);
	FOR(i,64) mo[i] *= -1;
	mo[1] = 0;

	ll ans = 0;

	for(int i = 2;(1LL << (i - 1)) <= c; i++){
		for(int j = 1; j< i; j++) if(i % j == 0){
			ll div = ((1LL << i) - 1) / ((1LL << j) - 1);
			ll hi = min((1LL << j) - 1,c/div);
			ll lo = ((1LL << (i - 1)) - 1) / div;
			ans += (hi - lo) * mo[i / j];
		}
	}
	return ans;
}

int main()
{
	
	
	ll r,l;
	cin>>l>>r;

	ll ans = solve(r) - solve(l-1);

	cout << ans << endl;

	return 0;
}