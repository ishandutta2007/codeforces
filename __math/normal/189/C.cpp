#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <stdlib.h>
#include <stdio.h>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)

using namespace std;

static const double EPS = 1e-10;
const int MODULO = 1000000007;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

//BEGIN!!!
typedef pair<double,int> P;

int gcd(int x,int y){
	int r;
    while((r = x % y) != 0)
    {
        x = y;
        y = r;
    }
    return y;
}

const int MAX_N = 2*100000;

int n;
	static int s[MAX_N+1],t[MAX_N+1];
int s_m[MAX_N+1*2],t_m[MAX_N+1];


int solve(){
	FOR(j,n){
		s_m[j] = t_m[s[j]];
	}
	copy(s_m,s_m+n,s_m+n);
	int ans = 0;
	int i = 0;
	while(i < n){
		int cnt = 1;
		int last = s_m[i];
		int start_i = i;
		while(s_m[i+1] > last){
			i++;
			cnt++;
			last = s_m[i];
		}
		cnt -= start_i;
		ans = max(ans,cnt);
		i++;
	}

	return n-ans;
}

int main(){
	cin>>n;
	FOR(i,n) {
		cin>>s[i];
	}
	FOR(i,n) {
		cin>>t[i];
		t_m[t[i]] = i+1;
	}

	int ans = solve();
	cout << ans << endl;
	return 0;
}