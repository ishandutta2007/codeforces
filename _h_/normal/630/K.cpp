#include <iostream>
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
#include <cstdio>
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
typedef long double ld;
const ll inf = 1LL<<60;
const ld eps = 1e-14;

ll choose(ll n, ll k){
	ll res = 1;
	rep(i,0,k) res = res*(n-i)/(i+1);
	return res;
}

int main(){
	ll n;
	cin >> n;
	ll ans = n/(2*3*5*7) * 2*4*6;
	n %= 2*3*5*7;
	rep(i,1,n+1) ans += __gcd(i,2*3*5*7) == 1;
	cout << ans << endl;
}