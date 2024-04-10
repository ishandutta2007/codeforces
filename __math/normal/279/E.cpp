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
	int n= sz(s);
	vector<Pii> press;
	int cnt0 = 0,cnt1 = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '1'){
			if(cnt0 != 0) press.push_back(Pii(0,cnt0));
			cnt0 = 0;
			cnt1++;
		} else {
			if(cnt1 != 0) press.push_back(Pii(1,cnt1));
			cnt0++;
			cnt1 = 0;
		}
	}
	if(cnt0 != 0) press.push_back(Pii(0,cnt0));
	if(cnt1 != 0) press.push_back(Pii(1,cnt1));

	int ans = 0;
	int m = sz(press);
	FOR(i,m){
		if(press[i].first == 0) continue;
		// first = 1
		if(press[i].second == 1){
			ans++;
		} else {
			ans += 2;
			while(i < m-1 && press[i+1].second == 1){
				i++;
				ans++;
				if(i < m-1) i++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}