#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int n;
ll m[111111];
ll x[111111];

ll f(ll n) {
	--n;
	ll res = 0;
	for (ll x = 1; x <= n; x *= 2) {
		ll m;
		if (n & x)
			m = n;
		else {
			m = n & ~(x - 1);
			--m;
		}
		m = m & (x - 1) | (m >> 1 & ~(x - 1));
		if ((m & 1) == 0) res |= x;
	}
	return res;
}

ll g(ll n) {
	ll res = 0;
	for (ll i = 0; i < n; ++i) res ^= i;
	return res;
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	#endif
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> m[i];
		res ^= f(x[i]) ^ f(x[i] + m[i]);
	}
	puts(res ? "tolik" : "bolik");
	return 0;
}