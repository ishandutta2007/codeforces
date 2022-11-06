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
const ll inf = 1LL<<60;
const ll md = 1e9+7;
const ld eps = 1e-14;

void fail(){
	puts("unfair");
	exit(0);
}

int main(){
	int n,b,q;
	cin >> n >> b >> q;
	vector<pii> hi(q+2);
	rep(i,0,q) cin >> hi[i].first >> hi[i].second;
	hi[q] = pii(b, n);
	hi[q+1] = pii(0,0);
	sort(allof(hi));
	vi mi(q+1), tt(q+1), cc(5);
	vector<vi> c(q+1, vi(5));
	rep(i,0,q+1){
		int l = hi[i].first+1, r = hi[i+1].first+1;
		tt[i] = r-l;
		mi[i] = r-l - (hi[i+1].second - hi[i].second);
		if(mi[i] < 0) fail();
		rep(x,l,r) ++c[i][x%5];
		rep(x,0,5) cc[x] += c[i][x];
	}
	rep(mk,0,32){
		int di = 0;
		rep(x,0,5) if(mk&(1<<x)){
			di += n/5;
			di -= cc[x];
		}
		rep(i,0,q+1){
			int d = mi[i] - tt[i];
			rep(x,0,5) if(mk&(1<<x))
				d += c[i][x];
			if(d > 0) di += d;
		}
		if(di > 0) fail();
	}
	puts("fair");
}