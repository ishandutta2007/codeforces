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

const int mx = 2e5+1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vi fact(mx);
	rep(i,2,mx) if(fact[i] == 0) for(int j = i; j < mx; j += i) fact[j] = i;
	vector<vi> ps(mx);
	rep(i,0,n){
		int a;
		cin >> a;
		vi ds(1,1);
		while(a > 1){
			int sz = ds.size();
			int p = fact[a];
			while(a % p == 0){
				a /= p;
				int beg = ds.size()-sz, slut = ds.size();
				rep(i,beg,slut) ds.pb(ds[i]*p);
			}
		}
		for(int d : ds) ps[d].pb(i);
	}
	ll ans = 0;
	vi v(n);
	rep(i,0,n) v[i] = i;

	auto upd = [&](int p, int r, ll d){
		while(p < n && v[p] < r){
			ans += d * (r - v[p]);
			v[p] = r;
			++p;
		}
	};

	rrep(d,1,mx){
		if(ps[d].size() > 1){
			int sz = ps[d].size();
			upd(0,ps[d][sz-2], d);
			upd(ps[d][1]+1, n, d);
			upd(ps[d][0]+1,ps[d][sz-1],d);
		}
	}
	cout << ans << endl;
}