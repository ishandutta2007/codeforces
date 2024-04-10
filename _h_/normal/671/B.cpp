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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,k;
	cin >> n >> k;
	vi cs(n);
	rep(i,0,n) cin >> cs[i];
	ll lo = -1, hi = 2e9;
	while(lo+1 < hi){
		ll mi = (lo + hi)/2;
		ll po = 0;
		for(int c : cs){
			po += max(0LL, mi - c);
		}
		if(po > k){
			hi = mi;
		} else {
			lo = mi;
		}
	}
	ll sum = 0;
	for(ll c : cs) sum += c;
	ll avg = sum / n;
	ll maxmin = min(avg, lo);
	lo = -1, hi = 2e9;
	while(lo + 1 < hi){
		ll mi = (lo + hi)/2;
		ll ri = 0;
		for(int c : cs){
			ri += max(0LL, c - mi);
		}
		if(ri > k){
			lo = mi;
		} else {
			hi = mi;
		}
	}
	ll minmax = max(sum % n == 0 ? avg : avg + 1, hi);
	cout << minmax - maxmin << endl;
}