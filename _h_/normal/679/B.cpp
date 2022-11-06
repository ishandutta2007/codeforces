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
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

ll cb(ll a){
	return a*a*a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll m;
	cin >> m;
	vector<ll> v(100), b(100);
	v[0] = 0;
	int j = -1;
	rep(i,1,100){
		ll l = 0, r = 1e8;
		while(l+1 < r){
			ll mi = (l+r)/2;
			if(3*mi*mi + 3*mi + 1 > v[i-1])
				r = mi;
			else
				l = mi;
		}
		b[i] = r;
		v[i] = v[i-1] + cb(r);
		if(v[i] > m){
			j = i-1;
			break;
		}
	}
	rrep(i,1,j+1){
		while(1){
			ll d = cb(b[i]+1)-cb(b[i]);
			if(v[j]+d > m)
				break;
			bool go = 1;
			rep(k,i+1,j+1)
				if(v[k]+d >= cb(b[k]+1))
					go = 0;
			if(!go) break;
			rep(k,i,j+1)
				v[k] += d;
			++b[i];
		}
	}
	cout << j << ' ' << v[j] << endl;
}