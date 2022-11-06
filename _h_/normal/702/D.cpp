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
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll d,k,a,b,t;
	cin >> d >> k >> a >> b >> t;
	ll ans = d*b;
	ll j = d/k;
	ans = min(ans, j*(a*k + t) + (d%k)*a);
	if(j >= 1)
		ans = min(ans, (j)*(a*k + t)-t + (d%k)*b);
	if(d > k) ans = min(ans, k*a + b*(d-k));
	cout << ans << endl;
}