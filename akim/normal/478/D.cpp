#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

vector<int> dp0(200100), dp1(200100);

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll R, G;
	scanf("%I64d%I64d", &R, &G);
	ll s = R + G;
	ll c;
	for(c = 1; s >= c; c++) {
		s -= c;
	}
	c--;
	s = 0;
	dp0[0] = 1;
	for(int i = 0; i < c; i++, s += i) {
		for(int f = 0; f < 200100; f++) {dp1[f] = 0;}
		for(int f = 0; f <= R; f++) {
			//cout << dp0[f] << " ";
			ll g = G - (s - f);
			if(g - i - 1 >= 0) dp1[f] = (dp1[f] + dp0[f]) % mod;
			if(f + i + 1 <= R) dp1[f + i + 1] = (dp1[f + i + 1] + dp0[f]) % mod;
		}
		//cout << "\n";
		dp0.swap(dp1);
	}
	ll o = 0;
	for(int i = 0; i <= R; i++) {
		o = (o + dp0[i]) % mod;
	}
	printf("%I64d", o);

	return(0);
}

// by Kim Andrey