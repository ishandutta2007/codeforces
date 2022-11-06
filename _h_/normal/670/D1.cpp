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
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n;
	ll k;
	cin >> n >> k;
	vl as(n), bs(n);
	for(ll &a : as) cin >> a;
	for(ll &a : bs) cin >> a;
	map<ll, pll> frco;
	rep(i,0,n){
		ll b = bs[i], a = as[i];
		ll nn = b/a;
		if(!frco.count(nn)) frco[nn] = pll(0,0);
		frco[nn].first += b % a;
		frco[nn].second += a;
	}
	frco[1LL<<40] = pll(0,0);
	ll fr = k, co = 0, cur = 0;
	for(auto it : frco){
		pll p = it.second;
		ll nx = it.first;
		if((nx-cur)*co > fr){
			cout << cur + fr/co << endl;
			return 0;
		}
		fr -= (nx-cur)*co;
		fr += p.first;
		co += p.second;
		cur = nx;
	}
}