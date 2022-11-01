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

ll a[100000];

int main(){
	ll n,k; cin>>n>>k;
	FOR(i,n) cin>>a[i];

	if(k == 1){
		cout << n << endl;
		return 0;
	}

	set<ll> s;
	FOR(i,n) s.insert(a[i]);

	int ans = 0;

	for(set<ll>::iterator it = s.begin(); it != s.end(); ++it){
		int cnt = 1;
		for(ll nxt = *it * k; nxt < ((int)1e9 + 1); nxt *= k){
			set<ll>::iterator it2 = s.find(nxt);
			if(it2 != s.end()){
				s.erase(it2);
				cnt++;
			} else {
				break;
			}
		}

		ans += (cnt + 1) / 2;
	}

	cout << ans << endl;

	return 0;
}