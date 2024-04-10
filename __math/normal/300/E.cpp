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

ll powers[ten(7)+10];
bool prime[ten(7) + 1];

//f
void init_prime()
{
	memset(prime,1,sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i < sizeof(prime); i++) if(prime[i])
		for(int j = i * i; j < sizeof(prime); j += i) prime[j] = false;
}

ll get_val(int cur,ll cnt){
	ll l = -1,r = 1LL << 60;
	while(r - l != 1){
		ll md = (l+r)/2;
		ll p = md;
		ll x = 0;
		while(p){
			p /= cur;
			x += p;
		}
		if(x >= cnt) r = md;
		else l = md;
	}
	return r;
}

int main(){
	int k;
	cin >> k;
	FOR(i,k){
		int x; cin>>x;
		powers[x]++;
	}
	for(int i = ten(7)+1; i >= 1; i--) powers[i] += powers[i+1];
	
	ll ans = 1;

	init_prime();
	FOR(i,ten(7)+1){
		if(prime[i]){
			ll cnt = 0;
			ll start = i;
			while(start <= ten(7)){
				for(int j = (int)start; j <= ten(7); j += (int)start){
					cnt += powers[j];
				}
				start *= i;
			}
			ll tmp = get_val(i,cnt);
			ans = max(ans,tmp);
		}
	}

	cout << ans << endl;

	return 0;
}