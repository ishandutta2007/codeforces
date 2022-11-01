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


int a[200];

int main(){
	int n; cin>>n;
	int m = 2*n-1;
	FOR(i,m) cin>>a[i];

	sort(a,a+m);

	if(n % 2 == 1){
		FOR(i,m){
			if(a[i] < 0) a[i] *= -1;
		}
	} else {
		int cnt = 0;
		FOR(i,m/2){
			if(a[2*i] < 0 && a[2*i+1] < 0){
				a[2*i] *= -1;
				a[2*i+1] *= -1;
			} else if(a[2*i] < 0){
				int x = a[2*i],y = a[2*i+1];
				if(x + y < 0){
					a[2*i] *= -1;
					a[2*i+1] *= -1;
				}
			}
		}
	}


	cout << accumulate(a,a+m,0) << endl;

	return 0;
}