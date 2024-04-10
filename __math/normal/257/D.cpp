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

int n;
ll a[100000];
bool add[100000];


int main()
{
	cin>>n;
	FOR(i,n) cin>>a[i];

	ll cur = a[n-1];
	add[n-1] = true;
	for(int i = n-2; i >= 0; i--){

		if(cur >= 0) add[i] = false;
		else add[i] = true;

		if(add[i]) cur += a[i];
		else cur -= a[i];
	}

	if(cur < 0) FOR(i,n) add[i] = !add[i];

	FOR(i,n){
		printf("%c",add[i] ? '+' : '-');
	}
	puts("");

	return 0;
}