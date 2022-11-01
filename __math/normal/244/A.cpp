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
	int n,k; cin>>n>>k;
	int a[1000]; FOR(i,k) cin>>a[i];

	bool use[1000] = {};
	FOR(i,k) use[a[i]] = true;
	FOR(i,k){
		printf("%d%c",a[i],0==n-1?'\n':' ');
		int cnt = 1;
		FOR(j,n-1){
			while(use[cnt]) cnt++;
			use[cnt] = true;
			printf("%d%c",cnt,j==n-2?'\n':' ');
		}
	}
	

	return 0;
}