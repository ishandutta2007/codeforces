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
//const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }



int main(){
	int n;
	cin>>n;
	int a[10] = {};
	bool ok = true;
	FOR(i,n){
		int x; cin>>x;
		a[x-1]++;
		if(x == 5 || x == 7){
			ok = false;
		}
	}
	if(!ok){
		puts("-1");
		return 0;
	}

	vector<int> v(3);
	if(a[3] <= a[1] && a[3] <= a[0]){
		v[0] = a[3];
		a[1] -= a[3];
		a[0] -= a[3];
	} else {
		ok = false;
	}

	if(a[0] == a[1] + a[2] && a[0] == a[5]){
		v[1] = a[2];
		v[2] = a[1];
	} else {
		ok = false;
	}

	if(!ok){
		puts("-1");
	} else {
		FOR(i,v[0]) puts("1 2 4");
		FOR(i,v[1]) puts("1 3 6");
		FOR(i,v[2]) puts("1 2 6");

	}

		return 0;
}