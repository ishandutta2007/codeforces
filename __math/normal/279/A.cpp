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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main(){
	int n,m; cin>>n>>m;
	int cnt = 0;
	int x = 0,y = 0;
	while(x != n || y != m){
		cnt++;
		if(cnt % 4 == 1){
			if(y == m && x <= n && n <= -x+1) break;
			x = -x + 1;
		} else if(cnt % 4 == 2){
			if(x == n && y <= m && m <= x) break;
			y = x;
		} else if(cnt % 4 == 3){
			if(y == m && -x <= n && n <= x) break;
			x = -x;
		} else {
			if(x == n && -y <= m && m <= y) break;
			y = -y;
		}
	}
	cout << max(cnt-1,0) << endl;

	return 0;
}