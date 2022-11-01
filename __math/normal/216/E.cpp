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


int k,b,n; 
int a[100000];

ll solve(){
	ll countZero = 0;
	for (int i = 0, cnt = 0; i < n; ++i) {
		if (a[i]) {
			cnt = 0;
		}
		else {
			++cnt;
		}
		countZero += cnt;
	}
	if (b == 0)
		return countZero;
	
	map<ll,int> mp;
	ll ans = 0;
	int as = 0;
	mp[0] = 1;
	FOR(i,n){
		as = (as + a[i]) % (k - 1);
		int s = (as - b + (k-1)) % (k - 1);
		ans += mp[s];
		++mp[as];
	}
	if(k - 1 == b) ans -= countZero;

	return ans;

}

int main()
{
	cin>>k>>b>>n;
	FOR(i,n) cin>>a[i];

	cout << solve() << endl;

	return 0;
}