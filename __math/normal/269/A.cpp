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
	int n; cin>>n;
	vector<Pll> v(n);
	FOR(i,n) cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end());

	ll prev_k = -1,prev_a = 1;
	FOR(i,n){
		ll cur_k = v[i].first;
		ll cur_a = v[i].second;
		if(cur_k - prev_k > 20){
			prev_a = 0;
		} else {
			ll dv = 1;
			FOR(x,cur_k - prev_k) dv *= 4;
			prev_a = (prev_a + dv - 1) / dv;
		}
		prev_a = max(prev_a,cur_a);
		prev_k = cur_k;
	}

	prev_a = (prev_a+3)/4;
	prev_k++;

	while(prev_a != 1){
		prev_a = (prev_a+3)/4;
		prev_k++;
	}

	cout << prev_k << endl;

	return 0;
}