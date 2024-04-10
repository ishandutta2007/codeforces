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

ll mod_pow(ll x,ll n,ll mod){
	ll ret = 1,p = x;
	while(n){
		if(n&1){
			ret = ret * p % mod;
		}
		p = p * p % mod;
		n /= 2;
	}
	return ret;
}

int fractors[200000+10];

int a[100000];
int b[100000];

int main(){
	int n; cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(i,n) cin>>b[i];
	ll m; cin>>m;

	map<int,map<int,int> > v;
	FOR(i,n){
		v[a[i]][(i+1)]++;
		v[b[i]][(i+1)]++;
	}
	for(map<int,map<int,int> >::iterator it = v.begin(); it != v.end(); ++it){
		int x = 0;
		for(map<int,int>::iterator it2 = it->second.begin();
			it2 != it->second.end(); ++it2){
				fractors[it2->second]--;
				x += it2->second;
		}
		fractors[x]++;
	}

	static int powers[200000+10] = {};
	for(int i = 200000; i >= 0; i--) powers[i] = powers[i+1] + fractors[i];
	
	ll ans = 1;
	static bool prime[200000+10] = {};
	memset(prime,1,sizeof(prime));
	for(int i = 2; i <= 200000; i++) if(prime[i]){
		ll p = 0;
		//int xA x = 5*10^4 x
		for(ll x = i; x <= 200000; x *= i){
			for(ll y = x; y <= 200000; y += x){
				prime[y] = false;
				p += powers[y];
			}
		}
		ans = ans * mod_pow(i,p,m) % m; // i^p
	}

	cout << ans << endl;

	return 0;
}