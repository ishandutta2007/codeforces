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

int main(){
	int n;
	int a[100];
	cin >> n;
	FOR(i,n) cin>>a[i];
	int ans = 0;
	FOR(i,n) for(int j = i; j < n; j++){
		int tmp = 0;
		FOR(k,n){
			int add = (i <= k && k <= j) ? 1 - a[k] : a[k];
			tmp += add;
		}
		ans = max(ans,tmp);
	}

	cout << ans << endl;
	
	return 0;
}