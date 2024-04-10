#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

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

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#ifdef ONLINE_JUDGE
#define typeof(X) __typeof(X)
#else
#define typeof(X) decltype(X)
#endif
#define FOREACH(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define sz(c) ((int)(c).size())

int main(){
	int n; cin>>n;
	int a[100]; FOR(i,n) cin>>a[i];

	if(n == 1 || n % 2 == 0){
		puts("-1");
		return 0;
	}

	int ans = 0;
	int max_x = (n-1) / 2;
	for(int x = max_x; x > 0; x--){
		int xa = 2*x-1;
		int xb = xa+1;
		int x_minus = max(a[xa],a[xb]);
		a[xa] = 0;
		a[xb] = 0;
		a[x-1] = max(0,a[x-1] - x_minus);
		ans += x_minus;
	}
	ans += a[0];
	cout << ans << endl;

    return 0;
}