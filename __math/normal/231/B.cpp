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

int main(){
	int n,d,l; cin>>n>>d>>l;
	vector<int> ans(n,1);
	if(n&1) d--;
	if(d > 0){
		for(int i = 0; i < n; i+= 2){
			int add = min(d,l-1);
			d -= add;
			ans[i] += add;
			if(d == 0) break;
		}
	} else if(d < 0){
		d *= -1;
		for(int i = 1; i < n; i+= 2){
			int add = min(d,l-1);
			d -= add;
			ans[i] += add;
			if(d == 0) break;
		}
	}

	if(d == 0){
		FOR(i,n){
			cout << ans[i];
			if(i != n-1) cout << " ";
			else cout << endl;
		}
	}
	else {
		puts("-1");
	}

	return 0;
}