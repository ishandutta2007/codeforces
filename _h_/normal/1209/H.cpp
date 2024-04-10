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

typedef long double ld;

typedef complex<ld> P;

ld cross(P a, P b){
	return ( b * conj(a) ).imag();
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	vi x(n), y(n);
	vector<ld> s(n);
	rep(i,0,n) cin >> x[i] >> y[i] >> s[i];
	x.push_back(l);

	vector<P> maxi, opt;
	auto add_seg = [&](ld len, ld s){
		if(len == 0) return;
		P walk( len/(s+2), -len/(s+2) );
		P rest;
		if(s > 0){
			rest = P(len/s, len/s);
		} else {
			rest = P(len, 0);
		}
		maxi.push_back(walk);
		opt.push_back(walk - rest);
	};
	ld prev = 0;
	rep(i,0,n+1){
		add_seg(x[i]-prev, 0);
		if(i < n){
			add_seg(y[i]-x[i], s[i]);
			prev = y[i];
		}
	}
	int m = sz(maxi);
	vi perm(m);
	iota(all(perm),0);
	sort(all(perm), [&](int i, int j){
		return cross(opt[i], opt[j]) > 0;
	});
	vi idx(m);
	rep(i,0,m) idx[perm[i]] = i;

	priority_queue<pair<int,ld>> segs;
	P cur = 0;
	rep(i,0,m){
		cur += maxi[i];
		segs.push( {idx[i], 1} );
		while(cur.imag() < 0){
			auto pa = segs.top(); segs.pop();
			int j = perm[pa.first];
			ld f = pa.second;
			ld sub = cur.imag() / opt[j].imag();
			if(sub > f){
				cur -= opt[j] * f;
			} else {
				cur -= opt[j] * sub;
				cur = P(cur.real(), 0);
				segs.push( {idx[j], f-sub} );
			}
		}
	}

	cout.precision(11);
	cout << cur.real() << endl;
}