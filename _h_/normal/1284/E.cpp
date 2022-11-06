// written by _h_
// on 2020 01/04 at 13:05:01
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
typedef complex<ll> P;

bool operator<(const P &a, const P &b){
	return make_pair(a.real(),a.imag()) < make_pair(b.real(),b.imag());
}

ll cross(P a, P b){
	return (conj(a) * b).imag();
}

ll area(P a, P b, P c){
	return cross(a-b, c-b);
}

bool ang(P a, P b){
	if(a < P(0)) a = -a;
	if(b < P(0)) b = -b;
	return cross(a,b) > 0;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<P> xy(n);
	trav(p, xy){
		int x, y;
		cin >> x >> y;
		p = P(x,y);
	}

	vector<pii> ps;
	rep(i,0,n) rep(j,0,i){
		ps.emplace_back(i,j);
	}
	sort(all(ps), [&](pii a, pii b){
		P d1 = xy[a.first] - xy[a.second];
		P d2 = xy[b.first] - xy[b.second];
		return ang(d1, d2);
	});

	vi perm(n);
	iota(all(perm),0);
	sort(all(perm), [&](int i, int j){
		return xy[i] < xy[j];
	});

	vi idx(n);
	rep(i,0,n) idx[perm[i]] = i;

	ll ans = 0;

	trav(pa, ps){
		int i = pa.first, j = pa.second;
		assert(abs(idx[i] - idx[j]) == 1);
		swap(idx[i], idx[j]);
		ll k = min(idx[i], idx[j]);
		ans += k * (n-2-k);
	}
	ans -= n*ll(n-1)*ll(n-2)*ll(n-3)/12;
	ans *= n-4;
	ans /= 2;
	cout << ans << endl;
	/*
	int cnt = 0;
	rep(i,0,n) rep(j,0,n) rep(k,0,n) rep(l,0,n){
		vi ls = {i,j,k,l,i,j,k};
		rep(t,0,4) if(cross(xy[ls[t+2]]-xy[ls[t+1]], xy[ls[t]]-xy[ls[t+1]])<=0)
			goto nogood;
		++cnt;
		nogood: ;
	}
	int num = n*(n-1)*(n-2)*(n-3)/24 - cnt/4;
	cout << num * (n-4) / 2 << endl;
	*/
}