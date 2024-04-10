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
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef complex<double> Cd;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())


bool prime[1000001]; 

//f
void init_prime()
{
	memset(prime,1,sizeof(prime));
	prime[0] = prime[1] = false;
	for(int i = 2; i * i < sizeof(prime); i++) if(prime[i])
		for(int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
}

ll lsqrt(ll n){
	ll l = 1; ll r= n+1;
	while( r-l != 1){
		ll md = (r+l)/2;
		if (md*md <= n)
			l = md;
		else
			r = md;
	}
	return l;
}

int main(){
	init_prime();
	set<ll> s;
	FOR(i,1000001) if(prime[i]) s.insert((ll)i * (ll)i);
	int n;
	cin>>n;
	while(n--){
		ll x; cin>>x;
		if(s.find(x) != s.end()){
				puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}