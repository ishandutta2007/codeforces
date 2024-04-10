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


int mod_pow(int x,int p,int md){
	ll ret = 1;
	ll ml = x;
	while(p){
		if(p&1){
			ret = ret * ml % md;
		}
		ml = ml * ml % md;
		p/=2;
	}

	return (int)ret;
}

int main(){
	int n,m; cin>>n>>m;

	int ans = mod_pow(3,n,m) - 1;
	ans = (ans + m) % m;

	cout << ans << endl;

	return 0;
}