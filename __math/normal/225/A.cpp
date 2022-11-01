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

int a[100],b[100];

int main(){

	int n; cin>>n;
	int m; cin>>m;
	FOR(i,n) cin>>a[i]>>b[i];
	FOR(i,n){
		if(a[i] >= 4) a[i] = 7 - a[i];
		if(b[i] >= 4) b[i] = 7 - b[i];
	}

	int c[100];
	FOR(i,n){
		c[i] = a[i] + b[i];
	}

	int d = c[0];
	bool ok = true;
	for(int i = 1; i < n; i++){
		if(c[i] != d) ok = false;
	}

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}