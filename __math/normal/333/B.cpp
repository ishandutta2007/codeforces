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

int main(){
	int n,m; cin>>n>>m;
	set<int> v,h;
	FOR(i,m){
		int x,y; cin>>x>>y;
		v.insert(x),h.insert(y);
	}

	int ans = 0;
	for(int i = 1; i < (n+1)/2; i++){
		int a = i+1,b = b = n-a+1;
		if(a != b){
			if(v.find(a) == v.end()) ans++;
			if(v.find(b) == v.end()) ans++;
			if(h.find(a) == h.end()) ans++;
			if(h.find(b) == h.end()) ans++;
		} else {
			if(v.find(a) == v.end() || h.find(a) == h.end()) ans++;
		}
	}

	cout << ans << endl;
}