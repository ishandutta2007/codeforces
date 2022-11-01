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
#define sz(c) ((int)(c).size())

int a[100000],b[100000];

int d[100000];

int main(){
	int n,m;
	cin>>n; FOR(i,n) cin>>a[i];
	cin>>m; FOR(i,m) cin>>b[i];

	FOR(i,n){
		d[a[i]-1] = i+1;
	}
	ll l = 0,r = 0;
	FOR(i,m){
		l += d[b[i]-1];
		r += n - d[b[i]-1] + 1;
	}

	cout << l << " " << r << endl;

	return 0;
}