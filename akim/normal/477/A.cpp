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


const double eps = (1e-9);
const int mod = (int)(1e+9) + 7;
const double pi = acos(-1.0);

ll binpow(ll a, ll b) {
	ll o = 1;
	while(b) {
		if(b & 1) {
			o *= a;
			o %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return(o);
}

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	ll a, b, o = 0, m2 = binpow(2, mod - 2);
	cin >> a >> b;
	for(ll i = 1; i < b; i++) {
		ll s = (((((2 * i + i * (a - 1)) % mod) * m2) % mod) * a) % mod;
		o += (s * b + i * a) % mod;
		o %= mod;
	}
	cout << o;
	return(0);
}

// by Kim Andrey