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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int t[1000],c[1000];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>t[i]>>c[i];

	int last_time = 0;
	int max_queue = 0;
	int cur_time = 0;
	int cur_queue = 0;
	FOR(i,n){
		cur_queue = max(0,cur_queue + (cur_time - t[i])) + c[i];
		cur_time = t[i];

		max_queue = max(cur_queue,max_queue);
	}

	last_time = cur_time + cur_queue;

	cout << last_time << " " << max_queue << endl;


	return 0;
}