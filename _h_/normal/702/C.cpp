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
	
	int n,m;
	cin >> n >> m;
	vector<ll> cities(n);
	set<ll> towers;
	trav(x, cities) cin >> x;
	rep(_,0,m){
		ll x;
		cin >> x;
		towers.insert(x);
	}
	towers.insert(-(1LL<<40));
	towers.insert(1LL<<40);
	ll ans = 0;
	trav(c, cities){
		auto it = towers.lower_bound(c);
		ll cur = *it - c;
		--it;
		cur = min(cur, c - *it);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}