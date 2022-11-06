#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

ll inv(ll a, ll b){
	return a-1 ? b - b*inv(b%a, a)/a : 1;
}

bool f(ll x, ll y, ll n){
	ll d = __gcd(x,y);
	if(n%d != 0) return 0;
	n /= d, x /= d, y /= d;
	ll a = n*inv(x,y)%y;
	return n >= a*x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll x = 1234567, y = 123456, z = 1234;
	ll n;
	cin >> n;
	for(; n >= 0; n -= x){
		if(f(z,y,n)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}