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
const int mx = 3010;

int t[mx];

void upd(int p){
	for(++p; p < mx; p += p & -p) ++t[p];
}

int que(int p){
	int res = 0;
	for(; p > 0; p -= p & -p) res += t[p];
	return res;
}

char zey[mx][mx];
int le[mx][mx], ri[mx][mx]; 

int solve(vi &a, vi &b){
	int sz = a.size();
	if(sz == 0) return 0;
	int res = 0;
	fill(t,t+sz+5,0);
	vector<pii> bb(sz);
	rep(i,0,sz)
		bb[i] = pii(i-b[i]+1, i);
	sort(allof(bb));
	int ix = 0;
	rep(i,0,sz){
		while(ix < sz && bb[ix].first <= i)
			upd(bb[ix++].second);
		res += que(min(sz, i+a[i])) - i;
	}
	return res;
}

int main(){
	memset(t,0,sizeof(t));
	int n,m;
	cin >> n >> m;
	rep(i,0,n) scanf(" %s ", zey[i]);
	rep(i,0,n){
		le[i][0] = zey[i][0] == 'z';
		ri[i][m-1] = zey[i][m-1] == 'z';
	}
	rep(i,0,n) rep(j,1,m)
		le[i][j] = zey[i][j]=='z' ? 1 + le[i][j-1] : 0;
	rep(i,0,n) rrep(j,0,m-1)
		ri[i][j] = zey[i][j]=='z' ? 1 + ri[i][j+1] : 0;
	ll ans = 0;
	rep(s,0,m+n-1){
		vi a,b;
		rep(d, max(0, s-m+1), min(n, s+1)){
			if(zey[d][s-d] == 'z'){
				a.pb(le[d][s-d]);
				b.pb(ri[d][s-d]);
			} else {
				ans += solve(a,b);
				a.clear();
				b.clear();
			}
		}
		ans += solve(a,b);
	}
	cout << ans << endl;
}