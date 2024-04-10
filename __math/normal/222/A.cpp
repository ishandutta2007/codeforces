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

int a[100000];

int main(){

	int n,k; cin>>n>>k;
	FOR(i,n) cin>>a[i];

	bool ok = true;
	int s = a[k-1];

	for(int i = k; i < n; i++){
		if(a[i] != s) ok = false;
	}

	if(!ok){
		puts("-1");
		return 0;
	}

	int ans = k-1;
	for(;ans >= 0; ans--){
		if(a[ans] != s) break;
	}

	cout << ans + 1 << endl;



	return 0;
}