#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

template<typename T>
int binSearch(int lo, int hi, T f){
	while(lo+1 < hi){
		int mi = (lo+hi)/2;
		if(f(mi)) hi = mi;
		else lo = mi;
	}
	return hi;
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vi as(n);
	trav(x, as) cin >> x;
	sort(all(as));
	reverse(all(as));

	int par = 0;
	trav(x, as) par += x % 2;
	par %= 2;

	auto check = [&](int x, bool tooBig){
		vi bs;
		int ix = 0;
		while(ix < n && x < as[ix]) ++ix;
		rep(i,0,ix) bs.push_back(as[i]);
		bs.push_back(x);
		rep(i,ix,n) bs.push_back(as[i]);
		int m = sz(bs);

		vector<ll> difs(m), ks(m);

		rep(i,0,m){
			if(bs[i] == 0) break;
			difs[i] -= bs[i];
			++ks[0];
			--ks[min(bs[i]-1, i)];
			if(bs[i]-1 < i){
				difs[bs[i]-1] += bs[i];
				difs[i] -= bs[i];
			}
		}
		ll sum = 0, num = 0;
		rep(k,1,m+1){
			sum += difs[k-1];	
			num += ks[k-1];
			if(sum + ll(k)*(k-1 + num) < 0 && 
				(tooBig ? k > ix : k <= ix)){
				return true;
			}
		}
		return false;
	};

	vi cands;
	for(int x = par; x <= n; x += 2) cands.push_back(x);

	int to = 
	 binSearch(-1, sz(cands), [&](int i){return check(cands[i],true);});
	int fr = 
	 binSearch(-1, sz(cands), [&](int i){return !check(cands[i],false);});
	if(to <= fr) cout << -1 << endl;
	else {
		rep(i,fr,to) cout << cands[i] << ' ';
		cout << endl;
	}
}