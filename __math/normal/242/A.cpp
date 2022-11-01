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
	int x,y,a,b; cin>>x>>y>>a>>b;

	vector<Pii> ans;
	int start_f = max(a,b+1);
	for(int i = start_f; i <= x; i++){
		for(int j = b; j <= min(i-1,y); j++){
			ans.push_back(Pii(i,j));
		}
	}

	cout << sz(ans) << endl;
	FOR(i,sz(ans)){
		cout << ans[i].first << " " <<ans[i].second << endl;
	}

	return 0;
}