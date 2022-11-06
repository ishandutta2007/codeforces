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
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	vector<vi> hopp(40, vi(n)), wsum(40, vi(n)), minw(40, vi(n));
	trav(x, hopp[0]) cin >> x;
	trav(x, wsum[0]) cin >> x;
	rep(i,0,n) minw[0][i] = wsum[0][i];
	rep(i,1,40)
		rep(j,0,n)
			hopp[i][j] = hopp[i-1][hopp[i-1][j]];
	rep(i,1,40)
		rep(j,0,n)
			wsum[i][j] = wsum[i-1][j] + wsum[i-1][hopp[i-1][j]];
	rep(i,1,40)
		rep(j,0,n)
			minw[i][j] = min(minw[i-1][j], minw[i-1][hopp[i-1][j]]);
	auto sum = [&](int v, ll l){
		ll res = 0;
		int i = 0;
		while(l){
			if(l&1){
				res += wsum[i][v];
				v = hopp[i][v];
			}
			l /= 2;
			i++;
		}
		return res;
	};
	auto mn = [&](int v, ll l){
		ll res = 1e9;
		int i = 0;
		while(l){
			if(l&1){
				res = min(res, minw[i][v]);
				v = hopp[i][v];
			}
			l /= 2;
			i++;
		}
		return res;
	};
	rep(i,0,n) cout << sum(i, k) << ' ' << mn(i, k) << endl;
}