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
const unsigned int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main(){
	string s; cin>>s;

	vector<int> left,right;

	FOR(i,sz(s)){
		if(s[i] == 'l'){
			right.push_back(i+1);
		} else {
			left.push_back(i+1);
		}
	}

	vector<int> ans;
	FOR(i,sz(left)) ans.push_back(left[i]);
	FOR(i,sz(right)) ans.push_back(right[sz(right) - 1 - i]);

	FOR(i,sz(ans)){
		cout << ans[i] << endl;
	}

	return 0;
}