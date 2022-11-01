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
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }

int w[ten(5)];
int sw[ten(5) + 10];

int main(){
	int n,l,r;
	ll ql,qr;
	cin>>n>>l>>r>>ql>>qr;
	FOR(i,n) cin>>w[i];

	FOR(i,n) sw[i+1] += sw[i] + w[i];

	ll mx = tenll(11);
	FOR(a,n+1){
		int b = n - a;
		ll add = 0;
		if(b > a) add = (b-a-1) * qr;
		else if(a > b) add = (a-b-1) * ql;

		ll left_sum = sw[a];
		left_sum *= l;
		ll right_sum = sw[n] - sw[a];
		right_sum *= r;

		ll cur_ans = left_sum + right_sum + add;
		mx = min(mx,cur_ans);
	}

	cout << mx << endl;

	return 0;
}