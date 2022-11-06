#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const ll inf = 1LL<<60;
const ll md = 1e9+7;

ll inv(ll a, ll b){
	return a>1 ? b - inv(b%a,a)*b/a : 1;
}

ll xp(ll a, ll e){
	ll res = 1;
	while(e){
		if(e&1) res = res*a%md;
		a = a*a%md;
		e /= 2;
	}
	return res;
}

int main(){
	int n,k;
	cin >> n >> k;
	vl sum(k+2);
	rep(i,1,k+2) sum[i] = (xp(i,k) + sum[i-1])%md;
	if(n <= k+1){
		cout << sum[n] << endl;
		return 0;
	}
	ll ans = 0;
	vl fak(k+10);
	fak[0] = 1;
	rep(i,1,k+10) fak[i] = i*fak[i-1]%md;
	rep(i,0,k+2)
		ans += sum[i]*inv((n-i)*fak[i]%md * fak[k+1-i] % md * ((k+1-i)%2==0?1:-1) + md,md)%md;
	ans %= md;
	rep(i,0,k+2) ans = ans*(n-i)%md;
	cout << ans << endl;
}