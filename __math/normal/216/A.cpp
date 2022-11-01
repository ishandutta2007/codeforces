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
	ll a,b,c;
	cin>>a>>b>>c;
	ll ans = 0;
	ll mn = min(b,c) - 1;
	FOR(i,mn) ans += a++;
	ans *= 2;
	ans += a * ((max(b,c) - min(b,c)) + 1);
	cout << ans << endl;
	return 0;
}