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

ll n,k;
ll a[100000];

int main(){
	cin>>n>>k;
	FOR(i,n) cin>>a[i];
	sort(a,a+n);

	int l=0;
	Pll ans(1,a[0]);
	ll add = 0;
	for(int r = 1; r < n; r++){
		add += (a[r] - a[r-1]) * (r-l);
		while(add > k)
			add -= a[r] - a[l++];
		if(ans.first < r-l+1){
			ans = Pll(r-l+1,a[r]);
		}
	}

	cout << ans.first << " " << ans.second << endl;

	return 0;
}