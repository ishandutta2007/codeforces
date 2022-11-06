#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)v.size()
#define x real()
#define y imag()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> P;

pll pa(P a){
	return pll(a.x, a.y);
}

bool lt(P a, P b){
	return pa(a) < pa(b);
}

bool cmp(P a, P b){
	ll d = (a*conj(b)).y;
	if(d < 0) return true;
	if(d > 0) return false;
	if(d == 0) return lt(a, b);
	return false;
}

bool smile(P l, P r){
	return (l*conj(r)).y > 0LL;
}

ll gcd(ll a, ll b){
	a = abs(a), b = abs(b);
	while(b > 0){
		a %= b;
		swap(a,b);
	}
	return a;
}

void chull(vector<P> inp, vector<ll> &res, ll &rek){
	int i = 0;
	int n = sz(inp);
	rep(j,1,n) if(lt(inp[j], inp[i])) i = j;
	swap(inp[0], inp[i]);
	rrep(i,0,n) inp[i] -= inp[0];
	sort(inp.begin()+1, inp.end(), cmp);
	inp.push_back(inp[0]);

	vector<P> hu;
	inp.push_back(inp[0]);
	rep(i,0,n+1){
		while(sz(hu) >= 2){
			int s = sz(hu);
			P l = hu[s-2];
			P r = inp[i];
			l -= hu.back(), r -= hu.back();
			if(!smile(l, r) && (i<n || sz(hu)>2)) hu.pop_back();
			else break;
		}
		hu.push_back(inp[i]);
	}
//	trav(p, hu) cerr << p.x << ' ' << p.y << endl;
//	cerr << endl;
	int m = sz(hu)-1;	
	vector<P> d(m);
	rep(i,0,m) d[i] = hu[i+1]-hu[i];

//	trav(p, d) cerr << p.x << ' ' << p.y << endl;
//	cerr << endl;

	rek = 0;
	trav(p, d) rek = max(rek, (p*conj(p)).x);

	d.push_back(d[0]);

	res.resize(m);
	rep(i,0,m){
		P c = d[i]*conj(d[i+1]);
		ll denom = (d[i+1]*conj(d[i+1])).x;

		ll gc = gcd(denom, c.x);
		gc = gcd(gc, c.y);

		denom /= gc;
		c = P(c.x/gc, c.y/gc);

//		cerr << denom << ' '  << c.x << ' ' << c.y << endl;
		res[i] = denom*12341431LL ^ c.x *91823821LL ^ c.y;
	}

//	cerr << endl;
}

void fail(){
	puts("NO");
	exit(0);
}

const ll md = 1e9+7;
const ll bs = 123912LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n[2];
	rep(i,0,2) cin >> n[i];

	vector<ll> res[2];
	ll rek[2];
	rep(i,0,2){
		vector<P> inp(n[i]);
		trav(p, inp){
			int z, w;
			cin >> z >> w;
			p = P(z,w);
		}
		chull(inp, res[i], rek[i]);
	}
	if(sz(res[0]) != sz(res[1]) || rek[0] != rek[1]) fail();
	rep(t,0,2) trav(z, res[t]) z %= md;

	int l = sz(res[0]);

	vector<vector<ll>> pre(2, vector<ll>(l+1, 0));
	rep(t,0,2) rep(i,0,l) pre[t][i+1] = (pre[t][i]*bs + res[t][i]) % md;

	vector<ll> pws(l+1, 1);
	rep(i,0,l) pws[i+1] = pws[i]*bs % md;

	rep(i,0,l){
		ll f1 = pre[1][l];
		ll f0 = pre[0][i]*(1-pws[l]) + pws[i]*pre[0][l];
		f1 %= md, f0 %= md;
		if(f1 < 0) f1 += md;
		if(f0 < 0) f0 += md;
		if(f0 == f1){
			puts("YES");
			return 0;
		}
	}
	fail();

}