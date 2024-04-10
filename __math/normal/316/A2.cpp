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
const int MOD = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(n) ((int)1e##n)

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main() { 
	string s;
	cin>>s;

	bool en[10] = {};
	FOR(i,sz(s)) if('A' <= s[i] && s[i] <= 'J') en[s[i] - 'A'] = true;
	int q_cnt = 0;
	FOR(i,sz(s)) if(s[i] == '?') q_cnt++;

	ll ans = 1;
	int c = 10;
	FOR(i,10) if(en[i]){
		ans *= c;
		c--;
	}

	if(q_cnt){
		ans *= 10;
		q_cnt--;
	}
	if(('A' <= s[0] && s[0] <= 'J') || s[0] == '?') ans = ans / 10 * 9;

	printf("%I64d",ans);
	FOR(i,q_cnt) putchar('0');
	puts("");

	return 0;
}