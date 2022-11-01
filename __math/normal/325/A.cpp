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
#include <fstream>
#include <iterator>

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 1000000000 + 1; //1e9 + 1

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)


int main(){
	int n; cin>>n;

	bool ok = false;
	ll lx = INF,ly = INF,rx = 0,ry = 0;
	ll s = 0;
	FOR(i,n){
		ll a,b,c,d;
		cin>>a>>b>>c>>d;
		lx = min(lx,a);
		ly = min(ly,b);
		rx = max(rx,c);
		ry = max(ry,d);

		ll add = abs(a-c) * abs(b-d);
		s += add;
	}

	if(abs(lx-rx) == abs(ly - ry)){
		if(abs(lx-rx) * abs(lx-rx) == s)
			ok = true;
	}

	puts(ok ? "YES" : "NO");

	return 0;
}