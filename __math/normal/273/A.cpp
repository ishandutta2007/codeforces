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

int a[100000];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>a[i];

	ll cur_h = a[0];
	ll cur_w = 0;
	int m; cin>>m;
	FOR(i,m){
		ll h,w; scanf("%I64d%I64d",&w,&h);
		w--;
		if(cur_w < w){
			cur_h = a[w];
		}
		printf("%I64d\n",cur_h);

		if(cur_w < w){
			cur_w = w;
		}
		cur_h += h;
		while(cur_w < n + 1 && cur_h >= a[cur_w + 1]) cur_w++;
	}

	return 0;
}