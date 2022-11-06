#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

const ll md = 998244353;

struct Seg {
	ll l, r, m;
	Seg(ll _l, ll _r, ll _m) : l(_l%md), r(_r%md), m(_m%md) {}
};

Seg mul(Seg l, Seg r){
	return Seg(
		l.l*r.l,
		l.r*r.r,
		l.l*r.m + l.m*r.r - l.l*r.r
	);
};

struct Node {
	int fr, to, mi;
	Node *l = 0, *r = 0;
	Seg p = Seg(1,1,1);
	Node(int _fr, int _to, vl &pls, vl &prs){
		fr = _fr;
		to = _to;
		if(fr+1 < to){
			mi = (fr+to)/2;
			l = new Node(fr, mi, pls, prs);
			r = new Node(mi, to, pls, prs);
			p = mul(l->p, r->p);
		} else {
			p = Seg(pls[fr], prs[fr], 1);
		}
	}
	Seg que(int lo, int hi){
		if(lo >= to || hi <= fr){
			return Seg(1,1,1);
		} else if(lo <= fr && to <= hi){
			return p;
		} else {
			return mul(l->que(lo, hi), r->que(lo,hi));
		}
	}
	ll quem(int lo, int hi){
		return que(lo,hi).m;
	}
	void upd(int i, int dir){
		if(fr+1 < to){
			(i < mi ? l : r)->upd(i,dir);
			p = mul(l->p, r->p);
		} else {
			p = dir==1 ? Seg(0,1,1) : Seg(1,0,1);
		}
	}
};

struct UF {
	vi t, fr, to;
	UF(int n){
		t.resize(n, -1);
		fr.resize(n);
		to.resize(n);
		iota(all(fr), 0);
		iota(all(to), 1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	int uni(int a, int b){
		if(a > b) swap(a,b);
		fr[b] = fr[a];
		to[a] = to[b];
		if(t[b] < t[a]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
		return b;
	}
};

ll inv(ll a){
	ll e = md-2, res = 1;
	do {
		if(e & 1) res = res * a % md;
		a = a * a % md;
	} while( e >>= 1);
	return res;
}

struct Counter {
	int zeroes = 0;
	ll prod = 1;
	Counter(){}
	ll eval(){
		return zeroes ? 0 : prod;
	}
	void add(ll x){
		x %= md;
	//cerr << "adding " << x << endl;
		if(x) prod = prod * x % md;
		else ++zeroes;
	}
	void rem(ll x){
		x %= md;
	//cerr << "removing " << x << endl;
		if(x){
			prod = prod * inv(x) % md;
		}
		else --zeroes;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	ll hun = inv(100);

	int n;
	cin >> n;

	vi x(n), v(n), p(n);
	rep(i,0,n) cin >> x[i] >> v[i] >> p[i];

	vl pl(n), pr(n);
	rep(i,0,n){
		pr[i] = p[i] * hun % md;
		pl[i] = 1 - pr[i];
	}
	Node root(0, n, pl, pr);
	UF uf(n);

	vector<pii> cols;
	rep(i,1,n){
		cols.emplace_back(i-1, -1);
		if(v[i] != v[i-1])
			cols.emplace_back(i-1, 1);
	}
	sort(all(cols), [&](pii a, pii b){
		int d1 = x[a.first+1] - x[a.first];
		int v1 = a.second==-1 ? v[a.first+1] + v[a.first] :
			abs(v[a.first+1] - v[a.first]);
		int d2 = x[b.first+1] - x[b.first];
		int v2 = b.second==-1 ? v[b.first+1] + v[b.first] :
			abs(v[b.first+1] - v[b.first]);
		return ll(d1)*v2 < ll(d2)*v1;
	});

	ll ans = 0;
	Counter prob;
	trav(a, cols){
		int i = a.first;
		//cerr << i << " " << a.second << endl;
		ll dur = (x[i+1]-x[i]) * inv(a.second==1 ? abs(v[i+1]-v[i]) : v[i+1]+v[i]) % md;
		ll prevprob = prob.eval();
		if(a.second == -1){
			int ii = uf.find(i), jj = uf.find(i+1);
			prob.rem(root.quem(uf.fr[ii],uf.to[ii]));
			prob.rem(root.quem(uf.fr[jj],uf.to[jj]));
			ii = uf.uni(ii,jj);
			prob.add(root.quem(uf.fr[ii],uf.to[ii]));
		} else {
			int ii = uf.find(i);
			prob.rem(root.quem(uf.fr[ii],uf.to[ii]));
			if(v[i] > v[i+1]){
				prob.add(pl[i]);
				pl[i] = 1;
				pr[i] = 0;
				root.upd(i, -1);
			} else {
				prob.add(pr[i+1]);
				pl[i+1] = 0;
				pr[i+1] = 1;
				root.upd(i+1, 1);	
			}
			prob.add(root.quem(uf.fr[ii],uf.to[ii]));
		}
		ans = (ans + dur * (prevprob - prob.eval())) % md;
		//cerr << "ways: " << (md + prob.eval() * 16 % md)%md << " (" << prob.eval() << ")" << endl;
		//cerr << endl;
	}
	if(ans < 0) ans += md;
	cout << ans << endl;
	_Exit(0);
}